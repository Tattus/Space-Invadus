/* image.hpp
   ---------

   Créé par : Tattus
   le : 11/05/2015

   Modifié le : 11/11/2016
   ---------
    Lié à image.cpp

*/
#ifndef DEF_IMAGE
#define DEF_IMAGE

using namespace std;

/// Includes :
#include <iostream>
#include <SDL2/SDL.h>
#include "parametrage.hpp"
#include "errorusManagerus.hpp"
#include "resourcesManagerus.hpp"
#ifdef PARAM_SDL_TTF
    #include <SDL2/SDL_ttf.h>
    #include "font.hpp"
#endif
#include "window.hpp"


/// Classe :
class C_Image
{
    public:
        C_Image();
        ~C_Image();
        #ifdef PARAM_SDL_IMG
            bool loadTextureFromImg(string nameImg, C_Window *fenetre); // Charge une image via SDL_image. Renvoie true s'il n'y a pas d'erreur et false dans le cas contraire.
            bool loadTextureFromRcImg(string nameImg, C_Window *fenetre); // Charge une image via SDL_image à partir d'un conteneur de ressource. Renvoie true s'il n'y a pas d'erreur et false dans le cas contraire.
        #endif
        bool loadTextureFromBmp(string nameImg, C_Window *fenetre); // Charge une image BMP. Renvoie true s'il n'y a pas d'erreur et false dans le cas contraire.
        bool loadTextureFromRcBmp(string nameImg, C_Window *fenetre); // Charge une image BMP à partir d'un conteneur de ressource. Renvoie true s'il n'y a pas d'erreur et false dans le cas contraire.
        bool loadTexturefromWindow(C_Window *fenetre); // Charge une image à partir de la fenetre.
        bool loadTexturefromRectSurface(int w, int h, int r, int g, int b, int a, C_Window *fenetre); // Charge une image à partir d'un rectangle
        #ifdef PARAM_SDL_TTF
            bool loadTextureFromTextBlended(string text, C_Window *fenetre, C_Font *police); // Charge du texte dans une texture. Renvoie true s'il n'y a pas d'erreur et false dans le cas contraire.
        #endif
        SDL_Texture *getTexture(void); // Renvoie l'image.
        int getW(void);
        int getH(void);
    protected:
    private:
        C_ErrorManager *ErrorManager;
        C_ResourcesManager *ResourcesManager;
        SDL_Texture *myImg;
        int imgW;
        int imgH;
};

#endif // DEF_IMAGE
