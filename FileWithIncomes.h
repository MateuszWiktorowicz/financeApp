#include <iostream>
#include <fstream>
#include <vector>

#include "XmlFile.h"
#include "FileWithOperations.h"
#include "Operation.h"
#include "ConvertMethods.h"


using namespace std;

class FileWithIncomes : public FileWithOperations

{
    const int operationId = 1;
public:
    vector <Operation> loadIncomesFromFile();
    FileWithIncomes(string fileName) : FileWithOperations(fileName) {};
   void appendOperationToXmlFile(Operation operation);


};
