#include "FileWithExpenses.h"


void FileWithExpenses::appendOperationToXmlFile(Operation operation)
{
    CMarkup expensesFile;
    bool fileOpened = expensesFile.Load("expenses.xml");

    fileOpened ? expensesFile.FindElem() : expensesFile.AddElem("Expenses");

    expensesFile.IntoElem();
    expensesFile.AddElem("Expense");
    expensesFile.IntoElem();
    expensesFile.AddElem("operationId", "2");
    expensesFile.AddElem("userId", "1");
    expensesFile.AddElem("date", ConvertMethods::convertVectorDateIntoStringFormat(operation.getDate()));
    expensesFile.AddElem("item", operation.getItem());
    expensesFile.AddElem("amount", ConvertMethods::convertDoubleToString(operation.getAmount()));
    expensesFile.Save("expenses.xml");
}

vector <Operation> FileWithExpenses::loadExpensesFromFile()
{
     Operation operation;
    string operationData;
    vector <Operation> operations;
    CMarkup operationsToLoad;

    if (operationsToLoad.Load("expenses.xml"))
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

            operationsToLoad.FindElem("date");
            operation.setDate(ConvertMethods::convertStringDateFormatToIntVector(operationsToLoad.GetData()));

            operationsToLoad.FindElem("item");
            operation.setItem(operationsToLoad.GetData());

            operationsToLoad.FindElem("amount");
            operation.setAmount(ConvertMethods::convertStringToDouble(operationsToLoad.GetData()));

            operationsToLoad.OutOfElem();

            operations.push_back(operation);
        }
    }
    return operations;
}
