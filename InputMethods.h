#ifndef HELPFULLMETHODS_H
#define HELPFULLMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

#include "ConvertMethods.h"

using namespace std;

class InputMethods
{
public:
    static char readSign();
    static int readNumber();
    static string readLine();
    static double readDouble();
};


#endif
