#include <iostream>
#include <vector>

#include "InputMethods.h"
#include "ConvertMethods.h"
#include "Operation.h"

using namespace std;

class AccountManager
{

    int loggedInUserId;
    vector <Operation> operations;

public:
    void addIncome();

};
