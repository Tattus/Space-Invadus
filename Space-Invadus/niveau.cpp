/* niveau.cpp
   ---------------

   Créé par : Tattus
   le : 26/10/2016

   Modifié le : 11/11/2016
*/
#include "niveau.hpp"
C_Niveau::C_Niveau()
{
    EventManager = C_EventManager::getInstance();
    ManagerImages = C_ManagerImages::getInstance();
    Window = C_Window::getInstance();
    numLvl = 0;
}

C_Niveau::C_Niveau(int lvl)
{
    EventManager = C_EventManager::getInstance();
    ManagerImages = C_ManagerImages::getInstance();
    Window = C_Window::getInstance();
    numLvl = lvl;
}

C_Niveau::~C_Niveau()
{

}

void C_Niveau::setLevel(int lvl)
{
    numLvl = lvl;
}

bool C_Niveau::playLevel(void)
{
    // Basics :
    bool pause = false;
    int dureeRendu = 0, debutRendu = 0, dernierRendu = 0;

    // Ressources :
    SDL_Rect posBackground = {0, 0, ManagerImages->getImage(C_ManagerImages::I_BG, 0)->getW(), ManagerImages->getImage(C_ManagerImages::I_BG, 0)->getH()};

    C_Vaisseau *spaceShip = NULL;
    spaceShip = new C_Vaisseau(ManagerImages->getImage(C_ManagerImages::I_HUMAN, 0)->getTexture(), ManagerImages->getImage(C_ManagerImages::I_HUMAN, 0)->getW() / 9,
                               ManagerImages->getImage(C_ManagerImages::I_HUMAN, 0)->getH(), 5, 5, 1, 8);
    spaceShip->setStartPosition(RES_W / 2 - ManagerImages->getImage(C_ManagerImages::I_HUMAN, 0)->getW() / 4 / 2, RES_H - 75);

    C_Mur *mur[3] = {NULL};
    for (int i = 0 ; i < 3 ; i++)
    {
        mur[i] = new C_Mur(ManagerImages->getImage(C_ManagerImages::I_HUMAN, 1)->getTexture(), ManagerImages->getImage(C_ManagerImages::I_HUMAN, 1)->getW() / 3,
                            ManagerImages->getImage(C_ManagerImages::I_HUMAN, 1)->getH(), 0, 0, 3, 3);
    }
    mur[0]->setStartPosition(100, 680);
    mur[1]->setStartPosition(RES_W / 2 - ManagerImages->getImage(C_ManagerImages::I_HUMAN, 1)->getW() / 3 / 2, 680);
    mur[2]->setStartPosition(RES_W - ManagerImages->getImage(C_ManagerImages::I_HUMAN, 1)->getW() / 3 - 100, 680);

    C_Alien *alien0[10] = {NULL}; // Ligne 0
    C_Alien *alien1[10] = {NULL}; // Ligne 1
    C_Alien *alien2[10] = {NULL}; // Ligne 2
    C_Alien *alien3[10] = {NULL}; // Ligne 3
    C_Alien *alien4[10] = {NULL}; // Ligne 4
    C_Alien *alien5[10] = {NULL}; // Ligne 5
    for (int i = 0 ; i < 10 ; i++)
    {
        alien5[i] = new C_Alien(ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getTexture(), ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getW() / 9,
                      ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getH(), numLvl * 1, 10, 3, 3, 3, 8);
        alien5[i]->setStartPosition(25 + i * (ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getW() / 9 + 25),
                                    25);
        alien5[i]->updateCollisionCord(spaceShip, mur);

        alien4[i] = new C_Alien(ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getTexture(), ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getW() / 9,
                      ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getH(), numLvl * 1, 10, 3, 3, 3, 8);
        alien4[i]->setStartPosition(25 + i * (ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getW() / 9 + 25),
                                    (ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getH() + 5) + 25);
        alien4[i]->updateCollisionCord(spaceShip, mur);

        alien3[i] = new C_Alien(ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getTexture(), ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getW() / 9,
                      ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getH(), numLvl * 1, 10, 3, 3, 3, 8);
        alien3[i]->setStartPosition(25 + i * (ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getW() / 9 + 25),
                                    (ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getH() + 5) * 2 + 25);
        alien3[i]->updateCollisionCord(spaceShip, mur);

        alien2[i] = new C_Alien(ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getTexture(), ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getW() / 9,
                      ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getH(), numLvl * 1, 10, 3, 3, 3, 8);
        alien2[i]->setStartPosition(25 + i * (ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getW() / 9 + 25),
                                    (ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getH() + 5) * 3 + 25);
        alien2[i]->updateCollisionCord(spaceShip, mur);

        alien1[i] = new C_Alien(ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getTexture(), ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getW() / 9,
                      ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getH(), numLvl * 1, 10, 3, 3, 3, 8);
        alien1[i]->setStartPosition(25 + i * (ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getW() / 9 + 25),
                                    (ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getH() + 5) * 4 + 25);
        alien1[i]->updateCollisionCord(spaceShip, mur);

        alien0[i] = new C_Alien(ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getTexture(), ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getW() / 9,
                      ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getH(), numLvl * 1, 10, 3, 3, 3, 8);
        alien0[i]->setStartPosition(25 + i * (ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getW() / 9 + 25),
                                    (ManagerImages->getImage(C_ManagerImages::I_ALIEN, numLvl - 1)->getH() + 5) * 5 + 25);
        alien0[i]->updateCollisionCord(spaceShip, mur);
        alien0[i]->setFirstLine(true);
    }

    spaceShip->updateCollisionCord((C_Unite**)alien0, (C_Unite**)alien1, (C_Unite**)alien2, (C_Unite**)alien3, (C_Unite**)alien4, (C_Unite**)alien5, mur);
    // Boucle Principale :
    while(true)
    {
        /// Contrôles
        EventManager->updateEvents();

        if (EventManager->quit())
        {
            for (int i = 0 ; i < 10 ; i++)
            {
                delete(alien0[i]);
                delete(alien1[i]);
                delete(alien2[i]);
                delete(alien3[i]);
                delete(alien4[i]);
                delete(alien5[i]);
            }
            for (int i = 0 ; i < 3 ; i++)
            {
                delete(mur[i]);
            }
            delete(spaceShip);
            C_ConfigInit::kill();
            exit(EXIT_SUCCESS);
        }
        if (EventManager->getKeyState(SDL_SCANCODE_SPACE) || EventManager->getJoyButtonState(0, 4))
        {
            pause = true;
            int dureePause = 0;
            int debutPause = 0;
            int dernierPause = 0;
            while(pause)
            {

                EventManager->updateEvents();
                if (EventManager->quit())
                {
                    for (int i = 0 ; i < 10 ; i++)
                    {
                        delete(alien0[i]);
                        delete(alien1[i]);
                        delete(alien2[i]);
                        delete(alien3[i]);
                        delete(alien4[i]);
                        delete(alien5[i]);
                    }
                    for (int i = 0 ; i < 3 ; i++)
                    {
                        delete(mur[i]);
                    }
                    delete(spaceShip);
                    C_ConfigInit::kill();
                    exit(EXIT_SUCCESS);
                }
                if (EventManager->getKeyState(SDL_SCANCODE_SPACE) || EventManager->getJoyButtonState(0, 4))
                {
                    pause = false;
                }
                SDL_RenderPresent(Window->getRenderer());
                debutPause = SDL_GetTicks();
                dureePause = debutPause - dernierPause;
                if (dureePause < 0)
                {
                    dureePause = 0;
                }
                if(dureePause < 1000 / 30) // pour 30 FPS.
                {
                    SDL_Delay((1000 / 30) - dureePause);
                }
                dernierPause = SDL_GetTicks();
            }
        }
        if (spaceShip->getQuit())
        {
            for (int i = 0 ; i < 10 ; i++)
            {
                delete(alien0[i]);
                delete(alien1[i]);
                delete(alien2[i]);
                delete(alien3[i]);
                delete(alien4[i]);
                delete(alien5[i]);
            }
            for (int i = 0 ; i < 3 ; i++)
            {
                delete(mur[i]);
            }
            delete(spaceShip);
            C_MenuLoose menuLoose(numLvl);
            menuLoose.launchMenu();
        }
        if (win((C_Unite**)alien0, (C_Unite**)alien1, (C_Unite**)alien2, (C_Unite**)alien3, (C_Unite**)alien4, (C_Unite**)alien5))
        {
            for (int i = 0 ; i < 10 ; i++)
            {
                delete(alien0[i]);
                delete(alien1[i]);
                delete(alien2[i]);
                delete(alien3[i]);
                delete(alien4[i]);
                delete(alien5[i]);
            }
            for (int i = 0 ; i < 3 ; i++)
            {
                delete(mur[i]);
            }
            delete(spaceShip);
            C_MenuWin menuWin(numLvl);
            menuWin.launchMenu();
        }

        spaceShip->handleEvent();

        for (int i = 0 ; i < 10 ; i++)
        {
            if (!alien0[i]->getDeadStatut())
            {
                alien0[i]->moving();
                alien0[i]->shoot();
            }
            else
            {
                alien1[i]->setFirstLine(true);
            }
            if (!alien1[i]->getDeadStatut())
            {
                alien1[i]->moving();
                alien1[i]->shoot();
            }
            else
            {
                if (alien1[i]->getFirstLine())
                {
                    alien2[i]->setFirstLine(true);
                }
            }
            if (!alien2[i]->getDeadStatut())
            {
                alien2[i]->moving();
                alien2[i]->shoot();
            }
            else
            {
                if (alien1[i]->getFirstLine() && alien2[i]->getFirstLine())
                {
                    alien3[i]->setFirstLine(true);
                }
            }
            if (!alien3[i]->getDeadStatut())
            {
                alien3[i]->moving();
                alien3[i]->shoot();
            }
            else
            {
                if (alien1[i]->getFirstLine() && alien2[i]->getFirstLine() && alien3[i]->getFirstLine())
                {
                    alien4[i]->setFirstLine(true);
                }
            }
            if (!alien4[i]->getDeadStatut())
            {
                alien4[i]->moving();
                alien4[i]->shoot();
            }
            else
            {
                if (alien1[i]->getFirstLine() && alien2[i]->getFirstLine() && alien3[i]->getFirstLine() && alien4[i]->getFirstLine())
                {
                    alien5[i]->setFirstLine(true);
                }
            }
            if (!alien5[i]->getDeadStatut())
            {
                alien5[i]->moving();
                alien5[i]->shoot();
            }
        }
        for (int i = 0 ; i < 10 ; i++)
        {
            if (looseAlienDown(alien0[i]->getPosition()))
            {
                for (int i = 0 ; i < 10 ; i++)
                {
                    delete(alien0[i]);
                    delete(alien1[i]);
                    delete(alien2[i]);
                    delete(alien3[i]);
                    delete(alien4[i]);
                    delete(alien5[i]);
                }
                for (int i = 0 ; i < 3 ; i++)
                {
                    delete(mur[i]);
                }
                delete(spaceShip);
                C_MenuLoose menuLoose(numLvl);
                menuLoose.launchMenu();
            }
            if (looseAlienDown(alien1[i]->getPosition()))
            {
                for (int i = 0 ; i < 10 ; i++)
                {
                    delete(alien0[i]);
                    delete(alien1[i]);
                    delete(alien2[i]);
                    delete(alien3[i]);
                    delete(alien4[i]);
                    delete(alien5[i]);
                }
                for (int i = 0 ; i < 3 ; i++)
                {
                    delete(mur[i]);
                }
                delete(spaceShip);
                C_MenuLoose menuLoose(numLvl);
                menuLoose.launchMenu();
            }
            if (looseAlienDown(alien2[i]->getPosition()))
            {
                for (int i = 0 ; i < 10 ; i++)
                {
                    delete(alien0[i]);
                    delete(alien1[i]);
                    delete(alien2[i]);
                    delete(alien3[i]);
                    delete(alien4[i]);
                    delete(alien5[i]);
                }
                for (int i = 0 ; i < 3 ; i++)
                {
                    delete(mur[i]);
                }
                delete(spaceShip);
                C_MenuLoose menuLoose(numLvl);
                menuLoose.launchMenu();
            }
            if (looseAlienDown(alien3[i]->getPosition()))
            {
                for (int i = 0 ; i < 10 ; i++)
                {
                    delete(alien0[i]);
                    delete(alien1[i]);
                    delete(alien2[i]);
                    delete(alien3[i]);
                    delete(alien4[i]);
                    delete(alien5[i]);
                }
                for (int i = 0 ; i < 3 ; i++)
                {
                    delete(mur[i]);
                }
                delete(spaceShip);
                C_MenuLoose menuLoose(numLvl);
                menuLoose.launchMenu();
            }
            if (looseAlienDown(alien4[i]->getPosition()))
            {
                for (int i = 0 ; i < 10 ; i++)
                {
                    delete(alien0[i]);
                    delete(alien1[i]);
                    delete(alien2[i]);
                    delete(alien3[i]);
                    delete(alien4[i]);
                    delete(alien5[i]);
                }
                for (int i = 0 ; i < 3 ; i++)
                {
                    delete(mur[i]);
                }
                delete(spaceShip);
                C_MenuLoose menuLoose(numLvl);
                menuLoose.launchMenu();
            }
            if (looseAlienDown(alien5[i]->getPosition()))
            {
                for (int i = 0 ; i < 10 ; i++)
                {
                    delete(alien0[i]);
                    delete(alien1[i]);
                    delete(alien2[i]);
                    delete(alien3[i]);
                    delete(alien4[i]);
                    delete(alien5[i]);
                }
                for (int i = 0 ; i < 3 ; i++)
                {
                    delete(mur[i]);
                }
                delete(spaceShip);
                C_MenuLoose menuLoose(numLvl);
                menuLoose.launchMenu();
            }
        }

        /// Affichage
        SDL_RenderClear(Window->getRenderer());
        SDL_RenderCopy(Window->getRenderer(), ManagerImages->getImage(C_ManagerImages::I_BG, 0)->getTexture(), NULL, &posBackground);
        spaceShip->show();
        spaceShip->showLasers();
        for (int i = 0 ; i < 3 ; i++)
        {
            mur[i]->show();
        }
        for (int i = 0 ; i < 10 ; i++)
        {
            alien0[i]->show();
            alien0[i]->showLasers();
            alien1[i]->show();
            alien1[i]->showLasers();
            alien2[i]->show();
            alien2[i]->showLasers();
            alien3[i]->show();
            alien3[i]->showLasers();
            alien4[i]->show();
            alien4[i]->showLasers();
            alien5[i]->show();
            alien5[i]->showLasers();
        }
        SDL_RenderPresent(Window->getRenderer());

        // Blocage 60 FPS
        debutRendu = SDL_GetTicks();
        dureeRendu = debutRendu - dernierRendu;
        if (dureeRendu < 0)
        {
            dureeRendu = 0;
        }
        if(dureeRendu < 1000 / 50) // pour 50 FPS.
        {
            SDL_Delay((1000 / 50) - dureeRendu);
        }
        dernierRendu = SDL_GetTicks();
    }

    return true;
}

