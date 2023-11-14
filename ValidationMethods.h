#ifndef VALIDATIONTMETHODS_H
#define VALIDATIONTMETHODS_H


#include <iostream>
#include <vector>
#include <ctime>

#include "ConvertMethods.h"

using namespace std;

class ValidationMethods
{
    static bool isYearCorrect(vector <int> intVecDataToCheck);
    static bool isMonthCorrect(vector <int> intVecDataToCheck);
    static bool isDayCorrect(vector <int> intVecDataToCheck);
    static bool isNotLaterThanLastDayOfCurrentMonth(vector <int> intVecDataToCheck);
    static int getCurrentDateLastDayOfMonth(vector <int> currentDate);
public:
    static bool isDateCorrect(string dataToCheck);
    static bool isDateFormatCorrect(string dataToCheck);
    static bool isDateYearsMonthsDaysCorrect(vector <int> intVecDataToCheck);
    static int countMaxDayInMonth(vector <int> intVecDataToCheck);

};




#endif
