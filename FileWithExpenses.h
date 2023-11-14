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
public:
    vector <Operation> loadExpensesFromFile();
    FileWithExpenses(string fileName) : FileWithOperations(fileName) {};
   void appendOperationToXmlFile(Operation operation);


};
