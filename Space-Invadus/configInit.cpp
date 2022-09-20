#include "configInit.hpp"

static C_ConfigInit *myInstanceCI = NULL;
static bool CIinit;
static int langage;

C_ConfigInit::C_ConfigInit()
{
    CIinit = false;
    GlobalInitManager = NULL;
    ResourcesManager = NULL;
    langage = FRA;
    #ifdef PARAM_SDL
        Window = NULL;
        ManagerImages = NULL;
        EventManager = NULL;
    #endif
    #ifdef PARAM_SDL_TTF
        ManagerFonts = NULL;
    #endif
    #ifdef PARAM_FMOD_STUDIO_LOW
        SoundManager = NULL;
        ManagerSounds = NULL;
    #endif
}

C_ConfigInit::~C_ConfigInit()
{

}

C_ConfigInit *C_ConfigInit::getInstance(void)
{
    if (myInstanceCI == NULL)
    {
        myInstanceCI = new C_ConfigInit();
    }

    return myInstanceCI;
}

void C_ConfigInit::kill(void)
{
    if (CIinit)
    {
        myInstanceCI->closes();
    }
    if (myInstanceCI != NULL)
    {
        delete(myInstanceCI);
        myInstanceCI = NULL;
    }
}

void C_ConfigInit::initializations(void)
{
    /// Pré-Initialisation
    CIinit = true;
    GlobalInitManager = C_GlobalInitManager::getInstance();
    ResourcesManager = C_ResourcesManager::getInstance();

    /// Initialisations Globales
    #ifdef PARAM_SDL
    if (!GlobalInitManager->initializationSDL(FLAGS_SDL))
    {
        #ifdef PARAM_MSG_BOX
        switch(langage)
        {
            case ENG:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error !", "The software will close.\nFor more details, check the failure file in the folder Error_Repor", NULL);
                break;
            case FRA:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Un problème est survenu !", "Le programme va fermer.\nPour plus de détail, consultez le fichier d'erreur dans le dossier Error_Report", NULL);
                break;
        }
        #endif
        C_ConfigInit::kill();
        exit(EXIT_FAILURE);
    }
    #endif
    #ifdef PARAM_SDL_IMG
    if (!GlobalInitManager->initializationSDLIMG(FLAGS_SDL_IMG))
    {
        #ifdef PARAM_MSG_BOX
        switch(langage)
        {
            case ENG:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error !", "The software will close.\nFor more details, check the failure file in the folder Error_Repor", NULL);
                break;
            case FRA:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Un problème est survenu !", "Le programme va fermer.\nPour plus de détail, consultez le fichier d'erreur dans le dossier Error_Report", NULL);
                break;
        }
        #endif
        C_ConfigInit::kill();
        exit(EXIT_FAILURE);
    }
    #endif
    #ifdef PARAM_SDL_TTF
    if (!GlobalInitManager->initializationSDLTTF())
    {
        #ifdef PARAM_MSG_BOX
        switch(langage)
        {
            case ENG:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error !", "The software will close.\nFor more details, check the failure file in the folder Error_Repor", NULL);
                break;
            case FRA:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Un problème est survenu !", "Le programme va fermer.\nPour plus de détail, consultez le fichier d'erreur dans le dossier Error_Report", NULL);
                break;
        }
        #endif
        C_ConfigInit::kill();
        exit(EXIT_FAILURE);
    }
    #endif
    #ifdef PARAM_SDL_MIX
    if (!GlobalInitManager->initializationSDLMIX(FLAGS_SDL_MIX))
    {
        #ifdef PARAM_MSG_BOX
        switch(langage)
        {
            case ENG:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error !", "The software will close.\nFor more details, check the failure file in the folder Error_Repor", NULL);
                break;
            case FRA:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Un problème est survenu !", "Le programme va fermer.\nPour plus de détail, consultez le fichier d'erreur dans le dossier Error_Report", NULL);
                break;
        }
        #endif
        C_ConfigInit::kill();
        exit(EXIT_FAILURE);
    }
    #endif
    #ifdef PARAM_SDL_NET
    if (!GlobalInitManager->initializationSDLNET())
    {
        #ifdef PARAM_MSG_BOX
        switch(langage)
        {
            case ENG:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error !", "The software will close.\nFor more details, check the failure file in the folder Error_Repor", NULL);
                break;
            case FRA:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Un problème est survenu !", "Le programme va fermer.\nPour plus de détail, consultez le fichier d'erreur dans le dossier Error_Report", NULL);
                break;
        }
        #endif
        C_ConfigInit::kill();
        exit(EXIT_FAILURE);
    }
    #endif
    #ifdef PARAM_FMOD_STUDIO_LOW
    if (!GlobalInitManager->initializationFMOD(NB_CHANNEL, FLAGS_FMOD_STUDIO_LOW))
    {
        #ifdef PARAM_MSG_BOX
        switch(langage)
        {
            case ENG:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error !", "The software will close.\nFor more details, check the failure file in the folder Error_Repor", NULL);
                break;
            case FRA:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Un problème est survenu !", "Le programme va fermer.\nPour plus de détail, consultez le fichier d'erreur dans le dossier Error_Report", NULL);
                break;
        }
        #endif
        C_ConfigInit::kill();
        exit(EXIT_FAILURE);
    }
    #endif
    #ifdef PARAM_SDL
        Window = C_Window::getInstance();
        ManagerImages = C_ManagerImages::getInstance();
        EventManager = C_EventManager::getInstance();
    #endif
    #ifdef PARAM_SDL_TTF
        ManagerFonts = C_ManagerFonts::getInstance();
    #endif
    #ifdef PARAM_FMOD_STUDIO_LOW
        SoundManager = C_SoundManager::getInstance();
        ManagerSounds = C_ManagerSounds::getInstance();
    #endif

    /// Licenses :
    if (!writeLicenses())
    {
        switch(langage)
        {
            case ENG:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error !", "The software will close.\nFor more details, check the failure file in the folder Error_Repor", NULL);
                break;
            case FRA:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Un problème est survenu !", "Le programme va fermer.\nPour plus de détail, consultez le fichier d'erreur dans le dossier Error_Report", NULL);
                break;
        }
        C_ConfigInit::kill();
        exit(EXIT_FAILURE);
    }

    /// Chargement Config
    // Ressources
    ResourcesManager->setRcContainer("SpaceInvadus.res");
    // Fenetre
    string window_name = PROG_NAME;
    // Langage
    C_FileManager fichier;
    fichier.setFilePath("./Language.txt");
    char langue = 0;
    fichier.readChar(&langue, 1);
    switch (langue)
    {
        case '0':
            langage = ENG;
            break;
        case '1':
            langage = FRA;
            break;
        default:
            langage = ENG;
            break;
    }
    // Aléatoire
    srand(time(NULL));

    /// SoundManager
    SoundManager->setSystem(GlobalInitManager->getFMODSystem(), GlobalInitManager->getNbChannel());
    //SoundManager->setFxChannelGroup(0, 49);

    /// Window
    if (!Window->createWindow(window_name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, RES_W, RES_H, SDL_WINDOW_SHOWN, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC, 0, 0, 0, 255))
    {
        switch(langage)
        {
            case ENG:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error !", "The software will close.\nFor more details, check the failure file in the folder Error_Repor", NULL);
                break;
            case FRA:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Un problème est survenu !", "Le programme va fermer.\nPour plus de détail, consultez le fichier d'erreur dans le dossier Error_Report", NULL);
                break;
        }
        C_ConfigInit::kill();
        exit(EXIT_FAILURE);
    }
    if (!Window->setIcon("icone.png"))
    {
        switch(langage)
        {
            case ENG:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error !", "The software will close.\nFor more details, check the failure file in the folder Error_Repor", NULL);
                break;
            case FRA:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Un problème est survenu !", "Le programme va fermer.\nPour plus de détail, consultez le fichier d'erreur dans le dossier Error_Report", NULL);
                break;
        }
        C_ConfigInit::kill();
        exit(EXIT_FAILURE);
    }

    /// Fonts
    if (!ManagerFonts->loadAllFonts())
    {
        switch(langage)
        {
            case ENG:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error !", "The software will close.\nFor more details, check the failure file in the folder Error_Repor", NULL);
                break;
            case FRA:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Un problème est survenu !", "Le programme va fermer.\nPour plus de détail, consultez le fichier d'erreur dans le dossier Error_Report", NULL);
                break;
        }
        C_ConfigInit::kill();
        exit(EXIT_FAILURE);
    }
    ManagerFonts->setColorFont(C_ManagerFonts::F_REGULAR, 0, 255, 255, 255, 255);

    /// Images
    if (!ManagerImages->loadAllImages())
    {
        switch(langage)
        {
            case ENG:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error !", "The software will close.\nFor more details, check the failure file in the folder Error_Repor", NULL);
                break;
            case FRA:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Un problème est survenu !", "Le programme va fermer.\nPour plus de détail, consultez le fichier d'erreur dans le dossier Error_Report", NULL);
                break;
        }
        C_ConfigInit::kill();
        exit(EXIT_FAILURE);
    }

    /// Sounds
    if (!ManagerSounds->loadAllSounds())
    {
        switch(langage)
        {
            case ENG:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error !", "The software will close.\nFor more details, check the failure file in the folder Error_Repor", NULL);
                break;
            case FRA:
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Un problème est survenu !", "Le programme va fermer.\nPour plus de détail, consultez le fichier d'erreur dans le dossier Error_Report", NULL);
                break;
        }
        C_ConfigInit::kill();
        exit(EXIT_FAILURE);
    }

    /// Paramètre Jeu
    // Volume
    FMOD_ChannelGroup_SetVolume(SoundManager->getFxChannelGroup(), 0.5);
    // Répétitions de touches
    EventManager->setRepeatJoystickButton(true, 2);
    EventManager->setRepeatJoystickButton(true, 3);
    EventManager->setRepeatKeyButton(true, SDL_SCANCODE_LEFT);
    EventManager->setRepeatKeyButton(true, SDL_SCANCODE_RIGHT);

    /// Menu
    C_MenuPrincipale menuPrincipale;
    menuPrincipale.launchMenu();
}

int C_ConfigInit::getLanguage(void)
{
    return langage;
}

void C_ConfigInit::closes(void)
{
    #ifdef PARAM_SDL
        C_Window::kill();
        C_ManagerImages::kill();
        C_EventManager::kill();
    #endif
    #ifdef PARAM_SDL_JOYSTICK
        C_ManagerJoystick::kill();
    #endif
    #ifdef PARAM_SDL_TTF
        C_ManagerFonts::kill();
    #endif
    #ifdef PARAM_FMOD_STUDIO_LOW
        C_ManagerSounds::kill();
        C_SoundManager::kill();
    #endif
    C_ResourcesManager::kill();
    C_GlobalInitManager::kill();
    CIinit = false;
}
