#ifndef USER_H
#define USER_H

#include <vector>
#include <memory>
#include "Transaction.h"
#include "json.hpp" // Include the JSON library
using namespace std;

using json = nlohmann::json;

class User {
private:
    string name;
    vector<std::shared_ptr<Transaction>> transactions;

public:
    User(const string& name);
    void addTransaction(std::shared_ptr<Transaction> transaction);
    void displayTransactions() const;
    double calculateTotalIncome() const;
    double calculateTotalExpenses() const;
    string getName() const;
    json toJson() const; // Convert to JSON
    static User fromJson(const json& j); // Create from JSON
};

#endif // USER_H
