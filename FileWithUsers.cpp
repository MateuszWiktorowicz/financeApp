#include "FileWithUsers.h"

void FileWithUsers::appendUserToXmlFile(User user)
{
    CMarkup usersFile;
    bool fileOpened = usersFile.Load("users.xml");

    fileOpened ? usersFile.FindElem() : usersFile.AddElem("Users");

    usersFile.IntoElem();
    usersFile.AddElem("User");
    usersFile.IntoElem();
    usersFile.AddElem("id", user.getId());
    usersFile.AddElem("login", user.getLogin());
    usersFile.AddElem("password", user.getPassword());
    usersFile.AddElem("name", user.getName());
    usersFile.AddElem("surname", user.getSurname());
    usersFile.Save("users.xml");
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    User user;
    string userData;
    vector <User> users;
    CMarkup usersToLoad;

    if (usersToLoad.Load("users.xml"))
    {
        usersToLoad.FindElem();
        usersToLoad.IntoElem();
        while (usersToLoad.FindElem("User"))
        {
            usersToLoad.IntoElem();

            usersToLoad.FindElem("id");
            user.setId(atoi(usersToLoad.GetData().c_str()));

            usersToLoad.FindElem("login");
            user.setLogin(usersToLoad.GetData());

            usersToLoad.FindElem("password");
            user.setPassword(usersToLoad.GetData());

            usersToLoad.FindElem("name");
            user.setName(usersToLoad.GetData());

            usersToLoad.FindElem("surname");
            user.setSurname(usersToLoad.GetData());

            usersToLoad.OutOfElem();

            users.push_back(user);
        }
    }
    return users;
}
