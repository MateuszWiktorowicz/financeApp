#include <iostream>
#include <vector>

using namespace std;

class Operation
{
    int operationId;
    int userId;
    int dateYears;
    int dateMonths;
    int dateDays;
    vector <int> date;
    string item;
    double amount;
public:
    void setOperationId(int id);
    void setUserId(int id);
    void setDateYears(int years);
    void setDateMonths(int months);
    void setDateDays(int days);
    void setDate(vector <int> dateVector);
    void setItem(string desc);
    void setAmount(double sum);

    int getOperationId();
    int getUserId();
    int getDateYears();
    int getDateMonths();
    int getDateDays();
    vector <int> getDate();
    string getItem();
    double getAmount();
};
