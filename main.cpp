#include <iostream>


#include "ValidationMethods.h"
using namespace std;


int testUserManager()
{
    cout << "Hello world!" << endl;
    return 0;
}

//test FileWithUsers
int main()
{
ValidationMethods validationMethods;

string date = "2004/02/29";
cout << (validationMethods.isDateCorrect(date) ? "true" : "false");


    return 0;
}
