#include "Operation.h"

void Operation::setOperationId(int id)
{
    operationId = id;
}
void Operation::setUserId(int id)
{
    userId = id;
}
void Operation::setDateYears(int years)
{
    dateYears = years;
}
void Operation::setDateMonths(int months)
{
    dateMonths = months;
}
void Operation::setDateDays(int days)
{
    dateDays = days;
}
void Operation::setDate(vector <int> dateVector)
{
    date = dateVector;
}
void Operation::setItem(string desc)
{
    item = desc;
}
void Operation::setAmount(double sum)
{
    amount = sum;
}

int Operation::getOperationId()
{
    return operationId;
}
int Operation::getUserId()
{
    return userId;
}
int Operation::getDateYears()
{
    return dateYears;
}
int Operation::getDateMonths()
{
    return dateMonths;
}
int Operation::getDateDays()
{
    return dateDays;
}
vector <int> Operation::getDate()
{
    return date;
}
string Operation::getItem()
{
    return item;
}
double Operation::getAmount()
{
    return amount;
}
