#include <iostream>

#include "Markup.h"

using namespace std;

class XmlFile
{
    string const FILE_NAME;

public:
    XmlFile(string fileName) : FILE_NAME(fileName) {};
    string getFileName();
};
