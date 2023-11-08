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
    static int getIntegerYearFromStringDateFormat(string dateInProgramFormat);
    static int getIntegerMonthFromStringDateFormat(string dateInProgramFormat);
    static int getIntegerDayFromStringDateFormat(string dateInProgramFormat);
    static int countMaxDayInMonth(int year, int month, int day);
    static bool isNotLaterThanLastDayOfCurrentMonth(string dataToCheck);
    static int getCurrentDateLastDayOfMonth(vector <int> currentDate);
public:
    static bool isDateCorrect(string dataToCheck);
    static bool isDateFormatCorrect(string dataToCheck);
    static bool isDateYearsMonthsDaysCorrect(string dataToCheck);

};




#endif
