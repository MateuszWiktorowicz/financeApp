#include <iostream>
#include <fstream>

#include "XmlFile.h"
#include "User.h"
#include "Markup.h"

using namespace std;

class FileWithUsers : public XmlFile
{
public:
    FileWithUsers(string fileName) : XmlFile(fileName) {};
    void appendUserToXmlFile(User user);
};
