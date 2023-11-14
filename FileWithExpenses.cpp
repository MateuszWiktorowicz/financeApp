#include "FileWithExpenses.h"


void FileWithExpenses::appendOperationToXmlFile(Operation operation)
{
    CMarkup expensesFile;
    bool fileOpened = expensesFile.Load(XmlFile::getFileName());

    fileOpened ? expensesFile.FindElem() : expensesFile.AddElem("Expenses");

    expensesFile.IntoElem();
    expensesFile.AddElem("Expense");
    expensesFile.IntoElem();
    expensesFile.AddElem("operationId", "2");
    expensesFile.AddElem("userId", ConvertMethods::convertIntegerToString(operation.getUserId()));
    expensesFile.AddElem("date", ConvertMethods::convertVectorDateIntoStringFormat(operation.getDate()));
    expensesFile.AddElem("item", operation.getItem());
    expensesFile.AddElem("amount", ConvertMethods::convertDoubleToString(operation.getAmount()));
    expensesFile.Save(XmlFile::getFileName());
}

vector <Operation> FileWithExpenses::loadOperationsFromFile(int loggedInUser)
{
    Operation operation;
    string operationData;
    vector <Operation> operations;
    CMarkup operationsToLoad;

    if (operationsToLoad.Load(XmlFile::getFileName()))
    {
        operationsToLoad.FindElem();
        operationsToLoad.IntoElem();
        while (operationsToLoad.FindElem("Expense"))
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
