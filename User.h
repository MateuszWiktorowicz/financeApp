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
     User (int id = 0, string login = "", string password = "", string name = "", string surname = "")
    {
        this -> id = id;
        this -> login = login;
        this -> password = password;
        this -> name = name;
        this -> surname = surname;
    }
    void setId(int i);
    void setLogin(string log);
    void setPassword(string pass);
    void setName(string nam);
    void setSurname(string surnam);

    int getId();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();
};
