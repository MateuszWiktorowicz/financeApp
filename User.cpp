#include "User.h"

void User::setId(int i)
{
    id = i;
}
void User::setLogin(string log)
{
    login = log;
}
void User::setPassword(string pass)
{
    password = pass;
}
void User::setName(string nam)
{
    name = nam;
}
void User::setSurname(string surnam)
{
    surname = surnam;
}

int User::getId()
{
    return id;
}
string User::getLogin()
{
    return login;
}
string User::getPassword()
{
    return password;
}
