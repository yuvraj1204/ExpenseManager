#include "User.h"
#include <iostream>
using namespace std;

User::User(const std::string &name) : name(name) {}

void User::addTransaction(shared_ptr<Transaction> transaction)
{
    transactions.push_back(transaction);
}

void User::displayTransactions() const
{
    for (const auto &transaction : transactions)
    {
        transaction->display();
    }
}

double User::calculateTotalIncome() const
{
    double total = 0;
    for (const auto &transaction : transactions)
    {
        if (transaction->isIncomeType())
        {
            total += transaction->getAmount();
        }
    }
    return total;
}

double User::calculateTotalExpenses() const
{
    double total = 0;
    for (const auto &transaction : transactions)
    {
        if (!transaction->isIncomeType())
        {
            total += transaction->getAmount();
        }
    }
    return total;
}

string User::getName() const
{
    return name;
}

json User::toJson() const
{
    json j;
    j["name"] = name;
    for (const auto &transaction : transactions)
    {
        j["transactions"].push_back(transaction->toJson());
    }
    return j;
}

User User::fromJson(const json &j)
{
    User user(j.at("name").get<string>());
    for (const auto &item : j.at("transactions"))
    {
        user.addTransaction(std::make_shared<Transaction>(Transaction::fromJson(item)));
    }
    return user;
}
