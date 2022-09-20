#ifndef DEF_GLOBAL
#define DEF_GLOBAL

/// Includes :
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "parametrage.hpp"
#include "errorusManagerus.hpp"
#include "resourcesManagerus.hpp" /// --> Nécessite un parametrage local.

#ifdef PARAM_SDL
    #include <SDL2/SDL.h>
    #include "window.hpp"
    #include "managerImages.hpp"
    #include "eventusManagerus.hpp"
    #include "collisions.hpp"
    #ifdef PARAM_MSG_BOX
        #include <SDL2/SDL_messagebox.h>
    #endif
    #ifdef PARAM_SDL_IMG
        #include <SDL2/SDL_image.h>
    #endif
    #ifdef PARAM_SDL_TTF
        #include <SDL2/SDL_ttf.h>
        #include "managerFonts.hpp"
    #endif
    #ifdef PARAM_SDL_MIX
        #include <SDL2/SDL_mixer.h>
    #endif
    #ifdef PARAM_SDL_NET
        #include <SDL2/SDL_net.h>
    #endif
    #ifdef PARAM_SDL_JOYSTICK
        #include "managerJoystick.hpp"
    #endif
#endif
#ifdef PARAM_FMOD_STUDIO_LOW
    #include <FMOD/fmod.hpp>
    #include "soundusManagerus.hpp"
    #include "managerSounds.hpp"
#endif
#ifdef PARAM_TINY_XML
    #include <TinyXML/tinyxml2.h>
#endif

/// Prototypes :
bool writeLicenses(void);

using namespace std;

#endif // DEF_GLOBAL
