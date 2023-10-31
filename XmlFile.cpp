#include "XmlFile.h"

string XmlFile::getFileName()
{
    return FILE_NAME;
}

bool XmlFile::isFileEmpty(fstream &textFile)
{
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}
