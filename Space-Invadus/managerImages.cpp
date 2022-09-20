#include <sstream>
#include "managerImages.hpp"

static C_ManagerImages *myInstanceMI = NULL;

C_ManagerImages::C_ManagerImages()
{
    Window = C_Window::getInstance();

    nbGeneral = 2;
    nbBackground = 1;
    nbHuman = 2;
    nbAlien = 4;
    nbTir = 2;

    for (int i = 0 ; i < nbGeneral ; i++)
    {
        general[i] = NULL;
    }
    for (int i = 0 ; i < nbBackground ; i++)
    {
        background[i] = NULL;
    }
    for (int i = 0 ; i < nbHuman ; i++)
    {
        human[i] = NULL;
    }
    for (int i = 0 ; i < nbAlien ; i++)
    {
        alien[i] = NULL;
    }
    for (int i = 0 ; i < nbTir ; i++)
    {
        tir[i] = NULL;
    }
}

C_ManagerImages::~C_ManagerImages()
{
    for (int i = 0 ; i < nbGeneral ; i++)
    {
        if (general[i] != NULL)
        {
            delete(general[i]);
            general[i] = NULL;
        }
    }
    for (int i = 0 ; i < nbBackground ; i++)
    {
        if (background[i] != NULL)
        {
            delete(background[i]);
            background[i] = NULL;
        }
    }
    for (int i = 0 ; i < nbHuman ; i++)
    {
        if (human[i] != NULL)
        {
            delete(human[i]);
            human[i] = NULL;
        }
    }
    for (int i = 0 ; i < nbAlien ; i++)
    {
        if (alien[i] != NULL)
        {
            delete(alien[i]);
            alien[i] = NULL;
        }
    }
    for (int i = 0 ; i < nbTir ; i++)
    {
        if (tir[i] != NULL)
        {
            delete(tir[i]);
            tir[i] = NULL;
        }
    }
}

C_ManagerImages *C_ManagerImages::getInstance(void)
{
    if (myInstanceMI == NULL)
    {
        myInstanceMI = new C_ManagerImages();
    }

    return myInstanceMI;
}

void C_ManagerImages::kill(void)
{
    if (myInstanceMI != NULL)
    {
        delete(myInstanceMI);
        myInstanceMI = NULL;
    }
}

bool C_ManagerImages::loadAllImages(void)
{
    string myName = "";
    stringstream myNumber;
    myNumber.str("");
    string myExtensionPNG = ".png";
    for (int i = 0 ; i < nbGeneral ; i++)
    {
        myNumber << i;
        myName = "gen_" + myNumber.str() + myExtensionPNG;
        myNumber.str("");
        if (general[i] == NULL)
        {
            general[i] = new C_Image();
            if (!general[i]->loadTextureFromRcImg(myName, Window))
            {
                return false;
            }
        }
    }
    for (int i = 0 ; i < nbBackground ; i++)
    {
        myNumber << i;
        myName = "bg_" + myNumber.str() + myExtensionPNG;
        myNumber.str("");
        if (background[i] == NULL)
        {
            background[i] = new C_Image();
            if (!background[i]->loadTextureFromRcImg(myName, Window))
            {
                return false;
            }
        }
    }
    for (int i = 0 ; i < nbHuman ; i++)
    {
        myNumber << i;
        myName = "human_" + myNumber.str() + myExtensionPNG;
        myNumber.str("");
        if (human[i] == NULL)
        {
            human[i] = new C_Image();
            if (!human[i]->loadTextureFromRcImg(myName, Window))
            {
                return false;
            }
        }
    }
    for (int i = 0 ; i < nbAlien ; i++)
    {
        myNumber << i;
        myName = "alien_" + myNumber.str() + myExtensionPNG;
        myNumber.str("");
        if (alien[i] == NULL)
        {
            alien[i] = new C_Image();
            if (!alien[i]->loadTextureFromRcImg(myName, Window))
            {
                return false;
            }
        }
    }
    for (int i = 0 ; i < nbTir ; i++)
    {
        myNumber << i;
        myName = "tir_" + myNumber.str() + myExtensionPNG;
        myNumber.str("");
        if (tir[i] == NULL)
        {
            tir[i] = new C_Image();
            if (!tir[i]->loadTextureFromRcImg(myName, Window))
            {
                return false;
            }
        }
    }
    return true;
}

bool C_ManagerImages::loadImage(int imageCode, int sousCode, string fileName, string fileExtension)
{
    string myName = "";
    stringstream myNumber;
    myNumber.str("");

    myNumber << sousCode;
    myName = fileName + myNumber.str() + fileExtension;
    cout << myName << endl;
    switch(imageCode)
    {
        case I_GEN:
            if (general[sousCode] == NULL)
            {
                general[sousCode] = new C_Image();
                if (!general[sousCode]->loadTextureFromRcImg(myName, Window))
                {
                    return false;
                }
            }
            break;
        case I_BG:
            if (background[sousCode] == NULL)
            {
                background[sousCode] = new C_Image();
                if (!background[sousCode]->loadTextureFromRcImg(myName, Window))
                {
                    return false;
                }
            }
            break;
        case I_HUMAN:
            if (human[sousCode] == NULL)
            {
                human[sousCode] = new C_Image();
                if (!human[sousCode]->loadTextureFromRcImg(myName, Window))
                {
                    return false;
                }
            }
            break;
        case I_ALIEN:
            if (alien[sousCode] == NULL)
            {
                alien[sousCode] = new C_Image();
                if (!alien[sousCode]->loadTextureFromRcImg(myName, Window))
                {
                    return false;
                }
            }
            break;
        case I_TIR:
            if (tir[sousCode] == NULL)
            {
                tir[sousCode] = new C_Image();
                if (!tir[sousCode]->loadTextureFromRcImg(myName, Window))
                {
                    return false;
                }
            }
            break;
        default:
            break;
    }
    return true;
}

void C_ManagerImages::closeImage(int imageCode, int sousCode)
{
    switch(imageCode)
    {
        case I_GEN:
            if (general[sousCode] != NULL)
            {
                delete(general[sousCode]);
                general[sousCode] = NULL;
            }
            break;
        case I_BG:
            if (background[sousCode] != NULL)
            {
                delete(background[sousCode]);
                background[sousCode] = NULL;
            }
            break;
        case I_HUMAN:
            if (human[sousCode] != NULL)
            {
                delete(human[sousCode]);
                human[sousCode] = NULL;
            }
            break;
        case I_ALIEN:
            if (alien[sousCode] != NULL)
            {
                delete(alien[sousCode]);
                alien[sousCode] = NULL;
            }
            break;
        case I_TIR:
            if (tir[sousCode] != NULL)
            {
                delete(tir[sousCode]);
                tir[sousCode] = NULL;
            }
            break;
        default:
            break;
    }
}

C_Image *C_ManagerImages::getImage(int imageCode, int sousCode)
{
    switch(imageCode)
    {
        case I_GEN:
            return general[sousCode];
            break;
        case I_BG:
            return background[sousCode];
            break;
        case I_HUMAN:
            return human[sousCode];
            break;
        case I_ALIEN:
            return alien[sousCode];
            break;
        case I_TIR:
            return tir[sousCode];
            break;
        default:
            return NULL;
            break;
    }
    return NULL;
}
