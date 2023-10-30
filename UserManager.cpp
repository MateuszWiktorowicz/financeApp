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
    for (size_t i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == log)
        {
            return true;
        }
    }
    return false;
}

int UserManager::loginUser()
{
    string log = "", pass = "";

    cout <<  "Podaj login: ";
    log = InputMethods::readLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == log)
        {
            for (int numOfAttempts = 3; numOfAttempts > 0; numOfAttempts--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << numOfAttempts << ": ";
                pass = InputMethods::readLine();

                if (itr -> getPassword() == pass)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedInUserId = itr -> getId();
                    return  loggedInUserId;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

void UserManager::changePassword()
{
    string newPassword = "";

    cout << "PODAJ NOWE HASLO: " << endl;
    newPassword = InputMethods::readLine();

    for (vector <User>::iterator itr = users.begin(); itr < users.end(); itr ++)
    {
        if (itr -> getId() == loggedInUserId)
        {
            itr -> setPassword(newPassword);
            cout << "HASLO ZOSTALO ZMIENIONE: " << endl;
            system("pause");
            break;
        }
    }
}

void UserManager::logout()
{
    loggedInUserId = -1;
}

int UserManager::getLoggedInUserId()
{
    return loggedInUserId;
}
