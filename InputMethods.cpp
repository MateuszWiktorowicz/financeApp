#include "InputMethods.h"

string InputMethods::readLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

char InputMethods::readSign()
{
    string input = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            sign = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}

int InputMethods::readNumber()
{
    string input = "";
    int num = 0;

    while (true)
    {
        getline(cin, input);

        stringstream myStream(input);
        if (myStream >> num)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return num;
}

double InputMethods::readDouble()
{
    string input = "";
    double num = 0;

    while (true)
    {
        getline(cin, input);
        input = ConvertMethods::replaceCommasIntoDots(input);
        stringstream myStream(input);
        if (myStream >> num)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return num;
}
