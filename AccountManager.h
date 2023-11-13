#include <iostream>
#include <vector>

#include "InputMethods.h"
#include "ConvertMethods.h"
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
    bool compareDateOfOperationAscending(Operation &operation1, Operation &operation2);

public:
    AccountManager(int idLoggedInUser, string nameOfFileIncomes, string nameOfFileExpenses)
    : ID_LOGGED_IN_USER(idLoggedInUser), fileWithIncomes(nameOfFileIncomes), fileWithExpenses(nameOfFileExpenses)
    {
    };

    void addIncome();
    void addExpense();


};
