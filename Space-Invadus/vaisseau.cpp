#include "vaisseau.hpp"

C_Vaisseau::C_Vaisseau() : C_Unite()
{
    ManagerImages = C_ManagerImages::getInstance();
    quit = false;
    for (int i = 0 ; i < 10 ; i++)
    {
        alien0[i] = NULL;
        alien1[i] = NULL;
        alien2[i] = NULL;
        alien3[i] = NULL;
        alien4[i] = NULL;
        alien5[i] = NULL;
    }
    for (int i = 0 ; i < 3 ; i++)
    {
        mur[i] = NULL;
    }
}

C_Vaisseau::C_Vaisseau(SDL_Texture *image, int w, int h, int vitesse, int tempsAnimeDeath, int frameDeadStart, int frameDeadEnd) : C_Unite(image, w, h, vitesse, tempsAnimeDeath, frameDeadStart, frameDeadEnd)
{
    ManagerImages = C_ManagerImages::getInstance();
    quit = false;
    for (int i = 0 ; i < 10 ; i++)
    {
        alien0[i] = NULL;
        alien1[i] = NULL;
        alien2[i] = NULL;
        alien3[i] = NULL;
        alien4[i] = NULL;
        alien5[i] = NULL;
    }
    for (int i = 0 ; i < 3 ; i++)
    {
        mur[i] = NULL;
    }
}

C_Vaisseau::~C_Vaisseau()
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

void C_Vaisseau::handleEvent(void)
{
    if (!deadStatut)
    {
        if (EventManager->getJoyButtonState(0, 10) || EventManager->getKeyState(SDL_SCANCODE_C))
        {
            if (lasers.size() < 5)
            {
                lasers.push_back(new C_Tir(ManagerImages->getImage(C_ManagerImages::I_TIR, 0)->getTexture(),
                                    position.x + (ManagerImages->getImage(C_ManagerImages::I_HUMAN, 0)->getW() / 9 / 2 - 1), position.y - 6, -10));
                ManagerSounds->getSound(C_ManagerSounds::S_FX, 2)->playSound(C_Sound::C_FX);
            }
        }
    }
    if (!deadStatut)
    {
        if (EventManager->getJoyButtonState(0, 2) || EventManager->getJoyAxisState(0, 0) < -7000 || EventManager->getKeyState(SDL_SCANCODE_LEFT))
        {
            if (position.x - speed <= 0)
            {
                position.x = 0;
            }
            else
            {
                position.x -= speed;
            }
        }
        if (EventManager->getJoyButtonState(0, 3) || EventManager->getJoyAxisState(0, 0) > 7000 || EventManager->getKeyState(SDL_SCANCODE_RIGHT))
        {
            if (position.x <= RES_W - ManagerImages->getImage(C_ManagerImages::I_HUMAN, 0)->getW() / 9)
            {
                position.x += speed;
            }
        }
    }
}

void C_Vaisseau::show(void)
{
    if (deadStatut)
    {
        if (frame <= deadFrameEnd)
        {
            tempsAnim--;
            if (tempsAnim <= 0)
            {
                frame++;
                framePositionRefresh();
                tempsAnim = deathAnimeTime;
            }
            SDL_RenderCopy(Window->getRenderer(), sprite, &frameSelect, &position);
        }
        else
        {
            quit = true;
        }
    }
    else
    {
        SDL_RenderCopy(Window->getRenderer(), sprite, &frameSelect, &position);
    }
}

void C_Vaisseau::showLasers(void)
{
    for (unsigned int i = 0 ; i < lasers.size() ; i++)
    {
        if (lasers[i]->moving())
        {
            lasers[i]->show();
            bool touche = false;
            for (int j = 0 ; j < 10 ; j++)
            {
                if (!alien0[j]->getDeadStatut())
                {
                    if (collisionAABB_AABB(lasers[i]->getPosition(), alien0[j]->getPosition()))
                    {
                        touche = true;
                        alien0[j]->loosePV();
                    }
                }
                if (!alien1[j]->getDeadStatut())
                {
                    if (collisionAABB_AABB(lasers[i]->getPosition(), alien1[j]->getPosition()))
                    {
                        touche = true;
                        alien1[j]->loosePV();
                    }
                }
                if (!alien2[j]->getDeadStatut())
                {
                    if (collisionAABB_AABB(lasers[i]->getPosition(), alien2[j]->getPosition()))
                    {
                        touche = true;
                        alien2[j]->loosePV();
                    }
                }
                if (!alien3[j]->getDeadStatut())
                {
                    if (collisionAABB_AABB(lasers[i]->getPosition(), alien3[j]->getPosition()))
                    {
                        touche = true;
                        alien3[j]->loosePV();
                    }
                }
                if (!alien4[j]->getDeadStatut())
                {
                    if (collisionAABB_AABB(lasers[i]->getPosition(), alien4[j]->getPosition()))
                    {
                        touche = true;
                        alien4[j]->loosePV();
                    }
                }
                if (!alien5[j]->getDeadStatut())
                {
                    if (collisionAABB_AABB(lasers[i]->getPosition(), alien5[j]->getPosition()))
                    {
                        touche = true;
                        alien5[j]->loosePV();
                    }
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

void C_Vaisseau::loosePV(void)
{
    if (!deadStatut)
    {
        pv--;
        if (pv == 0)
        {
            ManagerSounds->getSound(C_ManagerSounds::S_FX, 1)->playSound(C_Sound::C_FX);
            dead();
        }
    }
}

void C_Vaisseau::updateCollisionCord(C_Unite **alien0Tab, C_Unite **alien1Tab, C_Unite **alien2Tab, C_Unite **alien3Tab, C_Unite **alien4Tab, C_Unite **alien5Tab, C_Mur **murTab)
{
    for (int i = 0 ; i < 10 ; i++)
    {
        alien0[i] = alien0Tab[i];
        alien1[i] = alien1Tab[i];
        alien2[i] = alien2Tab[i];
        alien3[i] = alien3Tab[i];
        alien4[i] = alien4Tab[i];
        alien5[i] = alien5Tab[i];
    }
    for (int i = 0 ; i < 3 ; i++)
    {
        mur[i] = murTab[i];
    }
}

bool C_Vaisseau::getQuit(void)
{
    return quit;
}
