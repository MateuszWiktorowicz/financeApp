#include <iostream>


#include "UserManager.h"
using namespace std;


int testUserManager()
{
    cout << "Hello world!" << endl;
    return 0;
}

//test user Manager
int main()
{
    cout << "Hello world!" << endl;
    UserManager userManager;




    userManager.registerUser();
 userManager.loginUser();
userManager.changePassword();
userManager.loginUser();
    return 0;
}
