/* menuLoose.hpp
   ---------------

   Créé par : Tattus
   le : 11/11/2016

   Modifié le : 11/11/2016
*/
#ifndef DEF_MENULOOSE
#define DEF_MENULOOSE

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
class C_MenuLoose
{
    public:
        /* Méthodes */
        C_MenuLoose();
        C_MenuLoose(int lvl);
        ~C_MenuLoose();
        void launchMenu(void);
    protected:
        /* Enumérations */
        enum active
        {
            REJOUER = 0,
            QUITTER
        };
        /* Méthodes */

        /* Attributs */
        C_EventManager *EventManager;
        C_ManagerImages *ManagerImages;
        C_ManagerFonts *ManagerFonts;
        C_Window *Window;
        int menuActive;
        int numLvl;
    private:
};

#endif // DEF_MENULOOSE
