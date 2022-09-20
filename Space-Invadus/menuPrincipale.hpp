#ifndef DEF_MENUPRINCIPALE
#define DEF_MENUPRINCIPALE

using namespace std;

/// Includes :
#include <iostream>
#include "parametrage.hpp"
#include "eventusManagerus.hpp"
#include "managerImages.hpp"
#include "image.hpp"
#include "managerFonts.hpp"
#include "window.hpp"
#include "niveau.hpp"

/// Classe :
class C_MenuPrincipale
{
    public:
        /* Méthodes */
        C_MenuPrincipale();
        ~C_MenuPrincipale();
        void launchMenu(void);
    protected:
        /* Enumérations */
        enum active
        {
            JOUER = 0,
            QUITTER
        };
        /* Méthodes */
        /* Attributs */
        C_EventManager *EventManager;
        C_ManagerImages *ManagerImages;
        C_ManagerFonts *ManagerFonts;
        C_Window *Window;
        int menuActive;
    private:
};

#endif // DEF_MENUPRINCIPALE
