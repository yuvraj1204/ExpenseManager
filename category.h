#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
using namespace std;

class Category
{
private:
    string name;

public:
    Category(const string &name);
    string getName() const;
    void setName(const string &name);
};

#endif // CATEGORY_H
