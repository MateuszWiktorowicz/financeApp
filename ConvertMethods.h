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
    static vector <int> getLastMonthVector();
    static vector <int> setFirsDayMonth(vector <int> vecToSetUp);
    static vector <int> setLastDayMonth(vector <int> vecToSetUp);
    static vector <int> insertSingleDigitsFromTheNumberToVector(int num);
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
    static int getIntegerYearFromDateIntVector(vector <int> dateVector);
    static int getIntegerMonthFromDateIntVector(vector <int> dateVector);
    static int getIntegerDayFromDateIntVector(vector <int> dateVector);


};


#endif
