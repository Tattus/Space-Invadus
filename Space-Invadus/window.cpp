/* window.cpp
   ----------
   Objet fenetre pour SDL2. nécessite errorusManagerus.cpp et errorusManagerus.h

*/
// Includes :
#include <SDL2/SDL_messagebox.h>
#include "window.hpp"

static C_Window *myInstanceW = NULL;

C_Window::C_Window()
{
    ResourcesManager = C_ResourcesManager::getInstance();
    ErrorManager = C_ErrorManager::getInstance();
    myWindow = NULL;
    myRenderer = NULL;
    fullscreen = false;
    myIcon = NULL;
    myW = 0;
    myH = 0;
}

C_Window::~C_Window()
{
    if (myWindow != NULL)
    {
        SDL_DestroyWindow(myWindow);
    }
    if (myIcon != NULL)
    {
        SDL_FreeSurface(myIcon);
    }
    if (myRenderer !=NULL)
    {
        SDL_DestroyRenderer(myRenderer);
    }
}

C_Window *C_Window::getInstance(void)
{
    if (myInstanceW == NULL)
    {
        myInstanceW = new C_Window();
    }

    return myInstanceW;
}

void C_Window::kill(void)
{
    if (myInstanceW != NULL)
    {
        delete(myInstanceW);
        myInstanceW = NULL;
    }
}

bool C_Window::createWindow(string title, int x, int y, int w, int h, Uint32 flagsWindow, int indexRenderer, Uint32 flagsRenderer, Uint8 rRenderer, Uint8 gRenderer, Uint8 bRenderer, Uint8 aRenderer)
{
    myW = w;
    myH = h;
    myWindow = SDL_CreateWindow(title.c_str(), x, y, w, h, flagsWindow);
    if (myWindow == NULL)
    {
        ErrorManager->errorCode(SDL_GetError(), C_ErrorManager::ERROR_SDL);
        return false;
    }
    if ((flagsWindow == (flagsWindow & SDL_WINDOW_FULLSCREEN)) || (flagsWindow == (flagsWindow & SDL_WINDOW_FULLSCREEN_DESKTOP)))
    {
        fullscreen = true;
    }
    myRenderer = SDL_CreateRenderer(myWindow, indexRenderer, flagsRenderer);
    if (myRenderer == NULL)
    {
        ErrorManager->errorCode(SDL_GetError(), C_ErrorManager::ERROR_SDL);
        return false;
    }
    SDL_SetRenderDrawColor(myRenderer, rRenderer, gRenderer, bRenderer, aRenderer);

    return true;
}

SDL_Window *C_Window::getWindow(void)
{
    return myWindow;
}

SDL_Renderer *C_Window::getRenderer(void)
{
    return myRenderer;
}

bool C_Window::getMode(void)
{
    return fullscreen;
}

bool C_Window::switchFullscreen(Uint32 flags)
{
    SDL_SetWindowFullscreen(myWindow, flags);
    if (SDL_SetWindowFullscreen(myWindow, flags) != 0)
    {
        ErrorManager->errorCode(SDL_GetError(), C_ErrorManager::ERROR_SDL);
        return false;
    }
    if ((flags == (flags & SDL_WINDOW_FULLSCREEN)) || (flags == (flags & SDL_WINDOW_FULLSCREEN_DESKTOP)))
    {
        fullscreen = true;
    }
    else
    {
        fullscreen = false;
    }
    return true;
}

void C_Window::setHint(string nameHint, string valueHint, int w, int h)
{
    SDL_SetHint(nameHint.c_str(), valueHint.c_str());
    SDL_RenderSetLogicalSize(myRenderer, w, h);
}

bool C_Window::setIconBMP(string iconName)
{
    bool returnValue = true;

    myIcon = ResourcesManager->LoadRcBitmap(iconName);
    if (myIcon == NULL)
    {
        ErrorManager->errorCode(ResourcesManager->getErrorCode(), C_ErrorManager::ERROR_RESOURCES_MANAGERUS, SDL_GetError(), C_ErrorManager::ERROR_SDL);
        returnValue = false;
    }
    else
    {
        SDL_SetWindowIcon(myWindow, myIcon);
    }

    return returnValue;
}

bool C_Window::setIconBMP(string iconName, int r, int g, int b)
{
    bool returnValue = true;

    myIcon = ResourcesManager->LoadRcBitmap(iconName);
    if (myIcon == NULL)
    {
        ErrorManager->errorCode(ResourcesManager->getErrorCode(), C_ErrorManager::ERROR_RESOURCES_MANAGERUS, SDL_GetError(), C_ErrorManager::ERROR_SDL);
        returnValue = false;
    }
    else
    {
        SDL_SetColorKey(myIcon, SDL_TRUE, SDL_MapRGB(myIcon->format, r, g, b));

        SDL_SetWindowIcon(myWindow, myIcon);
    }

    return returnValue;
}

#ifdef PARAM_SDL_IMG
bool C_Window::setIcon(string iconName)
{
    bool returnValue = true;

    myIcon = ResourcesManager->IMG_RcLoad(iconName);
    if (myIcon == NULL)
    {
        ErrorManager->errorCode(ResourcesManager->getErrorCode(), C_ErrorManager::ERROR_RESOURCES_MANAGERUS, SDL_GetError(), C_ErrorManager::ERROR_SDL);
        returnValue = false;
    }
    else
    {
        SDL_SetWindowIcon(myWindow, myIcon);
    }

    return returnValue;
}
#endif

int C_Window::getScreenW(void)
{
    return myW;
}

int C_Window::getScreenH(void)
{
    return myH;
}
