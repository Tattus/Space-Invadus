#include "menuWin.hpp"

C_MenuWin::C_MenuWin()
{
    EventManager = C_EventManager::getInstance();
    ManagerImages = C_ManagerImages::getInstance();
    ManagerFonts = C_ManagerFonts::getInstance();
    Window = C_Window::getInstance();
    numLvl = 1;
}

C_MenuWin::C_MenuWin(int lvl)
{
    EventManager = C_EventManager::getInstance();
    ManagerImages = C_ManagerImages::getInstance();
    ManagerFonts = C_ManagerFonts::getInstance();
    Window = C_Window::getInstance();
    numLvl = lvl;
}

C_MenuWin::~C_MenuWin()
{

}

void C_MenuWin::launchMenu(void)
{
    // Ressources :
    ManagerFonts->setColorFont(C_ManagerFonts::F_REGULAR, 0, 255, 255, 255, 255);
    ManagerFonts->setColorFont(C_ManagerFonts::F_BOLD, 0, 255, 255, 255, 255);
    C_Image *background = NULL, *titre = NULL, *texteVictoire = NULL;
    background = new C_Image();
    if (!background->loadTexturefromWindow(Window))
    {
        delete(background);
        C_ConfigInit::kill();
        exit(EXIT_FAILURE);
    }
    titre = new C_Image();
    if (!titre->loadTextureFromTextBlended("Space Invadus", Window, ManagerFonts->getFont(C_ManagerFonts::F_BOLD, 0)))
    {
        delete(background);
        delete(titre);
        C_ConfigInit::kill();
        exit(EXIT_FAILURE);
    }
    texteVictoire = new C_Image();
    switch (C_ConfigInit::getLanguage())
    {
        case C_ConfigInit::FRA:
            if (numLvl == 4)
            {
                if (!texteVictoire->loadTextureFromTextBlended("Victoire ! Vous avez fini le jeu !", Window, ManagerFonts->getFont(C_ManagerFonts::F_REGULAR, 0)))
                {
                    delete(background);
                    delete(titre);
                    delete(texteVictoire);
                    C_ConfigInit::kill();
                    exit(EXIT_FAILURE);
                }
            }
            else
            {
                if (!texteVictoire->loadTextureFromTextBlended("Victoire !", Window, ManagerFonts->getFont(C_ManagerFonts::F_REGULAR, 0)))
                {
                    delete(background);
                    delete(titre);
                    delete(texteVictoire);
                    C_ConfigInit::kill();
                    exit(EXIT_FAILURE);
                }
            }
            break;
        case C_ConfigInit::ENG:
            if (numLvl == 4)
            {
                if (!texteVictoire->loadTextureFromTextBlended("Victory ! Game completed !", Window, ManagerFonts->getFont(C_ManagerFonts::F_REGULAR, 0)))
                {
                    delete(background);
                    delete(titre);
                    delete(texteVictoire);
                    C_ConfigInit::kill();
                    exit(EXIT_FAILURE);
                }
            }
            else
            {
                if (!texteVictoire->loadTextureFromTextBlended("Victory !", Window, ManagerFonts->getFont(C_ManagerFonts::F_REGULAR, 0)))
                {
                    delete(background);
                    delete(titre);
                    delete(texteVictoire);
                    C_ConfigInit::kill();
                    exit(EXIT_FAILURE);
                }
            }
            break;
        default:
            break;
    }
    SDL_Rect posBackground = {0, 0, ManagerImages->getImage(C_ManagerImages::I_BG, 0)->getW(), ManagerImages->getImage(C_ManagerImages::I_BG, 0)->getH()};
    SDL_Rect posBackgroundTexte = {RES_W / 2 - ManagerImages->getImage(C_ManagerImages::I_GEN, 1)->getW() / 2, 140,
                                    ManagerImages->getImage(C_ManagerImages::I_GEN, 1)->getW(), ManagerImages->getImage(C_ManagerImages::I_GEN, 1)->getH()};
    SDL_Rect posTitre = {RES_W / 2 - titre->getW() / 2, 150, titre->getW(), titre->getH()};
    SDL_Rect posTexteVictoire = {RES_W / 2 - texteVictoire->getW() / 2, 250, texteVictoire->getW(), texteVictoire->getH()};

    // Boucle Principale :
    while(true)
    {
        /// Contrôles
        EventManager->updateEvents();

        if (EventManager->quit())
        {
            delete(background);
            delete(titre);
            delete(texteVictoire);
            C_ConfigInit::kill();
            exit(EXIT_SUCCESS);
        }
        if (EventManager->getKeyState(SDL_SCANCODE_RETURN) || EventManager->getJoyButtonState(0, 10))
        {
            delete(background);
            delete(titre);
            delete(texteVictoire);
            if (numLvl < 4)
            {
                C_Niveau niveau(numLvl + 1);
                niveau.playLevel();
            }
            else
            {
                C_MenuPrincipale menuPrincipale;
                menuPrincipale.launchMenu();
            }

        }

        /// Affichage :
        SDL_RenderClear(Window->getRenderer());
        SDL_RenderCopy(Window->getRenderer(), background->getTexture(), NULL, &posBackground);
        SDL_RenderCopy(Window->getRenderer(), ManagerImages->getImage(C_ManagerImages::I_GEN, 1)->getTexture(), NULL, &posBackgroundTexte);
        SDL_RenderCopy(Window->getRenderer(), titre->getTexture(), NULL, &posTitre);
        SDL_RenderCopy(Window->getRenderer(), texteVictoire->getTexture(), NULL, &posTexteVictoire);
        SDL_RenderPresent(Window->getRenderer());
    }
}
