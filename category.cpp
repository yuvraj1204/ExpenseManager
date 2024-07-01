#include "Category.h"
using namespace std;

Category::Category(const string &name) : name(name) {}

string Category::getName() const
{
    return name;
}

void Category::setName(const string &name)
{
    this->name = name;
}
