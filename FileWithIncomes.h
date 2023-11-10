#include <iostream>
#include <fstream>
#include <vector>

#include "XmlFile.h"
#include "Operation.h"
#include "ConvertMethods.h"


using namespace std;

class FileWithIncomes : public XmlFile
{
public:
    FileWithIncomes(string fileName) : XmlFile(fileName) {};
   void appendOperationToXmlFile(Operation operation);


};
