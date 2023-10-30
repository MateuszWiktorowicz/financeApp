#include <iostream>
#include <vector>


#include "User.h"
#include "InputMethods.h"

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector <User> users;
    User insertNewUser();
    bool isLoginExist(string log);


public:
    void registerUser();
    int loginUser();
    void changePassword();
    void logout();
    int getLoggedInUserId();


};


