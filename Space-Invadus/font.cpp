/* font.cpp
   ----------

   Créé par : Tattus
   le : 13/05/2015

   Modifié le : 21/10/2016

*/
#include <SDL2/SDL_messagebox.h>
#include "font.hpp"

C_Font::C_Font()
{
    ResourcesManager = C_ResourcesManager::getInstance();
    ErrorManager = C_ErrorManager::getInstance();
    myFont = NULL;
    fromNoDel = false;
    fontColor.a = 0;
    fontColor.r = 0;
    fontColor.g = 0;
    fontColor.b = 255;
}

C_Font::C_Font(int r, int g, int b, int a)
{
    ResourcesManager = C_ResourcesManager::getInstance();
    ErrorManager = C_ErrorManager::getInstance();
    myFont = NULL;
    fromNoDel = false;
    fontColor.a = a;
    fontColor.r = r;
    fontColor.g = g;
    fontColor.b = b;
}

C_Font::~C_Font()
{
    if (myFont != NULL)
    {
        TTF_CloseFont(myFont);
    }
    if (fromNoDel)
    {
        ResourcesManager->closeRcFile();
    }
}

bool C_Font::loadFont(string fontName, int fontSize)
{
    myFont = TTF_OpenFont(fontName.c_str(), fontSize);
    if (myFont ==  NULL)
    {
        ErrorManager->errorCode(TTF_GetError(), C_ErrorManager::ERROR_SDLTTF);
        return false;
    }
    return true;
}

bool C_Font::loadRcFont(string fontName, int fontSize)
{
    myFont = ResourcesManager->TTF_OpenRcFontNoDel(fontName.c_str(), fontSize);
    if (myFont ==  NULL)
    {
        ErrorManager->errorCode(ResourcesManager->getErrorCode(), C_ErrorManager::ERROR_RESOURCES_MANAGERUS, TTF_GetError(), C_ErrorManager::ERROR_SDLTTF);
        return false;
    }
    fromNoDel = true;
    return true;
}

TTF_Font *C_Font::getFont(void)
{
    return myFont;
}

void C_Font::setColor(int r, int g, int b, int a)
{
    fontColor.a = a;
    fontColor.r = r;
    fontColor.g = g;
    fontColor.b = b;
}

SDL_Color C_Font::getColor(void)
{
    return fontColor;
}
