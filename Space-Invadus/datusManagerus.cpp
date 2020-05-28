/* datusManagerus.cpp
   ------------------

   Créé par : Tattus
   le : 01/05/2015

   Modifié le : 01/05/2015
*/
#include "datusManagerus.hpp"

C_DateManager::C_DateManager()
{
    myErrorCode = NO_ERROR;
    myGlobalFormat = "";
    myDate = "";
    myNumberElements = 0;
}

C_DateManager::~C_DateManager()
{

}

void C_DateManager::setGlobalFormat(string globalFormat)
{
    myGlobalFormat = globalFormat;
}

bool C_DateManager::setFormat(int nbElements, ...)
{
    bool returnValue = true;
    size_t found;
    string texteTemp = "";
    va_list maListeArg;
    va_start (maListeArg, nbElements);
    myNumberElements = nbElements;
    int numberFound = 0;
    int longueur = myGlobalFormat.length();
    int i;

    if (myNumberElements > 100)
    {
        myNumberElements = 100;
    }

    for (i = 0 ; i < longueur ; i++)
    {
        if (myGlobalFormat.at(i) == '*')
        {
            numberFound++;
        }
    }

    if (numberFound == myNumberElements)
    {
        found = 0;

        while (found != string::npos)
        {
            found = myGlobalFormat.find_first_of("*");
            if (found != string::npos)
            {
                texteTemp = (char)va_arg(maListeArg, int);
                myGlobalFormat.replace(found, 1, "%" + texteTemp);
            }
        }
    }
    else
    {
        myErrorCode = NB_ELEMENTS_INCORRECT;
        returnValue = false;
    }
    return returnValue;
}

string C_DateManager::getDate(void)
{
    char dateChar[1000];
    time_t timestamp = time(NULL);

    strftime(dateChar, sizeof(dateChar), myGlobalFormat.c_str(), localtime(&timestamp));

    myDate = dateChar;

    return myDate;
}

int C_DateManager::getErrorCode(void)
{
    return myErrorCode;
}
