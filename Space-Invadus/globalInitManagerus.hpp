/* globalInitManagerus.hpp
   -----------------

   Créé par : Tattus
   le : 18/10/2016

   Modifié le : 21/10/2016
*/
#ifndef DEF_GLOBALINITMANAGERUS
#define DEF_GLOBALINITMANAGERUS

/// Includes :
#include "global.hpp"

/// Classe :
class C_GlobalInitManager
{
    public:
        /* Méthodes */
        static C_GlobalInitManager *getInstance(void);
        static void kill(void);
        //-------------------------------
        #ifdef PARAM_SDL
            bool initializationSDL(int flags); // Initialisation de la SDL. La méthode renvoie true si elle s'est déroulée avec sucès et false s'il y a eu une erreur.
            void closeSDL(void); // Fermeture de la SDL.
        #endif
        #ifdef PARAM_SDL_IMG
            bool initializationSDLIMG(int flags); // Initialisation de SDL IMG. La méthode renvoie true si elle s'est déroulée avec sucès et false s'il y a eu une erreur.
            void closeSDLIMG(void); // Fermeture de SDL IMG.
        #endif
        #ifdef PARAM_SDL_TTF
            bool initializationSDLTTF(void); // Initialisation de SDL TTF. La méthode renvoie true si elle s'est déroulée avec sucès et false s'il y a eu une erreur.
            void closeSDLTTF(void); // Fermeture de SDL TTF.
        #endif
        #ifdef PARAM_SDL_MIX
            bool initializationSDLMIX(int flags); // Initialisation de SDL MIX. La méthode renvoie true si elle s'est déroulée avec sucès et false s'il y a eu une erreur.
            void closeSDLMIX(void); // Fermeture de SDL MIX.
        #endif
        #ifdef PARAM_SDL_NET
            bool initializationSDLNET(void); // Initialisation de SDL NET. La méthode renvoie true si elle s'est déroulée avec sucès et false s'il y a eu une erreur.
            void closeSDLNET(void); // Fermeture de SDL NET.
        #endif
        #ifdef PARAM_FMOD_STUDIO_LOW
            bool initializationFMOD(int nbChannel, int flags); // Initialisation de FMOD. La méthode renvoie true si elle s'est déroulée avec sucès et false s'il y a eu une erreur.
            FMOD_SYSTEM *getFMODSystem(void); // Renvoie le systeme FMOD créé par l'initialisation de FMOD.
            int getNbChannel(void); // Permet d'obtenir le nombre de canaux.
            void closeFMOD(void); // Fermeture de FMOD.
        #endif
    protected:
    private:
        /* Méthodes */
        C_GlobalInitManager();
        ~C_GlobalInitManager();
        /* Attributs */
        C_ErrorManager *ErrorManager;
        #ifdef PARAM_SDL
            bool init_SDL; // Variable qui indique si la SDL a été initialisée.
        #endif
        #ifdef PARAM_SDL_IMG
            bool init_SDL_IMG; // Variable qui indique si la SDL IMAGE a été initialisée.
        #endif
        #ifdef PARAM_SDL_TTF
            bool init_SDL_TTF; // Variable qui indique si la SDL TTF a été initialisée.
        #endif
        #ifdef PARAM_SDL_MIX
            bool init_SDL_MIX; // Variable qui indique si la SDL MIXER a été initialisée.
        #endif
        #ifdef PARAM_SDL_NET
            bool init_SDL_NET; // Variable qui indique si la SDL NET a été initialisée.
        #endif
        #ifdef PARAM_FMOD_STUDIO_LOW
            bool init_FMOD;
            bool init_FMODInter;
            FMOD_SYSTEM *mySystem;
            int myNbChannel;
        #endif
};


#endif // DEF_GLOBALINITMANAGERUS
