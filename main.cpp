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
 userManager.logout();
if(userManager.getLoggedInUserId() > 0)
{
    userManager.changePassword();
}
else
{
    cout << "User nie jest zalogowany";
}

    return 0;
}
