#include <iostream>
#include <vector>

#include "InputMethods.h"
#include "ConvertMethods.h"
#include "FileWithIncomes.h"
#include "Operation.h"

using namespace std;

class AccountManager
{
    int ID_LOGGED_IN_USER;
    vector <Operation> operations;
    FileWithIncomes fileWithIncomes;

public:
    AccountManager(string nameOfFileIncomes, int idLoggedInUser)
    : ID_LOGGED_IN_USER(idLoggedInUser), fileWithIncomes(nameOfFileIncomes)
    {
    };
    void addIncome();

};
