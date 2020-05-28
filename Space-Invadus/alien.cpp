/* alien.cpp
   ---------------

   Créé par : Tattus
   le : 25/10/2016

   Modifié le : 05/11/2016
*/
#include "alien.hpp"

C_Alien::C_Alien() : C_Unite()
{
    ManagerImages = C_ManagerImages::getInstance();
    lvl = 0;
    firstLine = false;
    animeDuration = 0;
    nbFrameAnimation = 0;
    frameStatut = 0;
    spaceShipCoord = NULL;
    for (int i = 0 ; i < 3 ; i++)
    {
        mur[i] = NULL;
    }
    delayMoveTotal = 0;
    delayMove = 0;
}

C_Alien::C_Alien(SDL_Texture *image, int w, int h, int vitesse, int dureeAnimation, int nbFrameAnime, int tempsAnimeDeath, int frameDeadStart, int frameDeadEnd) : C_Unite(image, w, h, vitesse, tempsAnimeDeath, frameDeadStart, frameDeadEnd)
{
    ManagerImages = C_ManagerImages::getInstance();
    lvl = 0;
    firstLine = false;
    animeDuration = dureeAnimation;
    nbFrameAnimation = nbFrameAnime;
    frameStatut = 0;
    spaceShipCoord = NULL;
    for (int i = 0 ; i < 3 ; i++)
    {
        mur[i] = NULL;
    }
    delayMoveTotal = 80 / vitesse;
    delayMove = 0;
}

C_Alien::~C_Alien()
{
    for (unsigned int i = 0 ; i < lasers.size() ; i++)
    {
        if (lasers[i] != NULL)
        {
            delete(lasers[i]);
            lasers[i] = NULL;
        }
    }
}

void C_Alien::setLvl(int niveau)
{
    lvl = niveau;
}

void C_Alien::setAnimeDuration(int dureeAnimation)
{
    animeDuration = dureeAnimation;
}

void C_Alien::setNbFrameAnimation(int nb)
{
    nbFrameAnimation = nb;
}

void C_Alien::setFirstLine(bool statut)
{
    firstLine = statut;
}

bool C_Alien::getFirstLine(void)
{
    return firstLine;
}

void C_Alien::shoot(void)
{
    if (!deadStatut && firstLine)
    {
        if (lasers.size() < 1)
        {
            if (rand() % (300 - lvl * 25) == 1)
            {
                lasers.push_back(new C_Tir(ManagerImages->getImage(C_ManagerImages::I_TIR, 1)->getTexture(),
                            position.x + (ManagerImages->getImage(C_ManagerImages::I_ALIEN, lvl)->getW() / 9 / 2 - 1),
                            position.y + ManagerImages->getImage(C_ManagerImages::I_ALIEN, lvl)->getH(), 10));
                ManagerSounds->getSound(C_ManagerSounds::S_FX, 3)->playSound(C_Sound::C_FX);
            }
        }
    }
}

void C_Alien::showLasers(void)
{
    for (unsigned int i = 0 ; i < lasers.size() ; i++)
    {
        if (lasers[i]->moving())
        {
            lasers[i]->show();
            bool touche = false;

            if (!spaceShipCoord->getDeadStatut())
            {
                if (collisionAABB_AABB(lasers[i]->getPosition(), spaceShipCoord->getPosition()))
                {
                    touche = true;
                    spaceShipCoord->loosePV();
                }
            }
            for (int j = 0 ; j < 3 ; j++)
            {
                if (!mur[j]->getDeadStatut())
                {
                    if (collisionAABB_AABB(lasers[i]->getPosition(), mur[j]->getPosition()))
                    {
                        touche = true;
                        mur[j]->loosePV();
                    }
                }
            }
            if (touche)
            {
                delete(lasers[i]);
                lasers.erase(lasers.begin() + i);
            }
        }
        else
        {
            delete(lasers[i]);
            lasers.erase(lasers.begin() + i);
        }
    }
}

void C_Alien::moving(void)
{

    if (!deadStatut)
    {
        // Animation
        if (frameStatut == F_UP && frame < (nbFrameAnimation - 1))
        {
            tempsAnim--;
            if (tempsAnim <= 0)
            {
                frame++;
                framePositionRefresh();
                tempsAnim = animeDuration;
            }
        }
        else if (frameStatut == F_UP && frame == (nbFrameAnimation - 1))
        {
            tempsAnim--;
            if (tempsAnim <= 0)
            {
                frame--;
                framePositionRefresh();
                frameStatut = F_DOWN;
                tempsAnim = animeDuration;
            }
        }
        else if (frameStatut == F_DOWN && frame > 0)
        {
            tempsAnim--;
            if (tempsAnim <= 0)
            {
                frame--;
                framePositionRefresh();
                tempsAnim = animeDuration;
            }
        }
        else if (frameStatut == F_DOWN && frame == 0)
        {
            tempsAnim--;
            if (tempsAnim <= 0)
            {
                frame++;
                framePositionRefresh();
                frameStatut = F_UP;
                tempsAnim = animeDuration;
            }
        }
        // Mouvement
        if (delayMove < delayMoveTotal)
        {
            delayMove++;
            position.x += speed;
        }
        else if (delayMove < delayMoveTotal + delayMoveTotal / 5)
        {
            delayMove++;
            position.y += speed;
        }
        else if (delayMove < delayMoveTotal * 2 + delayMoveTotal / 5)
        {
            delayMove++;
            position.x -= speed;
        }
        else if (delayMove < delayMoveTotal * 2 + delayMoveTotal / 5 * 2)
        {
            delayMove++;
            position.y += speed;
        }
        else
        {
            delayMove = 0;
        }
    }
}

void C_Alien::updateCollisionCord(C_Vaisseau *spaceShip, C_Mur **murTab)
{
    spaceShipCoord = spaceShip;
    for (int i = 0 ; i < 3 ; i++)
    {
        mur[i] = murTab[i];
    }
}
