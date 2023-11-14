#include "ValidationMethods.h"

bool ValidationMethods::isDateCorrect(string dataToCheck)
{
    return (isDateFormatCorrect(dataToCheck) && isDateYearsMonthsDaysCorrect(ConvertMethods::convertStringDateFormatToIntVector(dataToCheck)));
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

bool ValidationMethods::isDateYearsMonthsDaysCorrect(vector <int> intVecDataToCheck)
{
    if (isYearCorrect(intVecDataToCheck) && isMonthCorrect(intVecDataToCheck) && isDayCorrect(intVecDataToCheck) && isNotLaterThanLastDayOfCurrentMonth(intVecDataToCheck))
    {
        return true;
    }
    else
    {
        return false;
    }

}

bool ValidationMethods::isYearCorrect(vector <int> intVecDataToCheck)
{
    int year = ConvertMethods::getIntegerYearFromDateIntVector(intVecDataToCheck);
    return year >= 2000;
}

bool ValidationMethods::isMonthCorrect(vector <int> intVecDataToCheck)
{
    int month = ConvertMethods::getIntegerMonthFromDateIntVector(intVecDataToCheck);
    return month > 0 && month < 13;
}

bool ValidationMethods::isDayCorrect(vector <int> intVecDataToCheck)
{
    int day = ConvertMethods::getIntegerDayFromDateIntVector(intVecDataToCheck);

    int maxDay = countMaxDayInMonth(intVecDataToCheck);

    return day <= maxDay && day > 0;

}

bool ValidationMethods::isNotLaterThanLastDayOfCurrentMonth(vector <int> intVecDataToCheck)
{
    vector <int> lastDayOfCurrentMonth = ConvertMethods::setLastDayMonth(ConvertMethods::getCurrentDate());

    return intVecDataToCheck <= lastDayOfCurrentMonth;
}


int ValidationMethods::countMaxDayInMonth(vector <int> intVecDataToCheck)
{
    int month = ConvertMethods::getIntegerMonthFromDateIntVector(intVecDataToCheck);
    int year = ConvertMethods::getIntegerYearFromDateIntVector(intVecDataToCheck);

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
    else
    {
        cout << "Invalid month";
    }
    return 0;
}
