#include <iostream>


#include "AccountManager.h"
using namespace std;


int main()
{
AccountManager accountManager(1, "incomes.xml", "expenses.xml");
vector <int> date1 = {2,0,0,4,1,1,1,1};
vector <int> date2 = {2,0,0,5,1,1,1,1};
accountManager.addIncome();
accountManager.addIncome();
accountManager.addIncome();
accountManager.addExpense();

accountManager.showBalanceAccountFromPeriod(date1, date2);



    return 0;
}
