#ifndef DEF_JOYSTICK
#define DEF_JOYSTICK

/// Includes :
#include <iostream>
#include <SDL2/SDL.h>
#include "errorusManagerus.hpp"

using namespace std;

/// Classe :
class C_Joystick
{
    public:
        /* Méthodes */
        C_Joystick();
        ~C_Joystick();
        bool setJoystick(int deviceIndex); // Ouverture du joystick. Renvoie false s'il y a eu une erreur et true si la méthode s'est déroulée correctement.
        SDL_Joystick *getJoystick(void); // Récupération du joystick. Renvoie NULL si le Joystick n'existe pas.
        int getNbButton(void); // Récupération du nombre de boutons du Joystick.
        int getNbAxis(void); // Récupération du nombre d'axes du Joystick.
    protected:
    private:
        /* Variables */
        C_ErrorManager *ErrorManager;
        SDL_Joystick *joystick;
        int nbButton;
        int nbAxis;
};

#endif
