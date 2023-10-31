#include <iostream>
#include <fstream>

#include "Markup.h"

using namespace std;

class XmlFile
{
    string const FILE_NAME;

public:
    XmlFile(string fileName) : FILE_NAME(fileName) {};
    string getFileName();
    bool isFileEmpty(fstream &textFile);
};
