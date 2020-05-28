/* managerImages.hpp
   ---------------

   Créé par : Tattus
   le : 17/05/2015

   Modifié le : 27/10/2016

*/
#ifndef DEF_MANAGERIMAGES
#define DEF_MANAGERIMAGES

/// Includes :
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "errorusManagerus.hpp"
#include "window.hpp"
#include "image.hpp"

using namespace std;

/// Classe :
class C_ManagerImages
{
    public:
        /* Enumérations */
        enum ImagesResource
        {
            I_GEN = 0,
            I_BG,
            I_HUMAN,
            I_ALIEN,
            I_TIR
        };
        /* Méthodes */
        static C_ManagerImages *getInstance(void);
        static void kill(void);
        //------------------------
        bool loadAllImages(void); // Charger toutes les images.
        bool loadImage(int imageCode, int sousCode, string fileName, string fileExtension); // Charger une image en particulier.
        void closeImage(int imageCode, int sousCode); // Fermer une image en particulier.
        C_Image *getImage(int imageCode, int sousCode); // Voir le tableau excel des ressources pour les paramètres.
    protected:
    private:
        /* Méthodes */
        C_ManagerImages();
        ~C_ManagerImages();
        /* Variables */
        C_Window *Window;
        int nbGeneral;
        int nbBackground;
        int nbHuman;
        int nbAlien;
        int nbTir;
        C_Image *general[2];
        C_Image *background[1];
        C_Image *human[2];
        C_Image *alien[4];
        C_Image *tir[2];
};

#endif // DEF_MANAGERIMAGES
