#ifndef DEF_MENUWIN
#define DEF_MENUWIN

using namespace std;

/// Includes :
#include <iostream>
#include "parametrage.hpp"
#include "eventusManagerus.hpp"
#include "managerImages.hpp"
#include "image.hpp"
#include "managerFonts.hpp"
#include "window.hpp"
#include "menuPrincipale.hpp"
#include "niveau.hpp"

/// Classe :
class C_MenuWin
{
    public:
        /* Méthodes */
        C_MenuWin();
        C_MenuWin(int lvl);
        ~C_MenuWin();
        void launchMenu(void);
    protected:
        /* Enumérations */
        /* Méthodes */

        /* Attributs */
        C_EventManager *EventManager;
        C_ManagerImages *ManagerImages;
        C_ManagerFonts *ManagerFonts;
        C_Window *Window;
        int numLvl;
    private:
};

#endif // DEF_MENUWIN
