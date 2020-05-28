/* managerFonts.hpp
   ---------------

   Créé par : Tattus
   le : 17/05/2015

   Modifié le : 22/10/2016

*/
#ifndef DEF_MANAGERFONTS
#define DEF_MANAGERFONTS

/// Include :
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include "parametrage.hpp"
#include "errorusManagerus.hpp"
#include "font.hpp"

using namespace std;

/// Classe :
class C_ManagerFonts
{
    public:
        /* Enumérations */
        enum FontResource
        {
            F_REGULAR = 0,
            F_BOLD,
            F_ITALIC,
            F_BOLDITALIC
        };
        /* Méthodes */
        static C_ManagerFonts *getInstance(void);
        static void kill(void);
        //------------------------
        bool loadAllFonts(void); // Charger toutes les polices
        bool loadFont(int fontCode, int sousCode); // Charger une police en particulier
        void closeFont(int fontCode, int sousCode); // Fermer une police en particulier
        void setColorFont(int fontCode, int sousCode, int r, int g, int b, int a); // Voir le tableau excel des ressources pour le paramètre fontCode et sousCode.
        C_Font *getFont(int fontCode, int sousCode); // Voir le tableau excel des ressources pour le paramètre fontCode et sousCode.
    protected:
    private:
        /* Méthodes */
        C_ManagerFonts();
        ~C_ManagerFonts();
        /* Variables */
        int nbRegular;
        C_Font *regular[1];
        int nbBold;
        C_Font *bold[1];
};

#endif // DEF_MANAGERFONTS
