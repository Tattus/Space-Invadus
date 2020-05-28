/* window.hpp
   ----------

   Créé par : Tattus
   le : 08/05/2015

   Modifié le : 24/10/2016
*/
#ifndef DEF_WINDOW
#define DEF_WINDOW

using namespace std;

/// Includes :
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "parametrage.hpp"
#include "resourcesManagerus.hpp"
#include "errorusManagerus.hpp"

/// Classe :
class C_Window
{
    public:
        /* Méthodes */
        static C_Window *getInstance(void);
        static void kill(void);
        //------------------------
        // createwindow // Créé la fenêtre. Prend les mêmes paramètres que SDL_CreateWindow(), SDL_CreateRenderer().
        bool createWindow(string title, int x, int y, int w, int h, Uint32 flagsWindow, int indexRenderer, Uint32 flagsRenderer, Uint8 rRenderer, Uint8 gRenderer, Uint8 bRenderer, Uint8 aRenderer);
        SDL_Window *getWindow(void); // Permet d'obtenir la fenêtre.
        SDL_Renderer *getRenderer(void); // Permet d'obtenir le rendu.
        bool getMode(void); // Permet d'obtenir le mode.
        // switchFullscreen // Permet de changer le mode fenetré ou plein écran. Avec les flags de SDL_SetWindowFullscreen().
        bool switchFullscreen(Uint32 flags);
        void setHint(string nameHint, string valueHint, int w, int h); // Même paramètres que SDL_SetHint).
        // setIcon // Met une icone à la fenêtre.
        bool setIconBMP(string iconName); // Sans transparence
        bool setIconBMP(string iconName, int r, int g, int b); // En indiquant une couleur de transparence
        #ifdef PARAM_SDL_IMG
            bool setIcon(string iconName); // Autre format que BMP.
        #endif
        //
        int getScreenW(void);
        int getScreenH(void);

    protected:
    private:
        /* Méthodes */
        C_Window();
        ~C_Window();
        /* Variables */
        SDL_Window *myWindow;
        SDL_Renderer *myRenderer;
        bool fullscreen;
        SDL_Surface *myIcon;
        C_ResourcesManager *ResourcesManager;
        C_ErrorManager *ErrorManager;
        int myW;
        int myH;
};

#endif // DEF_WINDOW
