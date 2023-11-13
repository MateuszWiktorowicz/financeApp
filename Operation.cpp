#include "Operation.h"

void Operation::setOperationId(int id)
{
    operationId = id;
}
void Operation::setUserId(int id)
{
    userId = id;
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
vector <int> Operation::getDate()const
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
