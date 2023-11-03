#ifndef VALIDATIONTMETHODS_H
#define VALIDATIONTMETHODS_H


#include <iostream>
#include <vector>
#include <ctime>

#include "ConvertMethods.h"

using namespace std;

class ValidationMethods
{
    static bool isYearCorrect(int yearToCheck);
    static bool isMonthCorrect(int monthToCheck);
    static bool isDayCorrect(int year, int month, int day);
public:
    static bool isDateCorrect(string dataToCheck);
    static bool isDateFormatCorrect(string dataToCheck);
    static bool isDateYearsMonthsDaysCorrect(string dataToCheck);

};




#endif
