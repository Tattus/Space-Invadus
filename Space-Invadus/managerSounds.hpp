#ifndef DEF_MANAGERSOUNDS
#define DEF_MANAGERSOUNDS

/// Includes :
#include <iostream>
#include <FMOD/fmod.hpp>
#include "errorusManagerus.hpp"
#include "sound.hpp"

using namespace std;

/// Classe :
class C_ManagerSounds
{
    public:
        /* Enumérations */
        enum SoundsResource
        {
            S_FX = 0,
        };
        /* Méthodes */
        static C_ManagerSounds *getInstance(void);
        static void kill(void);
        //------------------------
        bool loadAllSounds(void); // Charge tout les sons.
        bool loadSound(int soundCode, int sousCode, string fileName, string fileExtension); // Charge un son en particulier.
        void closeSound(int soundCode, int sousCode); // Ferme un son en particulier.
        C_Sound *getSound(int soundCode, int sousCode); // Voir le tableau excel des ressources pour le paramètre.
    protected:
    private:
        /* Méthodes */
        C_ManagerSounds();
        ~C_ManagerSounds();
        /* Variables */
        int nbFx;
        //int nbVoice;
        int nbMusic;
        C_Sound *fx[5];
};

#endif // DEF_MANAGERSOUNDS
