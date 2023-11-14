#include "FinanceApp.h"

void FinanceApp::registerUser()
{
    userManager.registerUser();
}

void FinanceApp::loginUser()
{
    userManager.loginUser();

    if (userManager.isUserLoggedIn())
    {
        accountManager = new AccountManager(userManager.getLoggedInUserId(), NAME_OF_FILE_WITH_INCOMES, NAME_OF_FILE_WITH_EXPENSES);
    }

}

void FinanceApp::changePassword()
{
    userManager.changePassword();
}

void FinanceApp::addIncome()
{
    if (userManager.isUserLoggedIn())
    {
        accountManager -> addIncome();
    }
}

void FinanceApp::addExpense()
{
    if (userManager.isUserLoggedIn())
    {
        accountManager -> addExpense();
    }
}

void FinanceApp::showBalanceCurrentMonth()
{
    if (userManager.isUserLoggedIn())
    {
        accountManager -> showBalanceCurrentMonth();
    }
}

void FinanceApp::showBalanceLastMonth()
{
    if (userManager.isUserLoggedIn())
    {
        accountManager -> showBalanceLastMonth();
    }
}

bool FinanceApp::isUserLoggedIn()
{
    return userManager.isUserLoggedIn();
}

void FinanceApp::logout()
{
    userManager.logout();
    delete accountManager;
    accountManager = NULL;
}

char FinanceApp::choiceOptionFromMainMenu()
{
    return menuManager.choiceOptionFromMainMenu();
}
char FinanceApp::choiceOptionFromUserMenu()
{
    return menuManager.choiceOptionFromUserMenu();
}
