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
    string log;
    system("cls");

    users.empty() ? user.setId(1) : user.setId(users.back().getId() + 1);

    cout << "REJESTRACJA NOWEGO UZYTKOWNIKA:" << endl;


    do
    {
        cout << "Wprowadz login" << endl;
        getline(cin, log);
        user.setLogin(log);
        if(isLoginExist(log))
        {
            cout << "Login zajety: Wprowadz inny login" << endl;
        }
    }
    while (isLoginExist(log));


    cout << "Wprowadz haslo" << endl;
    user.setPassword(InputMethods::readLine());

    cout << "Wprowadz imie" << endl;
    user.setName(InputMethods::readLine());

    cout << "Wprowadz nazwisko" << endl;
    user.setSurname(InputMethods::readLine());

    return user;

}

bool UserManager::isLoginExist(string log)
{
    bool loginExists = false;
    for (size_t i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == log)
        {
            loginExists = true;
        }

    }
    return loginExists;
}
