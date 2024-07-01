
#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <vector>
#include "User.h"
#include "Category.h"
#include "json.hpp" // Include the JSON library
using namespace std;

using json = nlohmann::json;

class FinanceManager {
private:
    vector<User> users;
    vector<Category> categories;

public:
    void addUser(const User& user);
    void addCategory(const Category& category);
    User* getUser(const string& name);
    Category* getCategory(const string& name);
    void saveToFile(const string& filename) const; // Save to JSON file
    void loadFromFile(const string& filename); // Load from JSON file
};

#endif // FINANCEMANAGER_H
