#include <iostream>
#include <fstream>
#include <vector>

#include "XmlFile.h"
#include "Operation.h"
#include "ConvertMethods.h"

using namespace std;

class FileWithIncomes : public XmlFile
{

    int operationId;

public:
    FileWithIncomes(string fileName) : XmlFile(fileName) {};
    virtual void appendOperationToXmlFile(Operation operation) = 0;


};
