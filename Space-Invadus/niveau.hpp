#ifndef DEF_NIVEAU
#define DEF_NIVEAU

using namespace std;

/// Includes :
#include <iostream>
#include "configInit.hpp"
#include "eventusManagerus.hpp"
#include "managerImages.hpp"
#include "window.hpp"
#include "menuWin.hpp"
#include "menuLoose.hpp"
#include "vaisseau.hpp"
#include "mur.hpp"
#include "alien.hpp"
#include "tir.hpp"

/// Classe :
class C_Niveau
{
    public:
        /* Méthodes */
        C_Niveau();
        C_Niveau(int lvl);
        ~C_Niveau();
        void setLevel(int nb);
        bool playLevel(void); // Renvoie false si le joueur a perdu, true si le joueur a gagné.
    protected:
        /* Méthodes */
        bool win(C_Unite **alien0, C_Unite **alien1, C_Unite **alien2, C_Unite **alien3, C_Unite **alien4, C_Unite **alien5);
        bool looseAlienDown(SDL_Rect position);
        /* Attributs */
        C_EventManager *EventManager;
        C_ManagerImages *ManagerImages;
        C_Window *Window;
        int numLvl;
    private:
};

#endif // DEF_NIVEAU
