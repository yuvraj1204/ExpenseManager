#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <ctime>
#include "Category.h"
#include "json.hpp" // Include the JSON library
using namespace std;

using json = nlohmann::json;

class Transaction
{
private:
    string description;
    double amount;
    time_t date;
    Category category;
    bool isIncome;

public:
    Transaction(const string &desc, double amt, time_t dt, const Category &cat, bool isInc);
    void display() const;
    double getAmount() const;
    string getDescription() const;
    time_t getDate() const;
    string getCategory() const;
    bool isIncomeType() const;
    json toJson() const;                        // Convert to JSON
    static Transaction fromJson(const json &j); // Create from JSON
};

#endif // TRANSACTION_H
