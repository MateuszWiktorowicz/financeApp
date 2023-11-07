#include "AccountManager.h"

Operation AccountManager::addIncome()
{
    Operation operation;
    //Data
    cout << "Z JAKA DATA DODAC PRZYCHOD" << endl;
    cout << "1. DZISIEJSZA" << endl;
    cout << "2. WYBIERZ DATE" << endl;

    char choice = InputMethods::readSign();

    switch(choice)
    {
       case '1' : operation.setDate(ConvertMethods::getCurrentDate()); break;

      case '2' :  operation.setDate(ConvertMethods::getChosenDate()); break;
    }




    //Kind of income

    cout << "Wpisz rodzaj przychodu" << endl;
    string kindOfIncome = InputMethods::readLine();
    operation.setItem(kindOfIncome);

    //amount of income

    cout << "Wpisz kwotê przychodu" << endl;
    int sum = InputMethods::readNumber();
    operation.setAmount(sum);

    return operation;

}
