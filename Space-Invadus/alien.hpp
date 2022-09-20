#ifndef DEF_ALIEN
#define DEF_ALIEN

using namespace std;

/// Includes :
#include <iostream>
#include <cstdlib>
#include <vector>
#include "managerImages.hpp"
#include "collisions.hpp"
#include "vaisseau.hpp"
#include "mur.hpp"
#include "tir.hpp"

/// Classe :
class C_Alien : public C_Unite
{
    public:
        /* Méthodes */
        C_Alien();
        C_Alien(SDL_Texture *image, int w, int h, int vitesse, int dureeAnimation, int nbFrameAnime, int tempsAnimeDeath, int frameDeadStart, int frameDeadEnd);
        ~C_Alien();
        void setLvl(int niveau);
        void setAnimeDuration(int dureeAnimation);
        void setNbFrameAnimation(int nb);
        void setFirstLine(bool statut);
        bool getFirstLine(void);
        void shoot(void);
        void showLasers(void);
        void moving(void);
        void updateCollisionCord(C_Vaisseau *spaceShip, C_Mur **murTab);
    protected:
        /* Enumérations */
        enum FrameStatut // Liste des statuts de frames.
        {
            F_UP = 0,   // Animation montante
            F_DOWN      // Animation descendante
        };
        /* Méthodes */
        /* Attributs */
        C_ManagerImages *ManagerImages;
        unsigned int lvl;
        vector<C_Tir*> lasers;
        bool firstLine;
        int frameStatut;
        int animeDuration;
        int nbFrameAnimation;
        int delayMoveTotal;
        int delayMove;
        C_Vaisseau *spaceShipCoord;
        C_Mur *mur[3];
    private:
};

#endif // DEF_ALIEN
