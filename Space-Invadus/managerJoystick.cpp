/* managerJoystick.cpp
   --------------------

   Créé par : Tattus
   le : 22/10/2016

   Modifié le : 22/10/2016

*/
#include "managerJoystick.hpp"

static C_ManagerJoystick *myInstanceMJ = NULL;

C_ManagerJoystick::C_ManagerJoystick()
{

}

C_ManagerJoystick::~C_ManagerJoystick()
{
    for (unsigned int i = 0 ; i < tableauJoystick.size() ; i++)
    {
        if (tableauJoystick[i] != NULL)
        {
            delete(tableauJoystick[i]);
        }
    }
}

C_ManagerJoystick *C_ManagerJoystick::getInstance(void)
{
    if (myInstanceMJ == NULL)
    {
        myInstanceMJ = new C_ManagerJoystick();
    }

    return myInstanceMJ;
}

void C_ManagerJoystick::kill(void)
{
    if (myInstanceMJ != NULL)
    {
        delete(myInstanceMJ);
        myInstanceMJ = NULL;
    }
}

bool C_ManagerJoystick::loadJoysticks(void)
{
    if (tableauJoystick.size() > 0)
    {
        for (int i = tableauJoystick.size() - 1 ; i >= 0 ; i--)
        {
            if (tableauJoystick[i] != NULL)
            {
                delete(tableauJoystick[i]);
                tableauJoystick.pop_back();
            }
        }
    }
    for (int i = 0 ; i < SDL_NumJoysticks() ; i++)
    {
        tableauJoystick.push_back(new C_Joystick());
        if (!tableauJoystick[i]->setJoystick(i))
        {
            return false;
        }
    }
    return true;
}

int C_ManagerJoystick::getNumberJoystick(void)
{
    return SDL_NumJoysticks();
}

SDL_Joystick *C_ManagerJoystick::getJoystick(int deviceIndex)
{
    if (deviceIndex < SDL_NumJoysticks())
    {
        return tableauJoystick[deviceIndex]->getJoystick();
    }
    return NULL;
}

int C_ManagerJoystick::getNbButton(int deviceIndex)
{
    if (deviceIndex < SDL_NumJoysticks())
    {
        return tableauJoystick[deviceIndex]->getNbButton();
    }
    return 0;
}

int C_ManagerJoystick::getNbAxis(int deviceIndex)
{
    if (deviceIndex < SDL_NumJoysticks())
    {
        return tableauJoystick[deviceIndex]->getNbAxis();
    }
    return 0;
}
