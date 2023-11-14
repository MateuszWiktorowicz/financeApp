#include "FileWithIncomes.h"


void FileWithIncomes::appendOperationToXmlFile(Operation operation)
{
    CMarkup incomesFile;
    bool fileOpened = incomesFile.Load(XmlFile::getFileName());

    fileOpened ? incomesFile.FindElem() : incomesFile.AddElem("Incomes");

    incomesFile.IntoElem();
    incomesFile.AddElem("Income");
    incomesFile.IntoElem();
    incomesFile.AddElem("operationId", ConvertMethods::convertIntegerToString(operationId));
    incomesFile.AddElem("userId", ConvertMethods::convertIntegerToString(operation.getUserId()));
    incomesFile.AddElem("date", ConvertMethods::convertVectorDateIntoStringFormat(operation.getDate()));
    incomesFile.AddElem("item", operation.getItem());
    incomesFile.AddElem("amount", ConvertMethods::convertDoubleToString(operation.getAmount()));
    incomesFile.Save("incomes.xml");
}

vector <Operation> FileWithIncomes::loadOperationsFromFile(int loggedInUser)
{
    Operation operation;
    string operationData;
    vector <Operation> operations;
    CMarkup operationsToLoad;

    if (operationsToLoad.Load(XmlFile::getFileName()))
    {
        operationsToLoad.FindElem();
        operationsToLoad.IntoElem();
        while (operationsToLoad.FindElem("Income"))
        {
            operationsToLoad.IntoElem();

            operationsToLoad.FindElem("operationId");
            operation.setOperationId(ConvertMethods::convertStringIntoInt(operationsToLoad.GetData()));

            operationsToLoad.FindElem("userId");
            operation.setUserId(ConvertMethods::convertStringIntoInt(operationsToLoad.GetData()));
            if (operation.getUserId() == loggedInUser)
            {
                operationsToLoad.FindElem("date");
                operation.setDate(ConvertMethods::convertStringDateFormatToIntVector(operationsToLoad.GetData()));

                operationsToLoad.FindElem("item");
                operation.setItem(operationsToLoad.GetData());

                operationsToLoad.FindElem("amount");
                operation.setAmount(ConvertMethods::convertStringToDouble(operationsToLoad.GetData()));

                operationsToLoad.OutOfElem();

                operations.push_back(operation);
            }
            else
            {
                operationsToLoad.OutOfElem();
            }
        }
    }
    return operations;
}
