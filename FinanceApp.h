#include <iostream>

#include <UserManager.h>
#include <AccountManager.h>

using namespace std;

class FinanceApp
{
    UserManager userManager;
    AccountManager accountManager;
    const string NAME_OF_FILE_WITH_INCOMES;
    const string NAME_OF_FILE_WITH_EXPENSES;
public:
    FinanceApp(string nameOfFileWithUsers, string nameOfFileWithIncomes, string nameOfFileWithExpenses)
    :  userManager(nameOfFileWithUsers), NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes),
     NAME_OF_FILE_WITH_EXPENSES(nameOfFileWithExpenses) {};
} ;
