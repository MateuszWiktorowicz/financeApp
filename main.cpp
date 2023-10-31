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
    vector <User> users;

    users = fileWithUsers.loadUsersFromFile();

    for (auto user : users)
    {
        cout << user.getId() << endl;
        cout << user.getLogin() << endl;
        cout << user.getPassword() << endl;
        cout << user.getName() << endl;
        cout << user.getSurname() << endl;
    }






    return 0;
}
