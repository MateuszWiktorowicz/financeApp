#include <iostream>
#include <vector>


#include "User.h"
#include "InputMethods.h"

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector <User> users;



public:
    void registerUser();
    User insertNewUser();

};


