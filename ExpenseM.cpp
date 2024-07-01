#include "FinanceManager.h"
#include <fstream>
using namespace std;

void FinanceManager::addUser(const User &user)
{
    users.push_back(user);
}

void FinanceManager::addCategory(const Category &category)
{
    categories.push_back(category);
}

User *FinanceManager::getUser(const string &name)
{
    for (auto &user : users)
    {
        if (user.getName() == name)
        {
            return &user;
        }
    }
    return nullptr;
}

Category *FinanceManager::getCategory(const string &name)
{
    for (auto &category : categories)
    {
        if (category.getName() == name)
        {
            return &category;
        }
    }
    return nullptr;
}

void FinanceManager::saveToFile(const string &filename) const
{
    json j;
    for (const auto &user : users)
    {
        j["users"].push_back(user.toJson());
    }
    ofstream file(filename);
    file << j.dump(4);
}

void FinanceManager::loadFromFile(const string &filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
        json j;
        file >> j;
        for (const auto &item : j["users"])
        {
            users.push_back(User::fromJson(item));
        }
    }
}
