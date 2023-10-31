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
