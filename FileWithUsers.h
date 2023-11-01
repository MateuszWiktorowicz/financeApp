#include <iostream>
#include <fstream>
#include <vector>

#include "XmlFile.h"
#include "User.h"
#include "ConvertMethods.h"


using namespace std;

class FileWithUsers : public XmlFile
{
public:
    FileWithUsers(string fileName) : XmlFile(fileName) {};
    void appendUserToXmlFile(User user);
    vector <User> loadUsersFromFile();
    void changeUserPasswordInFile(vector <User> users);
};
