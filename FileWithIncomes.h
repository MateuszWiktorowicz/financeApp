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
public:
    FileWithIncomes(string fileName) : FileWithOperations(fileName) {};
   void appendOperationToXmlFile(Operation operation);


};
