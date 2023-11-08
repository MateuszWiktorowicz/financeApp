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

    static string convertIntegerToString(int num);
    static string uppercaseFirstLetterLowercaseElseLetters(string text);
    static string getNumber(string text, int signPosition);
    static int convertStringIntoInt(string num);
    static vector <int> getCurrentDate();
    static vector <int> getChosenDate();
    static string convertVectorDateIntoStringFormat(vector <int> date);
    static double replaceCommasIntoDots(double value);
    static double convertStringToDouble(string str);


};


#endif
