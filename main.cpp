#include <iostream>


#include "AccountManager.h"
using namespace std;


int main()
{
AccountManager accountManager(1, "incomes.xml", "expenses.xml");


accountManager.showBalanceLastMonth();



    return 0;
}
