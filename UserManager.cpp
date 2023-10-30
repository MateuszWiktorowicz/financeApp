#include "UserManager.h"

void UserManager::registerUser()
{
    User user = insertNewUser();

    users.push_back(user);

    for (auto user : users)
    {
        cout << user.getId() << endl;
        cout << user.getLogin() << endl;
        cout << user.getPassword() << endl;
    }
    cout << "Rejestracja udana" << endl;
    system("pause");
}

User UserManager::insertNewUser()
{
    User user;
    system("cls");

    users.empty() ? user.setId(1) : user.setId(users.back().getId() + 1);


    cout << "REJESTRACJA NOWEGO UZYTKOWNIKA:" << endl;

    cout << "Wprowadz login" << endl;
    user.setLogin(InputMethods::readLine());

    cout << "Wprowadz haslo" << endl;
    user.setPassword(InputMethods::readLine());

    cout << "Wprowadz imie" << endl;
    user.setName(InputMethods::readLine());

    cout << "Wprowadz nazwisko" << endl;
    user.setSurname(InputMethods::readLine());

    return user;

}
