#include <iostream>

#include "UserManager.h"
#include "AccountManager.h"
#include "MenuManager.h"

using namespace std;

class FinanceApp
{
    UserManager userManager;
    MenuManager menuManager;
    AccountManager *accountManager;
    const string NAME_OF_FILE_WITH_INCOMES;
    const string NAME_OF_FILE_WITH_EXPENSES;
public:
    FinanceApp(string nameOfFileWithUsers, string nameOfFileWithIncomes, string nameOfFileWithExpenses)
        :  userManager(nameOfFileWithUsers), NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes),
           NAME_OF_FILE_WITH_EXPENSES(nameOfFileWithExpenses)
    {
        accountManager = NULL;
    };

    ~FinanceApp()
    {
        delete accountManager;
        accountManager = NULL;
    };

    void registerUser();
    void loginUser();
    bool isUserLoggedIn();
    void logout();
    void changePassword();
    void addIncome();
    void addExpense();
    void showBalanceCurrentMonth();
    void showBalanceLastMonth();
    void showBalanceFrom();
    char choiceOptionFromMainMenu();
    char choiceOptionFromUserMenu();

} ;
