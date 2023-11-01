#include <iostream>


#include "FileWithUsers.h"
using namespace std;


int testUserManager()
{
    cout << "Hello world!" << endl;
    return 0;
}

//test FileWithUsers
int main()
{
FileWithUsers fileWithUsers("users.xml");


User user1(1, "mat", "wik", "mateusz", "wiktoroiwcz");
User user2(2, "mat1", "wik1", "mateusz1", "wiktoroiwcz1");
vector <User> users;
users.push_back(user1);
users.push_back(user2);
fileWithUsers.changeUserPasswordInFile(users);


    return 0;
}
