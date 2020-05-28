/* parametrage.hpp
   -----------------

   Créé par : Tattus
   le : 22/10/2016

   Modifié le : 04/11/2016
*/
#ifndef DEF_PARAMETRAGE
#define DEF_PARAMETRAGE

    /// Defines de parametrage -- Décommenter les lignes adéquates.

        #define PARAM_SDL
            #define PARAM_MSG_BOX
            #define PARAM_SDL_JOYSTICK
            #define PARAM_SDL_IMG
            #define PARAM_SDL_TTF
                #define PARAM_LIBERATION_FONT
            //#define PARAM_SDL_MIX
            //#define PARAM_SDL_NET
        #define PARAM_FMOD_STUDIO_LOW
        //#define PARAM_TINY_XML

    /// Fin Parametrage

    /// Parametrage des flags. Indiquer les flags à utiliser pour les initialisations des modules

        #ifdef PARAM_SDL
            #define FLAGS_SDL SDL_INIT_VIDEO | SDL_INIT_JOYSTICK
        #endif
        #ifdef PARAM_SDL_IMG
            #define FLAGS_SDL_IMG IMG_INIT_PNG
        #endif
        #ifdef PARAM_SDL_MIX
            #define FLAGS_SDL_MIX 0
        #endif
        #ifdef PARAM_FMOD_STUDIO_LOW
            #define FLAGS_FMOD_STUDIO_LOW FMOD_INIT_NORMAL
        #endif

    /// Fin parametrage flags

    /// Parametrage des constantes de préprocesseur.

        #define PROG_NAME "Space Invadus"
        #define VERSION "1.0"
        #ifdef PARAM_SDL
            #define RES_W 600
            #define RES_H 800
        #endif
        #ifdef PARAM_FMOD_STUDIO_LOW
            #define NB_CHANNEL 50 // Nombre de canaux à initialisé dans le system FMOD.
        #endif
        #ifdef PARAM_SDL_TTF
            #define TAILLE_TEXTE_DEFAUT 30 // Taille de police par défaut.
        #endif

    /// Fin parametrage des constantes de préprocesseur.

#endif
