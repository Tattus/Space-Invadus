/* soundusManagerus.hpp
   --------------------

   Créé par : Tattus
   le : 10/05/2015

   Modifié le : 22/10/2016

*/
#ifndef DEF_SOUNDUSMANAGERUS
#define DEF_SOUNDUSMANAGERUS

using namespace std;

/// Includes :
#include <iostream>
#include <FMOD/fmod.h>
#include "errorusManagerus.hpp"

/// Classe :
class C_SoundManager
{
    public:
        /* Méthodes */
        static C_SoundManager *getInstance(void);
        static void kill(void);
        //-----------------------------
        void setSystem(FMOD_SYSTEM *system, int nbChannel); // Permet d'indiquer le système ansi que le nombre de canaux de ce dernier.
        FMOD_SYSTEM *getSystem(void); // Renvoie le systeme.
        void setFxChannelGroup(int startChannel, int lastChannel); // Permet de définir le groupe qui contient les canaux Fx.
        void setVoiceChannelGroup(int startChannel, int lastChannel); // Permet de définir le groupe qui contient les canaux Voice.
        void setMusicChannelGroup(int startChannel, int lastChannel); // Permet de définir le groupe qui contient les canaux Music.
        FMOD_CHANNELGROUP *getMasterChannelGroup(void); // Permet d'obtenir le groupe qui contient tout les canaux.
        FMOD_CHANNELGROUP *getFxChannelGroup(void); // Permet d'obtenir le groupe qui contient les canaux Fx.
        FMOD_CHANNELGROUP *getVoiceChannelGroup(void); // Permet d'obtenir le groupe qui contient les canaux Voice.
        FMOD_CHANNELGROUP *getMusicChannelGroup(void); // Permet d'obtenir le groupe qui contient les canaux Music.
        FMOD_CHANNEL *getChannel(int numChannel); // Permet de récuperer un canal.
    protected:
    private:
        /* Méthodes */
        C_SoundManager();
        ~C_SoundManager();
        void setChannel(void); // Permet d'assigner les canaux.
        void setMasterChannelGroup(void); // Créé le groupe de canaux qui contient tout les canaux.
        /* Variables */
        FMOD_SYSTEM *mySystem;
        int myNbChannel;
        FMOD_CHANNEL *myChannel[4093];
        FMOD_CHANNELGROUP *masterChannelGroup;
        FMOD_CHANNELGROUP *fxChannelGroup;
        FMOD_CHANNELGROUP *voiceChannelGroup;
        FMOD_CHANNELGROUP *musicChannelGroup;
        C_ErrorManager *ErrorManager;
};

#endif // DEF_SOUNDUSMANAGERUS
