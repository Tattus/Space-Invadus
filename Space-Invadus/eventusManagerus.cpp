/* eventusManagerus.cpp
   ------------------------

   Créé par : Tattus
   le : 18/05/2015

   Modifié le : 23/10/2016
*/
#include "eventusManagerus.hpp"

static C_EventManager *myInstanceEVM = NULL;

C_EventManager::C_EventManager()
{
    keyboardState = SDL_GetKeyboardState(NULL);
    mouseState = SDL_GetMouseState(&myMouseX, &myMouseY);
    myMouseX = 0;
    myMouseY = 0;
    myMouseRelX = 0;
    myMouseRelY = 0;
    myQuit = false;
    for (int i = 0 ; i < SDL_NUM_SCANCODES ; i++)
    {
        repeatKeyButton[i] = false;
    }
    for (int i = 0 ; i < SDL_NUM_SCANCODES ; i++)
    {
        myKeyButton[i] = false;
    }
    for (int i = 0 ; i < SDL_NUM_SCANCODES ; i++)
    {
        myKeyButtonOff[i] = false;
    }
    for (int i = 0 ; i < 6 ; i++)
    {
        repeatMouseButton[i] = false;
    }
    for (int i = 0 ; i < 6 ; i++)
    {
        myMouseButton[i] = false;
    }
    for (int i = 0 ; i < 6 ; i++)
    {
        myMouseButtonOff[i] = false;
    }
    #ifdef PARAM_SDL_JOYSTICK
        ManagerJoystick = C_ManagerJoystick::getInstance();
        ManagerJoystick->loadJoysticks();

        for (int i = 0 ; i < 30 ; i++)
        {

            repeatJoyButton[i] = false;
        }

        for (int i = 0 ; i < ManagerJoystick->getNumberJoystick() ; i++)
        {
            myJoyButtonOff.push_back(vector<bool>(false));
            for (int j = 0 ; j < ManagerJoystick->getNbButton(i) ; j++)
            {
                myJoyButtonOff[i].push_back(false);
            }
        }

        for (int i = 0 ; i < ManagerJoystick->getNumberJoystick() ; i++)
        {
            myJoyButton.push_back(vector<bool>(false));
            for (int j = 0 ; j < ManagerJoystick->getNbButton(i) ; j++)
            {
                myJoyButton[i].push_back(false);
            }
        }

        for (int i = 0 ; i < ManagerJoystick->getNumberJoystick() ; i++)
        {
            myJoyAxis.push_back(vector<int>(0));
            for (int j = 0 ; j < ManagerJoystick->getNbAxis(i) ; j++)
            {
                myJoyAxis[i].push_back(0);
            }
        }
    #endif
}

C_EventManager::~C_EventManager()
{

}

C_EventManager *C_EventManager::getInstance(void)
{
    if (myInstanceEVM == NULL)
    {
        myInstanceEVM = new C_EventManager();
    }

    return myInstanceEVM;
}

void C_EventManager::kill(void)
{
    if (myInstanceEVM != NULL)
    {
        delete(myInstanceEVM);
        myInstanceEVM = NULL;
    }
}

