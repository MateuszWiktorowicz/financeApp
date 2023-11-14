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
    const int ID_LOGGED_IN_USER;
    vector <Operation> operations;
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;

    vector <int> getLastMonthVector();
    vector <int> setFirsDayMonth(vector <int> vecToSetUp);
    vector <int> setLastDayMonth(vector <int> vecToSetUp);
    Operation addAccountOperation(int operationId);
    bool isDateRangeCorrect(vector<Operation>::iterator itr, vector <int> date1, vector <int> date2);
    void showBalanceAccountFromPeriod(vector <int> date1, vector <int> date2);
    double coutOperationsInDataRangeAndCountTotal(vector <int> date1, vector <int> date2, int operationId);
public:
    AccountManager(int idLoggedInUser, string nameOfFileWithIncomes, string nameOfFileWithExpenses)
    : ID_LOGGED_IN_USER(idLoggedInUser), fileWithIncomes(nameOfFileWithIncomes), fileWithExpenses(nameOfFileWithExpenses)
    {
        operations = fileWithIncomes.loadOperationsFromFile(ID_LOGGED_IN_USER);
        vector <Operation> temp = fileWithExpenses.loadOperationsFromFile(ID_LOGGED_IN_USER);
        operations.insert(operations.end(), temp.begin(), temp.end());
    };
    void addIncome();
    void addExpense();
    void showBalanceCurrentMonth();
    void showBalanceLastMonth();
    void showBalanceFrom();



};
