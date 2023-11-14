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

    for (size_t i = 0; i < strDateFormat.size(); i++)
    {
        if (strDateFormat[i] != '-')
        {
            intDateVector.push_back(convertCharToInt(strDateFormat[i]));
        }
    }
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
    cout << "DATA MUSI SIE MIESCIC W PRZEDZIALE: 2000-01-01 / " << convertVectorDateIntoStringFormat(setLastDayMonth(getCurrentDate())) << endl;

    do
    {
        date = InputMethods::readLine();
        cout << (ValidationMethods::isDateCorrect(date) ? "WPROWADZONO POPRAWNA DATE" : "DATA NIEPOPRAWNA. WPROWADZ PONOWNIE") << endl;
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

int ConvertMethods::getIntegerYearFromDateIntVector(vector <int> dateVector)
{
    int year = dateVector[0] * 1000 + dateVector[1] * 100 + dateVector[2] * 10 + dateVector[3];
    return year;
}

int ConvertMethods::getIntegerMonthFromDateIntVector(vector <int> dateVector)
{
    int month = dateVector[4] * 10 + dateVector[5];
    return month;
}

int ConvertMethods::getIntegerDayFromDateIntVector(vector <int> dateVector)
{
    int day = dateVector[6] * 10 + dateVector[7];
    return day;
}

vector <int> ConvertMethods::setFirsDayMonth(vector <int> vecToSetUp)
{
    vector <int> newVector = {};

    for (size_t i = 0; i < 6; i++)
    {
        newVector.push_back(vecToSetUp[i]);
    }
    newVector.push_back(0);
    newVector.push_back(1);

    return newVector;
}

vector <int> ConvertMethods::setLastDayMonth(vector <int> vecToSetUp)
{
    vector <int> newVector = {};
    vector <int> temporary = {};

    int lastDayOfCurrentMonth = ValidationMethods::countMaxDayInMonth(vecToSetUp);

    for (size_t i = 0; i < 6; i++)
    {
        newVector.push_back(vecToSetUp[i]);
    }

    temporary = ConvertMethods::insertSingleDigitsFromTheNumberToVector(lastDayOfCurrentMonth);
    newVector.insert(newVector.end(), temporary.begin(), temporary.end());

    return newVector;
}

vector <int> ConvertMethods::getLastMonthVector()
{
    vector <int> currentDate = ConvertMethods::getCurrentDate();
    vector <int> vec = {};
    int month = getIntegerMonthFromDateIntVector(currentDate) - 1;
    int year = getIntegerMonthFromDateIntVector(currentDate);

    if (month == 1)
    {
        year -= 1;
        month = 12;
    }

    vector <int> temp = ConvertMethods::insertSingleDigitsFromTheNumberToVector(year);
    vec.insert(vec.end(), temp.begin(), temp.end());

    if (month < 10)
    {
        vec.push_back(0);
        vec.push_back(month);
    }
    else
    {
        temp = ConvertMethods::insertSingleDigitsFromTheNumberToVector(month);
        vec.insert(vec.end(), temp.begin(), temp.end());
    }
    return vec;
}
