#include "menuPrincipale.hpp"

C_MenuPrincipale::C_MenuPrincipale()
{
    EventManager = C_EventManager::getInstance();
    ManagerImages = C_ManagerImages::getInstance();
    ManagerFonts = C_ManagerFonts::getInstance();
    Window = C_Window::getInstance();
    menuActive = JOUER;
}

C_MenuPrincipale::~C_MenuPrincipale()
{

}

void C_MenuPrincipale::launchMenu(void)
{
    // Ressources :
    ManagerFonts->setColorFont(C_ManagerFonts::F_REGULAR, 0, 255, 255, 255, 255);
    ManagerFonts->setColorFont(C_ManagerFonts::F_BOLD, 0, 255, 255, 255, 255);
    C_Image *titre = NULL, *texteJouer = NULL, *texteQuitter = NULL;
    titre = new C_Image();
    if (!titre->loadTextureFromTextBlended("Space Invadus", Window, ManagerFonts->getFont(C_ManagerFonts::F_BOLD, 0)))
    {
        delete(titre);
        C_ConfigInit::kill();
        exit(EXIT_FAILURE);
    }
    texteJouer = new C_Image();
    switch (C_ConfigInit::getLanguage())
    {
        case C_ConfigInit::FRA:
            if (!texteJouer->loadTextureFromTextBlended("Jouer", Window, ManagerFonts->getFont(C_ManagerFonts::F_REGULAR, 0)))
            {
                delete(titre);
                delete(texteJouer);
                C_ConfigInit::kill();
                exit(EXIT_FAILURE);
            }
            break;
        case C_ConfigInit::ENG:
            if (!texteJouer->loadTextureFromTextBlended("Play", Window, ManagerFonts->getFont(C_ManagerFonts::F_REGULAR, 0)))
            {
                delete(titre);
                delete(texteJouer);
                C_ConfigInit::kill();
                exit(EXIT_FAILURE);
            }
            break;
        default:
            break;
    }
    texteQuitter = new C_Image();
    switch (C_ConfigInit::getLanguage())
    {
        case C_ConfigInit::FRA:
            if (!texteQuitter->loadTextureFromTextBlended("Quitter", Window, ManagerFonts->getFont(C_ManagerFonts::F_REGULAR, 0)))
            {
                delete(titre);
                delete(texteJouer);
                delete(texteQuitter);
                C_ConfigInit::kill();
                exit(EXIT_FAILURE);
            }
            break;
        case C_ConfigInit::ENG:
            if (!texteQuitter->loadTextureFromTextBlended("Leave", Window, ManagerFonts->getFont(C_ManagerFonts::F_REGULAR, 0)))
            {
                delete(titre);
                delete(texteJouer);
                delete(texteQuitter);
                C_ConfigInit::kill();
                exit(EXIT_FAILURE);
            }
            break;
        default:
            break;
    }
    SDL_Rect posBackground = {0, 0, ManagerImages->getImage(C_ManagerImages::I_BG, 0)->getW(), ManagerImages->getImage(C_ManagerImages::I_BG, 0)->getH()};
    SDL_Rect posTitre = {RES_W / 2 - titre->getW() / 2, 150, titre->getW(), titre->getH()};
    SDL_Rect posTexteJouer = {RES_W / 2 - texteJouer->getW() / 2, 250, texteJouer->getW(), texteJouer->getH()};
    SDL_Rect posTexteQuitter = {RES_W / 2 - texteQuitter->getW() / 2, 300, texteQuitter->getW(), texteQuitter->getH()};
    SDL_Rect posCadre = {RES_W / 2 - ManagerImages->getImage(C_ManagerImages::I_GEN, 0)->getW() / 2, 250 - 2,
                            ManagerImages->getImage(C_ManagerImages::I_GEN, 0)->getW(), ManagerImages->getImage(C_ManagerImages::I_GEN, 0)->getH()};

    // Boucle Principale :
    while(true)
    {
        /// Contrôles
        EventManager->updateEvents();

        if (EventManager->quit())
        {
            delete(titre);
            delete(texteJouer);
            delete(texteQuitter);
            C_ConfigInit::kill();
            exit(EXIT_SUCCESS);
        }
        if (EventManager->getKeyState(SDL_SCANCODE_UP) || EventManager->getKeyState(SDL_SCANCODE_DOWN) || EventManager->getJoyButtonState(0, 0) || EventManager->getJoyButtonState(0, 1))
        {
            if (menuActive == JOUER)
            {
                menuActive = QUITTER;
                posCadre.y = 300 - 2;
            }
            else
            {
                menuActive = JOUER;
                posCadre.y = 250 - 2;
            }
        }
        if (EventManager->getKeyState(SDL_SCANCODE_RETURN) || EventManager->getJoyButtonState(0, 10))
        {
            if (menuActive == JOUER)
            {
                delete(titre);
                delete(texteJouer);
                delete(texteQuitter);
                C_Niveau niveau(1);
                niveau.playLevel();
            }
            else
            {
                delete(titre);
                delete(texteJouer);
                delete(texteQuitter);
                C_ConfigInit::kill();
                exit(EXIT_SUCCESS);
            }
        }

        /// Affichage :
        SDL_RenderClear(Window->getRenderer());
        SDL_RenderCopy(Window->getRenderer(), ManagerImages->getImage(C_ManagerImages::I_BG, 0)->getTexture(), NULL, &posBackground);
        SDL_RenderCopy(Window->getRenderer(), titre->getTexture(), NULL, &posTitre);
        SDL_RenderCopy(Window->getRenderer(), texteJouer->getTexture(), NULL, &posTexteJouer);
        SDL_RenderCopy(Window->getRenderer(), texteQuitter->getTexture(), NULL, &posTexteQuitter);
        SDL_RenderCopy(Window->getRenderer(), ManagerImages->getImage(C_ManagerImages::I_GEN, 0)->getTexture(), NULL, &posCadre);
        SDL_RenderPresent(Window->getRenderer());
    }
}


