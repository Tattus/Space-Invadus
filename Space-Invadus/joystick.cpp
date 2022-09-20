#include "joystick.hpp"

C_Joystick::C_Joystick()
{
    ErrorManager = C_ErrorManager::getInstance();
    joystick = NULL;
}

C_Joystick::~C_Joystick()
{
    if (SDL_JoystickGetAttached(joystick))
    {
        SDL_JoystickClose(joystick);
    }
}

bool C_Joystick::setJoystick(int deviceIndex)
{
    joystick = SDL_JoystickOpen(deviceIndex);
    if (joystick == NULL)
    {
        ErrorManager->errorCode(SDL_GetError(), C_ErrorManager::ERROR_SDL);
        return false;
    }
    nbButton = SDL_JoystickNumButtons(joystick);
    if (nbButton < 0)
    {
        ErrorManager->errorCode(SDL_GetError(), C_ErrorManager::ERROR_SDL);
        return false;
    }
    nbAxis = SDL_JoystickNumAxes(joystick);
    if (nbAxis < 0)
    {
        ErrorManager->errorCode(SDL_GetError(), C_ErrorManager::ERROR_SDL);
        return false;
    }
    return true;
}

SDL_Joystick *C_Joystick::getJoystick(void)
{
    if (SDL_JoystickGetAttached(joystick))
    {
        return joystick;
    }
    return NULL;
}

int C_Joystick::getNbButton(void)
{
    return nbButton;
}

int C_Joystick::getNbAxis(void)
{
    return nbAxis;
}
