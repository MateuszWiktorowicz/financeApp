#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>
#include <vector>

using namespace std;

class Operation
{
    int operationId;
    int userId;
    vector <int> date;
    string item;
    double amount;
public:
    void setOperationId(int id);
    void setUserId(int id);
    void setDate(vector <int> dateVector);
    void setItem(string desc);
    void setAmount(double sum);

    int getOperationId();
    int getUserId();
    vector <int> getDate() const;
    string getItem();
    double getAmount();
};


#endif
