#include <iostream>


#include "AccountManager.h"
using namespace std;


int main()
{
AccountManager accountManager(1, "incomes.xml", "expenses.xml");

accountManager.addExpense();



    return 0;
}
