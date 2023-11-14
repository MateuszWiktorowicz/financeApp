#include "AccountManager.h"

void AccountManager::addIncome()
{
    Operation operation;
    system("cls");
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

    cout << "PRZYCHOD DODANY" << endl;
    system("pause");
}

void AccountManager::addExpense()
{
    system("cls");
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
    cout << "WYDATEK DODANY" << endl;
    system("pause");
}

void AccountManager::showBalanceAccountFromPeriod(vector <int> date1, vector <int> date2)
{
    system("cls");
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
        if ((itr -> getOperationId()  == 1) && (isDateRangeCorrect(itr, date1, date2)))
        {
            cout << "Kwota: " << itr -> getAmount() << " PLN" << endl;
            cout << "Data: " << ConvertMethods::convertVectorDateIntoStringFormat(itr -> getDate()) << endl;
            cout << "Kategoria: " << itr -> getItem() << endl << endl;
            incomes += itr -> getAmount();

        }
    }
    cout << "WYDATKI" << endl;

    for (vector <Operation>::iterator itr = operations.begin(); itr < operations.end(); itr++)
    {
        if ((itr -> getOperationId()  == 2) && (isDateRangeCorrect(itr, date1, date2)))
        {
            cout << "Kwota: " << itr -> getAmount() << " PLN" << endl;
            cout << "Data: " << ConvertMethods::convertVectorDateIntoStringFormat(itr -> getDate()) << endl;
            cout << "Kategoria: " << itr -> getItem() << endl << endl;
            expenses += itr -> getAmount();

        }
    }
    total = incomes - expenses;
    cout << "PRZYCHODY: " << incomes << endl;
    cout << "WYDATKI: " << expenses << endl;
    cout << "SALDO: " << total << endl;
    system("pause");

}

bool AccountManager::isDateRangeCorrect(vector<Operation>::iterator itr, vector <int> date1, vector <int> date2)
{
    return (itr -> getDate() >= date1) && (itr -> getDate() <= date2);
}

void AccountManager::showBalanceCurrentMonth()
{
    system("cls");
    vector <int> beginOfCurrentMonth = setFirsDayCurrentMonth();
    vector <int> endOfCurrentMonth = setLastDayCurrentMonth();

    showBalanceAccountFromPeriod(beginOfCurrentMonth, endOfCurrentMonth);

}

void AccountManager::showBalanceLastMonth()
{
    system("cls");
    vector <int> currentDate = ConvertMethods::getCurrentDate();
    vector <int> beginOfLastMonthDate = {};
    vector <int> endOfLastMonthDate = {};
    vector <int> temp = {};

    string strDateFormat = ConvertMethods::convertVectorDateIntoStringFormat(currentDate);

    int year = ConvertMethods::getIntegerYearFromStringDateFormat(strDateFormat);
    int month = ConvertMethods::getIntegerMonthFromStringDateFormat(strDateFormat) - 1;

    if (month == 0)
    {
        year -= 1;
        month = 12;
    }

    temp = ConvertMethods::insertSingleDigitsFromTheNumberToVector(year);
    beginOfLastMonthDate.insert(beginOfLastMonthDate.end(), temp.begin(), temp.end());
    endOfLastMonthDate.insert(endOfLastMonthDate.end(), temp.begin(), temp.end());

    if (month < 10)
    {
        beginOfLastMonthDate.push_back(0);
        beginOfLastMonthDate.push_back(month);
        endOfLastMonthDate.push_back(0);
        endOfLastMonthDate.push_back(month);

    }
    else
    {
        temp = ConvertMethods::insertSingleDigitsFromTheNumberToVector(month);
        beginOfLastMonthDate.insert(beginOfLastMonthDate.end(), temp.begin(), temp.end());
        endOfLastMonthDate.insert(endOfLastMonthDate.end(), temp.begin(), temp.end());
    }

    beginOfLastMonthDate.push_back(0);
    beginOfLastMonthDate.push_back(1);

    int lastDay = ValidationMethods::countMaxDayInMonth(year, month);
    temp = ConvertMethods::insertSingleDigitsFromTheNumberToVector(lastDay);
    endOfLastMonthDate.insert(endOfLastMonthDate.end(), temp.begin(), temp.end());

    showBalanceAccountFromPeriod(beginOfLastMonthDate, endOfLastMonthDate);

}
vector <int> AccountManager::setFirsDayCurrentMonth()
{
    vector <int> currentDate = ConvertMethods::getCurrentDate();
    vector <int> newVector = {};

    for (size_t i = 0; i < (currentDate.size() - 2); i++)
    {
        newVector.push_back(currentDate[i]);
    }
    newVector.push_back(0);
    newVector.push_back(1);

    return newVector;
}

vector <int> AccountManager::setLastDayCurrentMonth()
{
    vector <int> currentDate = ConvertMethods::getCurrentDate();
    string strFormatDate = ConvertMethods::convertVectorDateIntoStringFormat(currentDate);
    vector <int> newVector = {};
    vector <int> temporary = {};

    int year = ConvertMethods::getIntegerYearFromStringDateFormat(strFormatDate);
    int month = ConvertMethods::getIntegerMonthFromStringDateFormat(strFormatDate);
    int lastDayOfCurrentMonth = ValidationMethods::countMaxDayInMonth(year, month);


    for (size_t i = 0; i < (currentDate.size() - 2); i++)
    {
        newVector.push_back(currentDate[i]);
    }

    temporary = ConvertMethods::insertSingleDigitsFromTheNumberToVector(lastDayOfCurrentMonth);
    newVector.insert(newVector.end(), temporary.begin(), temporary.end());

    return newVector;
}

void AccountManager::showBalanceFrom()
{
    system("cls");
    cout << "PODAJ PRZEDZIAL DAT Z KTOREGO MA ZOSTAC WYSWIETLONY BILANS" << endl;
    cout << "PODAJ POCZATEK PRZEDZIALU" << endl;
    vector <int> date1 = ConvertMethods::getChosenDate();

    cout << "PODAJ KONIEC PRZEDZIALU" << endl;
    vector <int> date2 = ConvertMethods::getChosenDate();

    showBalanceAccountFromPeriod(date1, date2);
}
