/* mur.hpp
   ---------------

   Créé par : Tattus
   le : 05/11/2016

   Modifié le : 05/11/2016
*/
#ifndef DEF_MUR
#define DEF_MUR

using namespace std;

/// Includes :
#include <iostream>
#include "unite.hpp"

/// Classe :
class C_Mur : public C_Unite
{
    public:
        /* Méthodes */
        C_Mur();
        C_Mur(SDL_Texture *image, int w, int h, int vitesse, int tempsAnimeDeath, int frameDeadStart, int frameDeadEnd);
        ~C_Mur();
        void loosePV(void);
    protected:
        /* Enumérations */
        /* Méthodes */
        /* Attributs */
    private:
};

#endif // DEF_MUR
