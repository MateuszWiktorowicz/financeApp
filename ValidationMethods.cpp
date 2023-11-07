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
    if (dataToCheck[4] != '/' && dataToCheck[7] != '/')
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
    string strDataYear, strDataMonth, strDataDays;

    for (int i = 0; i < 4; i++)
    {
        strDataYear.push_back(dataToCheck[i]);

    }
    for (int i = 5; i < 7; i++)
    {
        strDataMonth.push_back(dataToCheck[i]);

    }
    for (int i = 8; i < 10; i++)
    {
        strDataDays.push_back(dataToCheck[i]);

    }
    year = ConvertMethods::convertStringIntoInt(strDataYear);
    month = ConvertMethods::convertStringIntoInt(strDataMonth);
    day = ConvertMethods::convertStringIntoInt(strDataDays);
    if (isYearCorrect(year) && isMonthCorrect(month) && isDayCorrect(year, month, day))
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
    int maxDay;
    if((month==2) && ((year%400==0) || ((year%100!=0)&&(year%4==0)))){
        maxDay = 29;
    }
    else if(month==2){
        maxDay = 28;
    }
    else if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
        maxDay = 31;
    }
    else if(month==4 || month==6 || month==9 || month==11){
        maxDay = 30;
    }
    else cout<<"Invalid month";

    return day <= maxDay && day > 0;

}
