/* tir.hpp
   ---------------

   Créé par : Tattus
   le : 27/10/2016

   Modifié le : 27/10/2016
*/
#ifndef DEF_TIR
#define DEF_TIR

using namespace std;

/// Includes :
#include <iostream>
#include "unite.hpp"

/// Classe :
class C_Tir : public C_Unite
{
    public:
        /* Méthodes */
        C_Tir();
        C_Tir(SDL_Texture *image, int x, int y, int vitesse);
        ~C_Tir();
        bool moving(void); // Renvoie True si le tir existe toujours, False s'il n'existe plus.
    protected:
        /* Enumérations */
        /* Méthodes */
        /* Attributs */
    private:
};

#endif // DEF_TIR
