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

    if (users.empty())
    {
        user.setId(1);
    }

    cout << "REJESTRACJA NOWEGO UZYTKOWNIKA:" << endl;

    cout << "Wprowadz login" << endl;
    user.setLogin(InputMethods::readLine());

    cout << "Wprowadz haslo" << endl;
    user.setLogin(InputMethods::readLine());

    cout << "Wprowadz imie" << endl;
    user.setLogin(InputMethods::readLine());

    cout << "Wprowadz nazwisko" << endl;
    user.setLogin(InputMethods::readLine());

    return user;

}
