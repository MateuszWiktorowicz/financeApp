#include <iostream>
#include <vector>


#include "User.h"

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector <User> users;
    User insertNewUser();


public:
    void registerUser();

};


