/* managerFonts.cpp
   -------------------

   Créé par : Tattus
   le : 17/05/2015

   Modifié le : 22/10/2016

*/
#include "managerFonts.hpp"

static C_ManagerFonts *myInstanceMF = NULL;


C_ManagerFonts::C_ManagerFonts()
{
    nbRegular = 1;
    nbBold = 1;

    for (int i = 0 ; i < nbRegular ; i++)
    {
        regular[i] = NULL;
    }
    for (int i = 0 ; i < nbBold ; i++)
    {
        bold[i] = NULL;
    }
}

C_ManagerFonts::~C_ManagerFonts()
{
    for (int i = 0 ; i < nbRegular ; i++)
    {
        if (regular[i] != NULL)
        {
            delete(regular[i]);
            regular[i] = NULL;
        }
    }
    for (int i = 0 ; i < nbBold ; i++)
    {
        if (bold[i] != NULL)
        {
            delete(bold[i]);
            bold[i] = NULL;
        }
    }
}

C_ManagerFonts *C_ManagerFonts::getInstance(void)
{
    if (myInstanceMF == NULL)
    {
        myInstanceMF = new C_ManagerFonts();
    }
    return myInstanceMF;
}

void C_ManagerFonts::kill(void)
{
    if (myInstanceMF != NULL)
    {
        delete(myInstanceMF);
        myInstanceMF = NULL;
    }
}

bool C_ManagerFonts::loadAllFonts(void)
{
    regular[0] = new C_Font();
    if (!regular[0]->loadRcFont("LiberationSerif-Regular.ttf", TAILLE_TEXTE_DEFAUT))
    {
        return false;
    }
    bold[0] = new C_Font();
    if (!bold[0]->loadRcFont("LiberationSerif-Bold.ttf", 50))
    {
        return false;
    }
    return true;
}

bool C_ManagerFonts::loadFont(int fontCode, int sousCode)
{
    switch(fontCode)
    {
        case F_REGULAR:
            switch(sousCode)
            {
                case 0:
                    if (regular[sousCode] == NULL)
                    {
                        regular[sousCode] = new C_Font();
                        if (!regular[sousCode]->loadRcFont("LiberationSerif-Regular.ttf", TAILLE_TEXTE_DEFAUT))
                        {
                            return false;
                        }
                    }
                    break;
                default:
                    break;
            }
            break;
        case F_BOLD:
            switch(sousCode)
            {
                case 0:
                    if (bold[sousCode] == NULL)
                    {
                        bold[sousCode] = new C_Font();
                        if (!bold[sousCode]->loadRcFont("LiberationSerif-Bold.ttf", 50))
                        {
                            return false;
                        }
                    }
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    return true;
}

void C_ManagerFonts::closeFont(int fontCode, int sousCode)
{
    switch(fontCode)
    {
        case F_REGULAR:
            if (regular[sousCode] != NULL)
            {
                delete(regular[sousCode]);
                regular[sousCode] = NULL;
            }
            break;
        case F_BOLD:
            if (bold[sousCode] != NULL)
            {
                delete(bold[sousCode]);
                bold[sousCode] = NULL;
            }
            break;
        default:
            break;
    }
}

void C_ManagerFonts::setColorFont(int fontCode, int sousCode, int r, int g, int b, int a)
{
    switch(fontCode)
    {
        case F_REGULAR:
            if (regular[sousCode] != NULL)
            {
                regular[sousCode]->setColor(r, g, b, a);
            }
            break;
        case F_BOLD:
            if (bold[sousCode] != NULL)
            {
                bold[sousCode]->setColor(r, g, b, a);
            }
            break;
        default:
            break;
    }
}

C_Font *C_ManagerFonts::getFont(int fontCode, int sousCode)
{
    switch(fontCode)
    {
        case F_REGULAR:
            return regular[sousCode];
            break;
        case F_BOLD:
            return bold[sousCode];
            break;
        default:
            return NULL;
            break;
    }
    return NULL;
}
