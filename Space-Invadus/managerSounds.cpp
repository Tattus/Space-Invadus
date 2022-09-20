#include <sstream>
#include "managerSounds.hpp"

static C_ManagerSounds *myInstanceMS = NULL;

C_ManagerSounds::C_ManagerSounds()
{
    nbFx = 5;

    for (int i = 0 ; i < nbFx ; i++)
    {
        fx[i] = NULL;
    }
}

C_ManagerSounds::~C_ManagerSounds()
{
    for (int i = 0 ; i < nbFx ; i++)
    {
        if (fx[i] != NULL)
        {
            delete(fx[i]);
            fx[i] = NULL;
        }
    }
}

C_ManagerSounds *C_ManagerSounds::getInstance(void)
{
    if (myInstanceMS == NULL)
    {
        myInstanceMS = new C_ManagerSounds();
    }

    return myInstanceMS;
}

void C_ManagerSounds::kill(void)
{
    if (myInstanceMS != NULL)
    {
        delete(myInstanceMS);
        myInstanceMS = NULL;
    }
}

bool C_ManagerSounds::loadAllSounds(void)
{
    string myName = "";
    stringstream myNumber;
    myNumber.str("");
    string myExtensionOGG = ".ogg";
    for (int i = 0 ; i < nbFx ; i++)
    {
        myNumber << i;
        myName = "son_" + myNumber.str() + myExtensionOGG;
        myNumber.str("");
        if (fx[i] == NULL)
        {
            fx[i] = new C_Sound();
            if (!fx[i]->loadRcSound(myName, FMOD_CREATESAMPLE))
            {
                return false;
            }
        }
    }
    return true;
}

bool C_ManagerSounds::loadSound(int soundCode, int sousCode, string fileName, string fileExtension)
{
    string myName = "";
    stringstream myNumber;
    myNumber.str("");

    myNumber << sousCode;
    myName = fileName + myNumber.str() + fileExtension;
    cout << myName << endl;
    switch(soundCode)
    {
        case S_FX:
            if (fx[sousCode] == NULL)
            {
                fx[sousCode] = new C_Sound();
                if (!fx[sousCode]->loadRcSound(myName, FMOD_CREATESAMPLE))
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

void C_ManagerSounds::closeSound(int soundCode, int sousCode)
{
    switch(soundCode)
    {
        case S_FX:
            if (fx[sousCode] != NULL)
            {
                delete(fx[sousCode]);
                fx[sousCode] = NULL;
            }
            break;
        default:
            break;
    }
}

C_Sound *C_ManagerSounds::getSound(int soundCode, int sousCode)
{
    switch(soundCode)
    {
        case S_FX:
            return fx[sousCode];
            break;
        default:
            return NULL;
            break;
    }
    return NULL;
}
