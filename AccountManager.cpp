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

    cout << "Wpisz rodzaj przychodu" << endl;
    string kindOfIncome = InputMethods::readLine();
    operation.setItem(kindOfIncome);

    cout << "Wpisz kwote przychodu" << endl;
    int sum = InputMethods::readNumber();
    operation.setAmount(sum);

    operations.push_back(operation);
}
