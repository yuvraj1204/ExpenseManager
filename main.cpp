#include <iostream>
#include <ctime>
#include "FinanceManager.h"
using namespace std;

int main()
{
    FinanceManager fm;

    // Load data from file
    fm.loadFromFile("data.json");

    // Add some initial categories if they don't already exist
    fm.addCategory(Category("Salary"));
    fm.addCategory(Category("Food"));
    fm.addCategory(Category("Rent"));
    fm.addCategory(Category("Entertainment"));
    fm.addCategory(Category("Travel"));

    // Add a user
    cout << "Enter user name: ";
    string userName;
    cin >> userName;
    User *user = fm.getUser(userName);
    if (!user)
    {
        User newUser(userName);
        fm.addUser(newUser);
        user = fm.getUser(userName);
    }

    int choice;
    do
    {
        cout << "\nFinance Manager Menu\n";
        cout << "1. Add Transaction\n";
        cout << "2. Display Transactions\n";
        cout << "3. Calculate Total Income\n";
        cout << "4. Calculate Total Expenses\n";
        cout << "5. Total Balance\n";
        cout << "6. Save and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string desc;
            double amount;
            string category;
            bool isIncome;

            cout << "Enter description: ";
            cin.ignore();
            getline(std::cin, desc);

            cout << "Enter amount: ";
            cin >> amount;

            cout << "Enter category: ";
            cin >> category;

            cout << "Is this an income? (1 for Yes, 0 for No): ";
            cin >> isIncome;

            Category *cat = fm.getCategory(category);
            if (cat)
            {
                time_t now = time(0);
                user->addTransaction(std::make_shared<Transaction>(desc, amount, now, *cat, isIncome));
            }
            else
            {
                cout << "Category not found!\n";
            }
            break;
        }
        case 2:
            user->displayTransactions();
            break;
        case 3:
            cout << "Total Income: " << user->calculateTotalIncome() << endl;
            break;
        case 4:
            cout << "Total Expenses: " << user->calculateTotalExpenses() << endl;
            break;
        case 5:
            cout << "Balance: " << user->calculateTotalIncome() - user->calculateTotalExpenses() << endl;
            break;
        case 6:
            cout << "Saving and exiting...\n";
            fm.saveToFile("data.json");
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
