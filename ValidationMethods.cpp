#include "ValidationMethods.h"

bool ValidationMethods::isDateCorrect(string dataToCheck)
{
    return (isDateFormatCorrect(dataToCheck) && isDateYearsMonthsDaysCorrect(dataToCheck));
}


bool ValidationMethods::isDateFormatCorrect(string dataToCheck)
{
    if (dataToCheck.size() != 10)
    {
        return false;
    }
    if (dataToCheck[4] != '-' && dataToCheck[7] != '-')
    {
        return false;
    }
    for (size_t i = 0; i < dataToCheck.size(); i++)
    {
        if (i != 4 && i != 7)
        {
            if (!isdigit(dataToCheck[i]))
            {
                return false;
            }
        }
    }
    return true;
}

bool ValidationMethods::isDateYearsMonthsDaysCorrect(string dataToCheck)
{
    int year, month, day;

    year = ConvertMethods::getIntegerYearFromStringDateFormat(dataToCheck);
    month = ConvertMethods::getIntegerMonthFromStringDateFormat(dataToCheck);
    day = ConvertMethods::getIntegerDayFromStringDateFormat(dataToCheck);

    if (isYearCorrect(year) && isMonthCorrect(month) && isDayCorrect(year, month, day) && isNotLaterThanLastDayOfCurrentMonth(dataToCheck))
    {
        return true;
    }
    else
    {
        return false;
    }

}


bool ValidationMethods::isYearCorrect(int yearToCheck)
{
    return yearToCheck >= 2000;
}

bool ValidationMethods::isMonthCorrect(int monthToCheck)
{
    return monthToCheck > 0 && monthToCheck < 13;
}

bool ValidationMethods::isDayCorrect(int year, int month, int day)
{
    int maxDay = countMaxDayInMonth(year, month);
    return day <= maxDay && day > 0;

}

bool ValidationMethods::isNotLaterThanLastDayOfCurrentMonth(string dataToCheck)
{
    vector <int> currentDate = ConvertMethods::getCurrentDate();
    string currentDateInStringFormatWithDashes = ConvertMethods::convertVectorDateIntoStringFormat(currentDate);

    if ((ConvertMethods::getIntegerYearFromStringDateFormat(dataToCheck) <= ConvertMethods::getIntegerYearFromStringDateFormat(currentDateInStringFormatWithDashes))
        && (ConvertMethods::getIntegerMonthFromStringDateFormat(dataToCheck) <= ConvertMethods::getIntegerMonthFromStringDateFormat(currentDateInStringFormatWithDashes)))
    {
        int maxDay = getCurrentDateLastDayOfMonth(currentDate);
        int day = ConvertMethods::getIntegerDayFromStringDateFormat(dataToCheck);

        return day <= maxDay;
    }
    else if ((ConvertMethods::getIntegerYearFromStringDateFormat(dataToCheck) <= ConvertMethods::getIntegerYearFromStringDateFormat(currentDateInStringFormatWithDashes))
        && (ConvertMethods::getIntegerMonthFromStringDateFormat(dataToCheck) < ConvertMethods::getIntegerMonthFromStringDateFormat(currentDateInStringFormatWithDashes)))
        {
            return true;
        }
    else
    {
        return false;
    }

}

int ValidationMethods::getCurrentDateLastDayOfMonth(vector <int> currentDate)
{
    string currentDateInStringFormat = "";
    int currentYear, currentMonth;

    currentDateInStringFormat = ConvertMethods::convertVectorDateIntoStringFormat(currentDate);

    currentYear = ConvertMethods::getIntegerYearFromStringDateFormat(currentDateInStringFormat);
    currentMonth = ConvertMethods::getIntegerMonthFromStringDateFormat(currentDateInStringFormat);

    return countMaxDayInMonth(currentYear, currentMonth);
}

int ValidationMethods::countMaxDayInMonth(int year, int month)
{
    if((month==2) && ((year%400==0) || ((year%100!=0)&&(year%4==0)))){
        return 29;
    }
    else if(month==2){
        return 28;
    }
    else if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
        return 31;
    }
    else if(month==4 || month==6 || month==9 || month==11){
        return 30;
    }
    else cout<<"Invalid month";
}
