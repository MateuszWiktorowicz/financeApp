#include <iostream>
#include "FinanceApp.h"

using namespace std;

int main()
{
    FinanceApp financeApp("users.xml", "incomes.xml", "expenses.xml");
    char menuOption;

    while (true)
    {
        if (!financeApp.isUserLoggedIn())
        {
            menuOption = financeApp.choiceOptionFromMainMenu();

            switch (menuOption)
            {
            case '1':
                financeApp.registerUser();;
                break;
            case '2':
                financeApp.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
         menuOption = financeApp.choiceOptionFromUserMenu();

            switch (menuOption)
            {
            case '1':
                financeApp.addIncome();
                break;
            case '2':
                financeApp.addExpense();
                break;
            case '3':
                financeApp.showBalanceCurrentMonth();
                break;
            case '4':
                financeApp.showBalanceLastMonth();
                break;
            case '5':
                financeApp.showBalanceFrom();
                break;
            case '7':
                financeApp.changePassword();
                break;
            case '8':
                financeApp.logout();
            break;
            }
        }
    }
    return 0;
}
