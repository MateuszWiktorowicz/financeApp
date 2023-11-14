#include <iostream>
#include <fstream>
#include <vector>

#include "XmlFile.h"
#include "FileWithOperations.h"
#include "Operation.h"
#include "ConvertMethods.h"


using namespace std;

class FileWithExpenses : public FileWithOperations

{
    const int operationId = 2;
public:
    vector <Operation> loadOperationsFromFile(int loggedInUser);
    FileWithExpenses(string fileName) : FileWithOperations(fileName) {};
   void appendOperationToXmlFile(Operation operation);


};