void C_EventManager::updateEvents(void)
{
    myMouseRelX = 0;
    myMouseRelY = 0;

    SDL_PollEvent(&myEvent);
    /// Clavier
    for (int i = 0 ; i < SDL_NUM_SCANCODES ; i++)
    {
        if (keyboardState[i])
        {
            if (repeatKeyButton[i])
            {
                myKeyButton[i] = true;
            }
            else
            {
                if (!myKeyButtonOff[i])
                {
                    myKeyButton[i] = true;
                    myKeyButtonOff[i] = true;
                }
                else
                {
                    myKeyButton[i] = false;
                }
            }
        }
        else
        {
            if (repeatKeyButton[i])
            {
                myKeyButton[i] = false;
            }
            else
            {
                myKeyButton[i] = false;
                myKeyButtonOff[i] = false;
            }
        }
    }


    /// Souris
    mouseState = SDL_GetMouseState(&myMouseX, &myMouseY);
    SDL_GetRelativeMouseState(&myMouseRelX,&myMouseRelY);
    // Boutons
    for (int i = 0 ; i < 6 ; i++)
    {
        if (SDL_GetMouseState(NULL, NULL) & i)
        {
            if (repeatMouseButton[i])
            {
                myMouseButton[i] = true;
            }
            else
            {
                if (!myMouseButtonOff[i])
                {
                    myMouseButton[i] = true;
                    myMouseButtonOff[i] = true;
                }
                else
                {
                    myMouseButton[i] = false;
                }
            }
        }
        else
        {
            if (repeatMouseButton[i])
            {
                myMouseButton[i] = false;
            }
            else
            {
                myMouseButton[i] = false;
                myMouseButtonOff[i] = false;
            }
        }
    }

    #ifdef PARAM_SDL_JOYSTICK
    /// Joystick
    // Branchement ou débranchement d'un joystick
    if (myEvent.jdevice.type == SDL_JOYDEVICEADDED || myEvent.jdevice.type == SDL_JOYDEVICEREMOVED)
    {
        ManagerJoystick->loadJoysticks();

        for (unsigned int i = 0 ; i < myJoyButtonOff.size() ; i++)
        {
            myJoyButtonOff[i].resize(0);
        }
        myJoyButtonOff.resize(0);

        for (unsigned int i = 0 ; i < myJoyButton.size() ; i++)
        {
            myJoyButton[i].resize(0);
        }
        myJoyButton.resize(0);

        for (unsigned int i = 0 ; i < myJoyAxis.size() ; i++)
        {
            myJoyAxis[i].resize(0);
        }
        myJoyAxis.resize(0);

        for (int i = 0 ; i < ManagerJoystick->getNumberJoystick() ; i++)
        {
            myJoyButtonOff.push_back(vector<bool>(false));
            for (int j = 0 ; j < ManagerJoystick->getNbButton(i) ; j++)
            {
                myJoyButtonOff[i].push_back(false);
            }
        }

        for (int i = 0 ; i < ManagerJoystick->getNumberJoystick() ; i++)
        {
            myJoyButton.push_back(vector<bool>(false));
            for (int j = 0 ; j < ManagerJoystick->getNbButton(i) ; j++)
            {
                myJoyButton[i].push_back(true);
            }
        }

        for (int i = 0 ; i < ManagerJoystick->getNumberJoystick() ; i++)
        {
            myJoyAxis.push_back(vector<int>(0));
            for (int j = 0 ; j < ManagerJoystick->getNbAxis(i) ; j++)
            {
                myJoyAxis[i].push_back(0);
            }
        }
    }

    // Boutons
    for (unsigned i = 0 ; i < myJoyButton.size() ; i++)
    {
        for (unsigned  j = 0 ; j < myJoyButton[i].size() ; j++)
        {
            if (SDL_JoystickGetButton(ManagerJoystick->getJoystick(i), j))
            {
                if (repeatJoyButton[j])
                {
                    myJoyButton[i][j] = true;
                }
                else
                {
                    if (!myJoyButtonOff[i][j])
                    {
                        myJoyButton[i][j] = true;
                        myJoyButtonOff[i][j] = true;
                    }
                    else
                    {
                        myJoyButton[i][j] = false;
                    }
                }
            }
            else
            {
                if (repeatJoyButton[j])
                {
                    myJoyButton[i][j] = false;
                }
                else
                {
                    myJoyButton[i][j] = false;
                    myJoyButtonOff[i][j] = false;
                }
            }
        }
    }

    // Axes
    for (unsigned i = 0 ; i < myJoyAxis.size() ; i++)
    {
        for (unsigned  j = 0 ; j < myJoyAxis[i].size() ; j++)
        {
            myJoyAxis[i][j] = SDL_JoystickGetAxis(ManagerJoystick->getJoystick(i), j);
        }
    }
    #endif
    /// Fenêtre
    if (myEvent.type == SDL_QUIT)
    {
        myQuit = true;
    }
}

bool C_EventManager::quit(void)
{
    return myQuit;
}

void C_EventManager::setRepeatKeyButton(bool statut)
{
    for (int i = 0 ; i < SDL_NUM_SCANCODES ; i++)
    {
        repeatKeyButton[i] = statut;
    }

}

void C_EventManager::setRepeatKeyButton(bool statut, SDL_Scancode key)
{
    repeatKeyButton[key] = statut;
}

void C_EventManager::setRepeatMouseButton(bool statut)
{
    for (int i = 0 ; i < 6 ; i++)
    {
        repeatMouseButton[i] = statut;
    }
}

void C_EventManager::setRepeatMouseButton(bool statut, Uint8 button)
{
    repeatMouseButton[button] = statut;
}

bool C_EventManager::getKeyState(SDL_Scancode key)
{
    return myKeyButton[key];
}

bool C_EventManager::getMouseButtonState(Uint8 button)
{
    return myMouseButton[button];
}

bool C_EventManager::mouseMoving(void)
{
    if (myMouseRelX == 0 && myMouseRelY == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int C_EventManager::getMouseX(void)
{
    return myMouseX;
}

int C_EventManager::getMouseY(void)
{
    return myMouseY;
}

int C_EventManager::getMouseRelX(void)
{
    return myMouseRelX;
}

int C_EventManager::getMouseRelY(void)
{
    return myMouseRelY;
}

void C_EventManager::showCursor(bool state)
{
    if (state)
    {
        SDL_ShowCursor(SDL_ENABLE);
    }
    else
    {
        SDL_ShowCursor(SDL_DISABLE);
    }
}

void C_EventManager::captureCursor(bool state)
{
    if (state)
    {
        SDL_SetRelativeMouseMode(SDL_TRUE);
    }
    else
    {
        SDL_SetRelativeMouseMode(SDL_FALSE);
    }
}

#ifdef PARAM_SDL_JOYSTICK
void C_EventManager::setRepeatJoystickButton(bool statut)
{
    for (unsigned i = 0 ; i < 30 ; i++)
    {
        repeatJoyButton[i] = statut;
    }
}

void C_EventManager::setRepeatJoystickButton(bool statut, unsigned int button)
{
    repeatJoyButton[button] = statut;
}

bool C_EventManager::getJoyButtonState(int joystick, unsigned int button)
{
    if (joystick < ManagerJoystick->getNumberJoystick())
    {
        if (button < myJoyButton[joystick].size())
        {
            return myJoyButton[joystick][button];
        }
        return false;
    }
    return false;
}

int C_EventManager::getJoyAxisState(int joystick, unsigned int axis)
{
    if (joystick < ManagerJoystick->getNumberJoystick())
    {
        if (axis < myJoyAxis[joystick].size())
        {
            return myJoyAxis[joystick][axis];
        }
        return 0;
    }
    return 0;
}
#endif
