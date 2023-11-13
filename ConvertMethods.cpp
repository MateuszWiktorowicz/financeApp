#include "ConvertMethods.h"

string ConvertMethods::convertIntegerToString(int num)
{
    ostringstream ss;
    ss << num;
    string str = ss.str();
    return str;
}

string ConvertMethods::convertDoubleToString(double num)
{
    ostringstream ss;
    ss << num;
    string str = ss.str();
    return str;
}

int ConvertMethods::convertCharToInt(char ch)
{
    int num = ch - '0';
    return num;
}

string ConvertMethods::uppercaseFirstLetterLowercaseElseLetters(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string ConvertMethods::getNumber(string text, int signPosition)
{
    string number = "";
    while(isdigit(text[signPosition]) == true)
    {
        number += text[signPosition];
        signPosition ++;
    }
    return number;
}

int ConvertMethods::convertStringIntoInt(string num)
{
    int intNumber;
    istringstream iss(num);
    iss >> intNumber;

    return intNumber;
}

vector <int> ConvertMethods::insertSingleDigitsFromTheNumberToVector(int num)
{
    vector <int> numbers = {};
    while (num > 0)
    {
        numbers.insert(numbers.begin(), num % 10);
        num /= 10;
    }
    return numbers;
}
vector <int> ConvertMethods::getCurrentDate()
{
    int year, month, day;
    vector <int> date = {};
    vector <int> result = {};
    time_t now = time(0);
    tm* currentDate = localtime(&now);


    year = currentDate -> tm_year + 1900;
    result = insertSingleDigitsFromTheNumberToVector(year);
    date.insert(date.end(), result.begin(), result.end());

    if ((currentDate -> tm_mon + 1) < 10)
    {
        date.push_back(0);
    }
    month = currentDate -> tm_mon + 1;
    result = insertSingleDigitsFromTheNumberToVector(month);
    date.insert(date.end(), result.begin(), result.end());

    if ((currentDate -> tm_mday) < 10)
    {
        date.push_back(0);
    }
    day = currentDate -> tm_mday;
    result = insertSingleDigitsFromTheNumberToVector(day);
    date.insert(date.end(), result.begin(), result.end());


    return date;
}

vector <int> ConvertMethods::convertStringDateFormatToIntVector(string strDateFormat)
{
    vector <int> intDateVector = {};
    vector <int> result = {};
    int year, month, day;

    year = getIntegerYearFromStringDateFormat(strDateFormat);
    result = insertSingleDigitsFromTheNumberToVector(year);
    intDateVector.insert(intDateVector.end(), result.begin(), result.end());


    month = getIntegerMonthFromStringDateFormat(strDateFormat);
    result = insertSingleDigitsFromTheNumberToVector(month);
    if (month < 10)
    {
        intDateVector.push_back(0);
    }
    intDateVector.insert(intDateVector.end(), result.begin(), result.end());


    day = getIntegerDayFromStringDateFormat(strDateFormat);
    result = insertSingleDigitsFromTheNumberToVector(day);
    if (day < 10)
    {
        intDateVector.push_back(0);
    }
    intDateVector.insert(intDateVector.end(), result.begin(), result.end());

    return intDateVector;
}

vector <int> ConvertMethods::getChosenDate()
{

    string date = enterDate();
    return convertStringDateFormatToIntVector(date);

}

string ConvertMethods::enterDate()
{
    string date;
    cout << "WPROWADZ DATE W FORMACIE YYYY-MM-DD" << endl;
    cout << "DATA NIE WCZESNIEJSZA NIZ 2000-01-01" << endl;

    do
    {
        date = InputMethods::readLine();
        cout << (ValidationMethods::isDateCorrect(date) ? "WPROWADZONO POPRAWNA DATE" : "DATA W NIEPOPRWANYM FORMACIE. WPROWADZ JESZCZE RAZ") << endl;
    }
    while (!ValidationMethods::isDateCorrect(date));

    return date;
}

string ConvertMethods::convertVectorDateIntoStringFormat(vector <int> date)
{
    string strDate = "";

    for (size_t i = 0; i < date.size(); i++)
    {

        if (i == 4 || i == 6)
        {
            strDate += "-";
        }

        strDate += convertIntegerToString(date[i]);
    }
    return strDate;
}

double ConvertMethods::convertStringToDouble(string str)
{
    return atof(str.c_str());
}

string ConvertMethods::replaceCommasIntoDots(string str)
{
    string str2 = "";
    for (size_t i = 0; i < str.size(); i++)
    {
        (str[i] == ',') ? str2 += '.' : str2 += str[i];

    }
    return str2;
}

int ConvertMethods::getIntegerYearFromStringDateFormat(string strDateFormat)
{
    string strDataYear = "";

    for (int i = 0; i < 4; i++)
    {
        strDataYear.push_back(strDateFormat[i]);

    }
    return convertStringIntoInt(strDataYear);
}

int ConvertMethods::getIntegerMonthFromStringDateFormat(string strDateFormat)
{
    string strDataMonth = "";

    for (int i = 5; i < 7; i++)
    {
        strDataMonth.push_back(strDateFormat[i]);

    }
    return convertStringIntoInt(strDataMonth);
}

int ConvertMethods::getIntegerDayFromStringDateFormat(string strDateFormat)
{
    string strDataDays = "";

    for (int i = 8; i < 10; i++)
    {
        strDataDays.push_back(strDateFormat[i]);

    }
    return convertStringIntoInt(strDataDays);
}