bool C_Niveau::win(C_Unite **alien0, C_Unite **alien1, C_Unite **alien2, C_Unite **alien3, C_Unite **alien4, C_Unite **alien5)
{
    int nbDead = 0;

    for (int i = 0 ; i < 10 ; i++)
    {
        if (alien0[i]->getDeadStatut())
        {
            nbDead++;
        }
    }
    for (int i = 0 ; i < 10 ; i++)
    {
        if (alien1[i]->getDeadStatut())
        {
            nbDead++;
        }
    }
    for (int i = 0 ; i < 10 ; i++)
    {
        if (alien2[i]->getDeadStatut())
        {
            nbDead++;
        }
    }
    for (int i = 0 ; i < 10 ; i++)
    {
        if (alien3[i]->getDeadStatut())
        {
            nbDead++;
        }
    }
    for (int i = 0 ; i < 10 ; i++)
    {
        if (alien4[i]->getDeadStatut())
        {
            nbDead++;
        }
    }
    for (int i = 0 ; i < 10 ; i++)
    {
        if (alien5[i]->getDeadStatut())
        {
            nbDead++;
        }
    }

    if (nbDead == 60)
    {
        return true;
    }
    return false;
}

bool C_Niveau::looseAlienDown(SDL_Rect position)
{
    if (position.y + position.h >= 680)
    {
        return true;
    }
    return false;
}
