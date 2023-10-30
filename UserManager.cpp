#include "UserManager.h"

void UserManager::registerUser()
{
    User user = insertNewUser();

    users.push_back(user);

    cout << "Rejestracja udana" << endl;
    system("pause");
}

User UserManager::insertNewUser()
{
    User user;
    system("cls");

    cout << "REJESTRACJA NOWEGO UZYTKOWNIKA:" << endl;

    cout << "Wprowadz login" << endl;
    user.setLogin("adam");

    cout << "Wprowadz haslo" << endl;
    user.setLogin("adam");

    cout << "Wprowadz imie" << endl;
    user.setLogin("adam");

    cout << "Wprowadz nazwisko" << endl;
    user.setLogin("adam");

    return user;

}
