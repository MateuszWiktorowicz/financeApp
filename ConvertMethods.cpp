#include "ConvertMethods.h"

string ConvertMethods::convertIntegerToString(int num)
{
    ostringstream ss;
    ss << num;
    string str = ss.str();
    return str;
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
    date.push_back(currentDate -> tm_mon + 1);
    date.push_back(currentDate -> tm_mday);

    return date;
}
