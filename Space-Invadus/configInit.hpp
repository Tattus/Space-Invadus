/* configInit.hpp
   -----------------

   Créé par : Tattus
   le : 18/10/2016

   Modifié le : 11/11/2016
*/
#ifndef DEF_CONFIGINIT
#define DEF_CONFIGINIT

/// Includes :
#include "global.hpp"
#include "globalInitManagerus.hpp"
#include "menuPrincipale.hpp"
#include "niveau.hpp"

/// Classe :
class C_ConfigInit
{
    public:
        /* Enumérations */
        enum Langue
        {
            ENG = 0,
            FRA
        };
        /* Méthodes */
        static C_ConfigInit *getInstance(void);
        static void kill(void);
        void initializations(void); // Méthode qui initialise le programme.
        static int getLanguage(void);
    protected:
    private:
        /* Méthodes */
        C_ConfigInit();
        ~C_ConfigInit();
        //------------------------
        void closes(void); // Méthode qui ferme ce qui a été initialisé.
        /* Attributs */
        C_GlobalInitManager *GlobalInitManager;
        C_ResourcesManager *ResourcesManager;
        #ifdef PARAM_SDL
            C_Window *Window;
            C_ManagerImages *ManagerImages;
            C_EventManager *EventManager;
        #endif
        #ifdef PARAM_SDL_TTF
            C_ManagerFonts *ManagerFonts;
        #endif
        #ifdef PARAM_FMOD_STUDIO_LOW
            C_SoundManager *SoundManager;
            C_ManagerSounds *ManagerSounds;
        #endif
};

#endif // DEF_CONFIGINIT
