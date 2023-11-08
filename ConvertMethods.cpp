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

vector <int> ConvertMethods::getCurrentDate()
{
    vector <int> date;
    time_t now = time(0);
    tm* currentDate = localtime(&now);


    date.push_back(currentDate -> tm_year + 1900);

    if ((currentDate -> tm_mon + 1) < 10)
    {
        date.push_back(0);
    }
    date.push_back(currentDate -> tm_mon + 1);

    if ((currentDate -> tm_mday) < 10)
    {
        date.push_back(0);
    }
    date.push_back(currentDate -> tm_mday);

    return date;
}

vector <int> ConvertMethods::getChosenDate()
{
    vector <int> intDateVector;
    string date = enterDate();

    for (size_t i = 0; i < date.size(); i++)
    {
        if (date[i] != '-')
        {
            intDateVector.push_back(convertCharToInt((date[i])));
        }
    }
    return intDateVector;
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
    char container;
    stringstream stream;

    for (size_t i = 0; i < 8; i++)
    {

        if (i == 4 || i == 6)
        {
            strDate.push_back('-');
        }
        stream << date[i];
        stream >> container;
        strDate.push_back(container);
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
