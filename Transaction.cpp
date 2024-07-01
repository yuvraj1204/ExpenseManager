#include "Transaction.h"
#include <iostream>
using namespace std;

Transaction::Transaction(const string &desc, double amt, time_t dt, const Category &cat, bool isInc)
    : description(desc), amount(amt), date(dt), category(cat), isIncome(isInc) {}

void Transaction::display() const
{
    cout << "Description: " << description
         << ", Amount: " << amount
         << ", Date: " << ctime(&date)
         << ", Category: " << category.getName()
         << ", Type: " << (isIncome ? "Income" : "Expense")
         << std::endl;
}

double Transaction::getAmount() const
{
    return amount;
}

string Transaction::getDescription() const
{
    return description;
}

time_t Transaction::getDate() const
{
    return date;
}

string Transaction::getCategory() const
{
    return category.getName();
}

bool Transaction::isIncomeType() const
{
    return isIncome;
}

json Transaction::toJson() const
{
    return json{
        {"description", description},
        {"amount", amount},
        {"date", date},
        {"category", category.getName()},
        {"isIncome", isIncome}};
}

Transaction Transaction::fromJson(const json &j)
{
    return Transaction(
        j.at("description").get<string>(),
        j.at("amount").get<double>(),
        j.at("date").get<time_t>(),
        Category(j.at("category").get<string>()),
        j.at("isIncome").get<bool>());
}
