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
    cout << "Hello world!" << endl;
    FileWithUsers fileWithUsers("users.txt");
    User user(1, "mat", "wik", "mateusz", "Wiktorowicz");



    fileWithUsers.appendUserToXmlFile(user);


    return 0;
}
