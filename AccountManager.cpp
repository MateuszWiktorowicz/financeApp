#include "AccountManager.h"

void AccountManager::addIncome()
{
    Operation operation;

    cout << "Z JAKA DATA DODAC PRZYCHOD" << endl;
    cout << "1. DZISIEJSZA" << endl;
    cout << "2. WYBIERZ DATE" << endl;

    char choice = InputMethods::readSign();

    switch(choice)
    {
    case '1' :
        operation.setDate(ConvertMethods::getCurrentDate());
        break;

    case '2' :
        operation.setDate(ConvertMethods::getChosenDate());
        break;
    }
    operation.setOperationId(1);
    operation.setUserId(ID_LOGGED_IN_USER);

    cout << "Wpisz rodzaj przychodu" << endl;
    string kindOfIncome = InputMethods::readLine();
    operation.setItem(kindOfIncome);

    cout << "Wpisz kwote przychodu" << endl;
    operation.setAmount(InputMethods::readDouble());

    operations.push_back(operation);
    fileWithIncomes.appendOperationToXmlFile(operation);
}

void AccountManager::addExpense()
{
    Operation operation;

    cout << "Z JAKA DATA DODAC WYDATEK" << endl;
    cout << "1. DZISIEJSZA" << endl;
    cout << "2. WYBIERZ DATE" << endl;

    char choice = InputMethods::readSign();

    switch(choice)
    {
    case '1' :
        operation.setDate(ConvertMethods::getCurrentDate());
        break;

    case '2' :
        operation.setDate(ConvertMethods::getChosenDate());
        break;
    }

    operation.setOperationId(2);
    operation.setUserId(ID_LOGGED_IN_USER);

    cout << "Wpisz rodzaj wydatku" << endl;
    string kindOfIncome = InputMethods::readLine();
    operation.setItem(kindOfIncome);

    cout << "Wpisz kwote wydatku" << endl;
    operation.setAmount(InputMethods::readDouble());

    operations.push_back(operation);
    fileWithExpenses.appendOperationToXmlFile(operation);
}
/*
bool AccountManager::compareDateOfOperationAscending(Operation &operation1, Operation &operation2)
{
   return (operation1.getDate() < operation2.getDate());
}
*/
void AccountManager::showBalanceAccountFromPeriod(vector <int> date1, vector <int> date2)
{
    double incomes = 0;
    double expenses = 0;
    double total = 0;
    sort(operations.begin(), operations.end(), [] (const Operation& op1, const Operation& op2)
         {
             return op1.getDate() > op2.getDate();
         });


    cout << "PRZYCHODY" << endl;
    for (vector <Operation>::iterator itr = operations.begin(); itr < operations.end(); itr++)
    {
        if ((itr -> getOperationId()  == 1) && ((itr -> getDate() >= date1) && (itr -> getDate() <= date2)))
        {
            cout << itr -> getAmount() << endl;
            cout << ConvertMethods::convertVectorDateIntoStringFormat(itr -> getDate()) << endl;
            cout << itr -> getItem() << endl;
            incomes += itr -> getAmount();

        }
    }

    for (vector <Operation>::iterator itr = operations.begin(); itr < operations.end(); itr++)
    {
        if ((itr -> getOperationId()  == 2) && ((itr -> getDate() >= date1) && (itr -> getDate() <= date2)))
        {
            cout << itr -> getAmount() << endl;
            cout << ConvertMethods::convertVectorDateIntoStringFormat(itr -> getDate()) << endl;
            cout << itr -> getItem() << endl;
            expenses += itr -> getAmount();

        }
    }
    total = incomes - expenses;
    cout << "PRZYCHODY: " << incomes << endl;
    cout << "WYDATKI: " << expenses << endl;
    cout << "SALDO: " << total << endl;

}
