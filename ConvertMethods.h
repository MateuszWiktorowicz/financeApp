#ifndef CONVERTMETHODS_H
#define CONVERTMETHODS_H


#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <algorithm>

#include "InputMethods.h"
#include "ValidationMethods.h"

using namespace std;

class ConvertMethods
{
    static string enterDate();

public:
    static vector <int> convertStringDateFormatToIntVector(string strDateFormat);
    static string convertIntegerToString(int num);
    static string uppercaseFirstLetterLowercaseElseLetters(string text);
    static string getNumber(string text, int signPosition);
    static int convertStringIntoInt(string num);
    static vector <int> getCurrentDate();
    static vector <int> getChosenDate();
    static string convertVectorDateIntoStringFormat(vector <int> date);
    static string replaceCommasIntoDots(string str);
    static double convertStringToDouble(string str);
    static string convertDoubleToString(double num);
    static int convertCharToInt(char ch);
    static int getIntegerYearFromStringDateFormat(string strDateFormat);
    static int getIntegerMonthFromStringDateFormat(string strDateFormat);
    static int getIntegerDayFromStringDateFormat(string strDateFormat);


};


#endif
