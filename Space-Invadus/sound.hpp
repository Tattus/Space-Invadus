#ifndef DEF_SOUND
#define DEF_SOUND

using namespace std;

/// Includes :
#include <iostream>
#include <FMOD/fmod.hpp>
#include "errorusManagerus.hpp"
#include "resourcesManagerus.hpp"
#include "soundusManagerus.hpp"

/// Classe :
class C_Sound
{
    public:
        /* Enumérations */
        enum canal
        {
            C_FX = 0,
            C_VOICE,
            C_MUSIC
        };
        /* Méthodes */
        C_Sound();
        ~C_Sound();
        bool loadSound(string soundName, int FMODFlags); // Permet de charger un son.
        bool loadRcSound(string soundName, int FMODFlags); // Permet de charger un son à partir d'un conteneur de ressource.
        bool loadRcSoundNoDel(string soundName, int FMODFlags); // Permet de charger un son à partir d'un conteneur de ressource en streaming.
        FMOD_SOUND *getSound(void); // Permet d'obtenir le son.
        void playSound(int canal); // Permet de jouer le son.
        void stopSound(void);
    protected:
    private:
        /* Variables */
        C_ErrorManager *ErrorManager;
        C_ResourcesManager *ResourcesManager;
        C_SoundManager *SoundManager;
        FMOD_SOUND *mySound;
        int myChannel;
        bool fromNoDel;
};

#endif // DEF_SOUND
