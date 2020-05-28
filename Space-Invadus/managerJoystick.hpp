/* managerJoystick.hpp
   --------------------

   Créé par : Tattus
   le : 22/10/2016

   Modifié le : 22/10/2016

*/
#ifndef DEF_MANAGERJOYSTICK
#define DEF_MANAGERJOYSTICK

/// Includes :
#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include "joystick.hpp"

using namespace std;

/// Classe :
class C_ManagerJoystick
{
    public:
        /* Méthodes */
        static C_ManagerJoystick *getInstance(void);
        static void kill(void);
        //------------------------
        bool loadJoysticks(void); // Charge tous les joysticks. S'ils ont déjà été chargé, les recharge.
        int getNumberJoystick(void); // Permet d'obtenir le nombre de Joystick branchés.
        SDL_Joystick *getJoystick(int deviceIndex); // Permet d'obtenir un pointeur sur le Joystick de l'index indiqué.
        int getNbButton(int deviceIndex); // Récupération du nombre de boutons du Joystick de l'index indiqué.
        int getNbAxis(int deviceIndex); // Récupération du nombre d'axes du Joystick de l'index indiqué.
    protected:
    private:
        /* Méthodes */
        C_ManagerJoystick();
        ~C_ManagerJoystick();
        /* Variables */
        vector<C_Joystick*> tableauJoystick;
};

#endif
