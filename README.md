Finance Manager Overview:

Finance Manager is a C++ console application designed for personal finance management. It allows users to manage transactions by adding income and expenses, categorizing them, and calculating total income, expenses, and available balance. The application utilizes the nlohmann/json library for saving and loading data from a JSON file.

Features:

Add transactions with descriptions, amounts, categories, and types (income or expense).
View all transactions.
Calculate total income, expenses, and available balance.
Save and load user data using JSON file storage.

Installation:

Clone the Repository:

git clone https://github.com/yourusername/finance-manager.git

cd Finance-Manager-

Download nlohmann/json:

Download json.hpp from nlohmann/json and place it in your project directory.

Compile the Project:

g++ -o FinanceManager main.cpp FinanceManager.cpp User.cpp Transaction.cpp Category.cpp -std=c++20

Run the executable:

./FinanceManager
