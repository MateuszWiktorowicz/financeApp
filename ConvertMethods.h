#ifndef CONVERTMETHODS_H
#define CONVERTMETHODS_H


#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class ConvertMethods
{
public:

    static string convertIntegerToString(int num);
    static string uppercaseFirstLetterLowercaseElseLetters(string text);
    static string getNumber(string text, int signPosition);
    static int convertStringIntoInt(string num);
};


#endif
