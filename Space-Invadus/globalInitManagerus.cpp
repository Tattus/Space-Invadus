#include "globalInitManagerus.hpp"

static C_GlobalInitManager *myInstanceGIM = NULL;

C_GlobalInitManager::C_GlobalInitManager()
{
    ErrorManager = C_ErrorManager::getInstance();
    #ifdef PARAM_SDL
        init_SDL = false;
    #endif
    #ifdef PARAM_SDL_IMG
        init_SDL_IMG = false;
    #endif
    #ifdef PARAM_SDL_TTF
        init_SDL_TTF = false;
    #endif
    #ifdef PARAM_SDL_MIX
        init_SDL_MIX = false;
    #endif
    #ifdef PARAM_SDL_NET
        init_SDL_NET = false;
    #endif
    #ifdef PARAM_FMOD_STUDIO_LOW
        init_FMOD = false;
        init_FMODInter = false;
        mySystem = NULL;
        myNbChannel = 0;
    #endif
}

C_GlobalInitManager::~C_GlobalInitManager()
{

}

C_GlobalInitManager *C_GlobalInitManager::getInstance(void)
{
    if (myInstanceGIM == NULL)
    {
        myInstanceGIM = new C_GlobalInitManager();
    }

    return myInstanceGIM;
}

void C_GlobalInitManager::kill(void)
{
    if (myInstanceGIM != NULL)
    {
        #ifdef PARAM_SDL
            myInstanceGIM->closeSDL();
        #endif
        #ifdef PARAM_SDL_IMG
            myInstanceGIM->closeSDLIMG();
        #endif
        #ifdef PARAM_SDL_TTF
            myInstanceGIM->closeSDLTTF();
        #endif
        delete(myInstanceGIM);
        myInstanceGIM = NULL;
    }
}

#ifdef PARAM_SDL
bool C_GlobalInitManager::initializationSDL(int flags)
{
    if (SDL_Init(flags) != 0)
    {
        ErrorManager->errorCode(SDL_GetError(), C_ErrorManager::ERROR_SDL);
        return false;
    }
    init_SDL = true;
    return true;
}

void C_GlobalInitManager::closeSDL(void)
{
    if (init_SDL)
    {
        SDL_Quit();
        init_SDL = false;
    }
}
#endif

#ifdef PARAM_SDL_IMG
bool C_GlobalInitManager::initializationSDLIMG(int flags)
{
    if (IMG_Init(flags) != flags)
    {
        ErrorManager->errorCode(IMG_GetError(), C_ErrorManager::ERROR_SDLIMG);
        return false;
    }
    init_SDL_IMG = true;
    return true;
}

void C_GlobalInitManager::closeSDLIMG(void)
{
    if (init_SDL_IMG)
    {
        IMG_Quit();
        init_SDL_IMG = false;
    }
}
#endif

#ifdef PARAM_SDL_TTF
bool C_GlobalInitManager::initializationSDLTTF(void)
{
    if (TTF_Init() == -1)
    {
        ErrorManager->errorCode(TTF_GetError(), C_ErrorManager::ERROR_SDLTTF);
        return false;
    }
    init_SDL_TTF = true;
    return true;
}

void C_GlobalInitManager::closeSDLTTF(void)
{
    if (init_SDL_TTF)
    {
        TTF_Quit();
        init_SDL_TTF = false;
    }
}
#endif

#ifdef PARAM_SDL_MIX
bool C_GlobalInitManager::initializationSDLMIX(int flags)
{
    if (Mix_Init(flags) != flags)
    {
        ErrorManager->errorCode(Mix_GetError(), C_ErrorManager::ERROR_SDLMIX);
        return false;
    }
    init_SDL_MIX = true;
    return true;
}

void C_GlobalInitManager::closeSDLMIX(void)
{
    if (init_SDL_MIX)
    {
        Mix_Quit();
        init_SDL_MIX = false;
    }
}
#endif

#ifdef PARAM_SDL_NET
bool C_GlobalInitManager::initializationSDLNET(void)
{
    if (SDLNet_Init() == -1)
    {
        ErrorManager->errorCode(SDLNet_GetError(), C_ErrorManager::ERROR_SDLNET);
        return false;
    }
    init_SDL_NET = true;
    return true;
}

void C_GlobalInitManager::closeSDLNET(void)
{
    if (init_SDL_NET)
    {
        SDLNet_Quit();
        init_SDL_NET = false;
    }
}
#endif

#ifdef PARAM_FMOD_STUDIO_LOW
bool C_GlobalInitManager::initializationFMOD(int nbChannel, int flags)
{
    FMOD_RESULT verifFMOD = FMOD_OK;
    verifFMOD = FMOD_System_Create(&mySystem, FMOD_VERSION);
    if (verifFMOD != FMOD_OK)
    {
        ErrorManager->errorCode(verifFMOD, C_ErrorManager::ERROR_FMOD);
        return false;
    }
    init_FMODInter = true;
    verifFMOD = FMOD_System_Init(mySystem, nbChannel, flags, 0);
    if (verifFMOD != FMOD_OK)
    {
        ErrorManager->errorCode(verifFMOD, C_ErrorManager::ERROR_FMOD);
        return false;
    }
    myNbChannel = nbChannel;
    init_FMOD = true;
    return true;
}

FMOD_SYSTEM *C_GlobalInitManager::getFMODSystem(void)
{
    return mySystem;
}

int C_GlobalInitManager::getNbChannel(void)
{
    return myNbChannel;
}

void C_GlobalInitManager::closeFMOD(void)
{
    if (init_FMODInter)
    {
        FMOD_System_Close(mySystem);
        init_FMODInter = false;
    }
    if (init_FMOD)
    {
        FMOD_System_Release(mySystem);
        init_FMOD = false;
    }
}
#endif


