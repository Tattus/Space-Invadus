#ifndef DEF_VAISSEAU
#define DEF_VAISSEAU

using namespace std;

/// Includes :
#include <iostream>
#include <vector>
#include "parametrage.hpp"
#include "managerImages.hpp"
#include "collisions.hpp"
#include "unite.hpp"
#include "mur.hpp"
#include "tir.hpp"


/// Classe :
class C_Vaisseau : public C_Unite
{
    public:
        /* Méthodes */
        C_Vaisseau();
        C_Vaisseau(SDL_Texture *image, int w, int h, int vitesse, int tempsAnimeDeath, int frameDeadStart, int frameDeadEnd);
        ~C_Vaisseau();
        void handleEvent(void);
        void show(void);
        void showLasers(void);
        void loosePV(void);
        void updateCollisionCord(C_Unite **alien0Tab, C_Unite **alien1Tab, C_Unite **alien2Tab, C_Unite **alien3Tab, C_Unite **alien4Tab, C_Unite **alien5Tab, C_Mur **murTab);
        bool getQuit(void); // Permet de quitter le niveau après la mort du joueur.
    protected:
        /* Méthodes */
        /* Attributs */
        C_ManagerImages *ManagerImages;
        bool quit;
        vector<C_Tir*> lasers;
        C_Unite *alien0[10];
        C_Unite *alien1[10];
        C_Unite *alien2[10];
        C_Unite *alien3[10];
        C_Unite *alien4[10];
        C_Unite *alien5[10];
        C_Mur *mur[3];
    private:
};

#endif // DEF_VAISSEAU
