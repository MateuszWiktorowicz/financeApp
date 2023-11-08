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

    year = getIntegerYearFromStringDateFormat(dataToCheck);
    month = getIntegerMonthFromStringDateFormat(dataToCheck);
    day = getIntegerDayFromStringDateFormat(dataToCheck);

    if (isYearCorrect(year) && isMonthCorrect(month) && isDayCorrect(year, month, day) && isNotLaterThanLastDayOfCurrentMonth(dataToCheck))
    {
        return true;
    }
    else
    {
        return false;
    }

}

int ValidationMethods::getIntegerYearFromStringDateFormat(string dateInProgramFormat)
{
    string strDataYear = "";

    for (int i = 0; i < 4; i++)
    {
        strDataYear.push_back(dateInProgramFormat[i]);

    }
    return ConvertMethods::convertStringIntoInt(strDataYear);
}

int ValidationMethods::getIntegerMonthFromStringDateFormat(string dateInProgramFormat)
{
    string strDataMonth = "";

    for (int i = 5; i < 7; i++)
    {
        strDataMonth.push_back(dateInProgramFormat[i]);

    }
    return ConvertMethods::convertStringIntoInt(strDataMonth);
}

int ValidationMethods::getIntegerDayFromStringDateFormat(string dateInProgramFormat)
{
    string strDataDays = "";

    for (int i = 8; i < 10; i++)
    {
        strDataDays.push_back(dateInProgramFormat[i]);

    }
    return ConvertMethods::convertStringIntoInt(strDataDays);
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
    int maxDay = countMaxDayInMonth(year, month, day);
    return day <= maxDay && day > 0;

}

bool ValidationMethods::isNotLaterThanLastDayOfCurrentMonth(string dataToCheck)
{
    vector <int> currentDate = ConvertMethods::getCurrentDate();
    string currentDateInStringFormatWithDashes = ConvertMethods::convertVectorDateIntoStringFormat(currentDate);

    if ((getIntegerYearFromStringDateFormat(dataToCheck) <= getIntegerYearFromStringDateFormat(currentDateInStringFormatWithDashes))
        && (getIntegerMonthFromStringDateFormat(dataToCheck) <= getIntegerMonthFromStringDateFormat(currentDateInStringFormatWithDashes)))
    {
        int maxDay = getCurrentDateLastDayOfMonth(currentDate);
        int day = getIntegerDayFromStringDateFormat(dataToCheck);

        return day <= maxDay;
    }
    else if ((getIntegerYearFromStringDateFormat(dataToCheck) <= getIntegerYearFromStringDateFormat(currentDateInStringFormatWithDashes))
        && (getIntegerMonthFromStringDateFormat(dataToCheck) < getIntegerMonthFromStringDateFormat(currentDateInStringFormatWithDashes)))
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
    int currentYear, currentMonth, currentDay;

    currentDateInStringFormat = ConvertMethods::convertVectorDateIntoStringFormat(currentDate);

    currentYear = getIntegerYearFromStringDateFormat(currentDateInStringFormat);
    currentMonth = getIntegerMonthFromStringDateFormat(currentDateInStringFormat);
    currentDay = getIntegerDayFromStringDateFormat(currentDateInStringFormat);

    return countMaxDayInMonth(currentYear, currentMonth, currentDay);
}

int ValidationMethods::countMaxDayInMonth(int year, int month, int day)
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
