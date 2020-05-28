/* image.cpp
   ---------

   Créé par : Tattus
   le : 11/05/2015

   Modifié le : 11/11/2016

*/
#include "image.hpp"
#ifdef PARAM_SDL_IMG
    #include <SDL2/SDL_image.h>
#endif

C_Image::C_Image()
{
    ResourcesManager = C_ResourcesManager::getInstance();
    ErrorManager = C_ErrorManager::getInstance();
    myImg = NULL;
    imgW = 0;
    imgH = 0;
}

C_Image::~C_Image()
{
    if (myImg != NULL)
    {
        SDL_DestroyTexture(myImg);
    }
}

#ifdef PARAM_SDL_IMG
bool C_Image::loadTextureFromImg(string nameImg, C_Window *fenetre)
{
    SDL_Surface *surface = NULL;

    surface = IMG_Load(nameImg.c_str());
    if (surface == NULL)
    {
        ErrorManager->errorCode(SDL_GetError(), C_ErrorManager::ERROR_SDL);
        return false;
    }
    imgW = surface->w;
    imgH = surface->h;

    myImg = SDL_CreateTextureFromSurface(fenetre->getRenderer(), surface);
    if (myImg == NULL)
    {
        ErrorManager->errorCode(SDL_GetError(), C_ErrorManager::ERROR_SDL);
        SDL_FreeSurface(surface);
        return false;
    }

    SDL_FreeSurface(surface);

    return true;
}

bool C_Image::loadTextureFromRcImg(string nameImg, C_Window *fenetre)
{
    SDL_Surface *surface = NULL;

    surface = ResourcesManager->IMG_RcLoad(nameImg);
    if (surface == NULL)
    {
        ErrorManager->errorCode(ResourcesManager->getErrorCode(), C_ErrorManager::ERROR_RESOURCES_MANAGERUS, SDL_GetError(), C_ErrorManager::ERROR_SDL);
        return false;
    }
    imgW = surface->w;
    imgH = surface->h;

    myImg = SDL_CreateTextureFromSurface(fenetre->getRenderer(), surface);
    if (myImg == NULL)
    {
        ErrorManager->errorCode(SDL_GetError(), C_ErrorManager::ERROR_SDL);
        SDL_FreeSurface(surface);
        return false;
    }

    SDL_FreeSurface(surface);

    return true;
}
#endif

bool C_Image::loadTextureFromBmp(string nameImg, C_Window *fenetre)
{
    SDL_Surface *surface = NULL;

    surface = SDL_LoadBMP(nameImg.c_str());
    if (surface == NULL)
    {
        ErrorManager->errorCode(SDL_GetError(), C_ErrorManager::ERROR_SDL);
        return false;
    }
    imgW = surface->w;
    imgH = surface->h;

    myImg = SDL_CreateTextureFromSurface(fenetre->getRenderer(), surface);
    if (myImg == NULL)
    {
        ErrorManager->errorCode(SDL_GetError(), C_ErrorManager::ERROR_SDL);
        SDL_FreeSurface(surface);
        return false;
    }

    SDL_FreeSurface(surface);

    return true;
}

bool C_Image::loadTextureFromRcBmp(string nameImg, C_Window *fenetre)
{
    SDL_Surface *surface = NULL;

    surface = ResourcesManager->LoadRcBitmap(nameImg.c_str());
    if (surface == NULL)
    {
        ErrorManager->errorCode(ResourcesManager->getErrorCode(), C_ErrorManager::ERROR_RESOURCES_MANAGERUS, SDL_GetError(), C_ErrorManager::ERROR_SDL);
        return false;
    }
    imgW = surface->w;
    imgH = surface->h;

    myImg = SDL_CreateTextureFromSurface(fenetre->getRenderer(), surface);
    if (myImg == NULL)
    {
        ErrorManager->errorCode(SDL_GetError(), C_ErrorManager::ERROR_SDL);
        SDL_FreeSurface(surface);
        return false;
    }

    SDL_FreeSurface(surface);

    return true;
}

