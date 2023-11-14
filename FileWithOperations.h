#ifndef FILEWITHOPERATIONS_H
#define FILEWITHOPERATIONS_H

#include <iostream>
#include <fstream>
#include <vector>

#include "XmlFile.h"
#include "Operation.h"
#include "ConvertMethods.h"

using namespace std;

class FileWithOperations : public XmlFile
{
    int operationId;
public:
    FileWithOperations(string fileName) : XmlFile(fileName) {};
    virtual void appendOperationToXmlFile(Operation operation) = 0;
    virtual vector <Operation> loadOperationsFromFile(int loggedInUser) = 0;


};


#endif
