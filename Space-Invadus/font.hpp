#ifndef DEF_FONT
#define DEF_FONT

/// Includes :
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "errorusManagerus.hpp"
#include "resourcesManagerus.hpp"

/// Classe :
class C_Font
{
    public:
        C_Font();
        C_Font(int r, int g, int b, int a); // Constructeur avec la couleur de la police en paramètre.
        ~C_Font();
        bool loadFont(string fontName, int fontSize); // Permet de charger une police.
        bool loadRcFont(string fontName, int fontSize); // Permet de charger une police à partir d'un conteneur de ressource.
        TTF_Font *getFont(void); // Permet d'obtenir la police.
        void setColor(int r, int g, int b, int a); // Permet de changer la couleur de la police.
        SDL_Color getColor(void); // Permet d'obtenir la couleur de la police.
    protected:
    private:
        C_ErrorManager *ErrorManager;
        C_ResourcesManager *ResourcesManager;
        TTF_Font *myFont;
        SDL_Color fontColor;
        bool fromNoDel;
};

#endif // DEF_FONT
