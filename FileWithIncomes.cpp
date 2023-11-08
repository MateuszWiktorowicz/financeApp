#include "FileWithIncomes.h"


void FileWithIncomes::appendOperationToXmlFile(Operation operation)
{
    CMarkup incomesFile;
    bool fileOpened = incomesFile.Load("incomes.xml");

    fileOpened ? incomesFile.FindElem() : incomesFile.AddElem("Incomes");

    incomesFile.IntoElem();
    incomesFile.AddElem("Income");
    incomesFile.IntoElem();
    incomesFile.AddElem("operationId", "1");
    incomesFile.AddElem("userId", "1");
    incomesFile.AddElem("date", ConvertMethods::convertVectorDateIntoStringFormat(operation.getDate()));
    incomesFile.AddElem("item", operation.getItem());
    incomesFile.AddElem("amount", ConvertMethods::convertDoubleToString(operation.getAmount()));
    incomesFile.Save("incomes.xml");
}
