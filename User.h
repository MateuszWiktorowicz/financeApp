#include <iostream>

using namespace std;


class User
{
    int id;
    string login;
    string password;
    string name;
    string surname;

public:
    void setId(int i);
    void setLogin(string log);
    void setPassword(string pass);
    void setName(string nam);
    void setSurname(string surnam);

    int getId();
    string getLogin();
    string getPassword();
};
