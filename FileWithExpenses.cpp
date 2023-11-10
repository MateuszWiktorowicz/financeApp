#include "FileWithExpenses.h"


void FileWithExpenses::appendOperationToXmlFile(Operation operation)
{
    CMarkup expensesFile;
    bool fileOpened = expensesFile.Load("expenses.xml");

    fileOpened ? expensesFile.FindElem() : expensesFile.AddElem("Expenses");

    expensesFile.IntoElem();
    expensesFile.AddElem("Expense");
    expensesFile.IntoElem();
    expensesFile.AddElem("operationId", "1");
    expensesFile.AddElem("userId", "1");
    expensesFile.AddElem("date", ConvertMethods::convertVectorDateIntoStringFormat(operation.getDate()));
    expensesFile.AddElem("item", operation.getItem());
    expensesFile.AddElem("amount", ConvertMethods::convertDoubleToString(operation.getAmount()));
    expensesFile.Save("expenses.xml");
}
