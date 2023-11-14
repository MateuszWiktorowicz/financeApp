#include <iostream>
#include <vector>


#include "User.h"
#include "InputMethods.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User insertNewUser();
    bool isLoginExist(string log);
public:
    UserManager(string fileName) : fileWithUsers(fileName)
    {
        loggedInUserId = 0;
        users = fileWithUsers.loadUsersFromFile();
    };

    void registerUser();
    int loginUser();
    void changePassword();
    void logout();
    int getLoggedInUserId();
    bool isUserLoggedIn();
};


