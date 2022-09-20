#include "global.hpp"
#include "configInit.hpp"

#ifdef PARAM_SDL
    #define SDL_MAIN_HANDLED
#endif

int main(int argc, char** argv)
{
    #ifdef PARAM_SDL
        SDL_SetMainReady();
    #endif

    C_ConfigInit *ConfigInit = NULL;

    ConfigInit = C_ConfigInit::getInstance();
    ConfigInit->initializations();

    C_ConfigInit::kill();

    return 0;
}