/*
SDL_Surface *surface = NULL;
    SDL_Texture *texture = NULL;

    surface = SDL_CreateRGBSurface(0, XRES, YRES, 32, 0, 0, 0, 0);
    SDL_RenderReadPixels(contexte->rendu, NULL, SDL_PIXELFORMAT_ARGB8888, surface->pixels, surface->pitch);

    texture = SDL_CreateTextureFromSurface(contexte->rendu, surface);
    if (texture == NULL)
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Erreur !", "Le programme va fermer.\nPour plus de détail, consultez err_report.txt", NULL);
        fprintf(contexte->my_stderr, "Impossible de créer texture Fond. %s \n", SDL_GetError());
        fermetureSurface(contexte, surface);
        return NULL;
    }
    fermetureSurface(contexte, surface);

    return texture;
    */

bool C_Image::loadTexturefromWindow(C_Window *fenetre)
{
    SDL_Surface *surface = NULL;

    surface = SDL_CreateRGBSurface(0, RES_W, RES_H, 32, 0, 0, 0, 0);
    if (surface == NULL)
    {
        ErrorManager->errorCode(SDL_GetError(), C_ErrorManager::ERROR_SDL);
        return false;
    }
    imgW = surface->w;
    imgH = surface->h;
    SDL_RenderReadPixels(fenetre->getRenderer(), NULL, SDL_PIXELFORMAT_ARGB8888, surface->pixels, surface->pitch);

    myImg = SDL_CreateTextureFromSurface(fenetre->getRenderer(), surface);
    if (myImg == NULL)
    {
        ErrorManager->errorCode(SDL_GetError(), C_ErrorManager::ERROR_SDL);
        SDL_FreeSurface(surface);
        return false;
    }

    SDL_FreeSurface(surface);

    return true;
}

/*
contexte->surface = SDL_CreateRGBSurface(0, 10, 100, 32, 0, 0, 0, 0);
    if(contexte->surface == NULL)
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Erreur !", "Le programme va fermer.\nPour plus de détail, consultez my_stderr.txt", NULL);
        fprintf(contexte->my_stderr, "Impossible de créer la surface. %s \n", SDL_GetError());
        fermetureTextures(contexte, 1);
    }
    SDL_FillRect(contexte->surface, NULL, SDL_MapRGB(contexte->surface->format, 0, 0, 255));
    contexte->raquette2 = SDL_CreateTextureFromSurface(contexte->rendu, contexte->surface);
    if (contexte->raquette2 == NULL)
    {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Erreur !", "Le programme va fermer.\nPour plus de détail, consultez my_stderr.txt", NULL);
        fprintf(contexte->my_stderr, "Impossible de créer texture raquette2. %s \n", SDL_GetError());
        fermetureSurfaces(contexte);
        fermetureTextures(contexte, 1);
    }
    fermetureSurfaces(contexte);
    */

bool C_Image::loadTexturefromRectSurface(int w, int h, int r, int g, int b, int a, C_Window *fenetre)
{
    SDL_Surface *surface = NULL;

    surface = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
    if (surface == NULL)
    {
        ErrorManager->errorCode(SDL_GetError(), C_ErrorManager::ERROR_SDL);
        return false;
    }
    imgW = surface->w;
    imgH = surface->h;
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, r, g, b));

    myImg = SDL_CreateTextureFromSurface(fenetre->getRenderer(), surface);
    if (myImg == NULL)
    {
        ErrorManager->errorCode(SDL_GetError(), C_ErrorManager::ERROR_SDL);
        SDL_FreeSurface(surface);
        return false;
    }
    SDL_SetTextureBlendMode(myImg, SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(myImg, a);

    SDL_FreeSurface(surface);

    return true;
}

#ifdef PARAM_SDL_TTF
bool C_Image::loadTextureFromTextBlended(string text, C_Window *fenetre, C_Font *font)
{
    SDL_Surface *surface = NULL;

    surface = TTF_RenderText_Blended(font->getFont(), text.c_str(), font->getColor());
    if (surface == NULL)
    {
        ErrorManager->errorCode(SDL_GetError(), C_ErrorManager::ERROR_SDL);
        return false;
    }
    imgW = surface->w;
    imgH = surface->h;

    myImg = SDL_CreateTextureFromSurface(fenetre->getRenderer(), surface);
    if (myImg == NULL)
    {
        ErrorManager->errorCode(SDL_GetError(), C_ErrorManager::ERROR_SDL);
        SDL_FreeSurface(surface);
        return false;
    }

    SDL_FreeSurface(surface);

    return true;
}
#endif

SDL_Texture *C_Image::getTexture(void)
{
    return myImg;
}

int C_Image::getW(void)
{
    return imgW;
}

int C_Image::getH(void)
{
    return imgH;
}
