#include <iostream>
#include <vector>
#include <algorithm>

#include "InputMethods.h"
#include "ConvertMethods.h"
#include "ValidationMethods.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "Operation.h"

using namespace std;

class AccountManager
{
    int ID_LOGGED_IN_USER;
    vector <Operation> operations;
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;

    vector <int> setFirsDayCurrentMonth();
    vector <int> setLastDayCurrentMonth();
    bool isDateRangeCorrect(vector<Operation>::iterator itr, vector <int> date1, vector <int> date2);
public:
    AccountManager(int idLoggedInUser, string nameOfFileIncomes, string nameOfFileExpenses)
    : ID_LOGGED_IN_USER(idLoggedInUser), fileWithIncomes(nameOfFileIncomes), fileWithExpenses(nameOfFileExpenses)
    {
        operations = fileWithIncomes.loadIncomesFromFile();
        vector <Operation> temp = fileWithExpenses.loadExpensesFromFile();
        operations.insert(operations.end(), temp.begin(), temp.end());
    };
    void showBalanceAccountFromPeriod(vector <int> date1, vector <int> date2);
    void addIncome();
    void addExpense();
    void showBalanceCurrentMonth();
    void showBalanceLastMonth();


};
