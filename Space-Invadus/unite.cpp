#include "unite.hpp"

C_Unite::C_Unite()
{
    EventManager = C_EventManager::getInstance();
    Window = C_Window::getInstance();
    ManagerSounds = C_ManagerSounds::getInstance();
    sprite = NULL;
    position.x = 0;
    position.y = 0;
    position.w = 0;
    position.h = 0;
    frameSelect.x = 0;
    frameSelect.y = 0;
    frameSelect.w = 0;
    frameSelect.h = 0;
    speed = 0;
    frame = 0;
    deathAnimeTime = 0;
    deadFrameStart = 0;
    deadFrameEnd = 0;
    tempsAnim = 0;
    deadStatut = false;
    pv = 1;
}

C_Unite::C_Unite(SDL_Texture *image, int w, int h, int vitesse, int tempsAnimeDeath, int frameDeadStart, int frameDeadEnd)
{
    EventManager = C_EventManager::getInstance();
    Window = C_Window::getInstance();
    ManagerSounds = C_ManagerSounds::getInstance();
    sprite = image;
    position.x = 0;
    position.y = 0;
    position.w = w;
    position.h = h;
    frameSelect.x = 0;
    frameSelect.y = 0;
    frameSelect.w = w;
    frameSelect.h = h;
    speed = vitesse;
    frame = 0;
    deathAnimeTime = tempsAnimeDeath;
    deadFrameStart = frameDeadStart;
    deadFrameEnd = frameDeadEnd;
    tempsAnim = 0;
    deadStatut = false;
    pv = 1;
}

C_Unite::~C_Unite()
{

}

void C_Unite::setSprite(SDL_Texture *image)
{
    if (sprite == NULL)
    {
        sprite = image;
    }
}

void C_Unite::setFrameSize(int w, int h)
{
    position.w = w;
    position.h = h;
    frameSelect.w = w;
    frameSelect.h = h;
}

void C_Unite::setStartPosition(int x, int y)
{
    position.x = x;
    position.y = y;
}

void C_Unite::setSpeed(int vitesse)
{
    speed = vitesse;
}

void C_Unite::setPV(int hp)
{
    pv = hp;
}

void C_Unite::setTimeDeathAnime(int time)
{
    deathAnimeTime = time;
}

void C_Unite::setDeadSprite(int frameDeadStart, int frameDeadEnd)
{
    deadFrameStart = frameDeadStart;
    deadFrameEnd = frameDeadEnd;
}

SDL_Rect C_Unite::getPosition(void)
{
    SDL_Rect deadpos = {0, 0, 0, 0};
    if (!deadStatut)
    {
        return position;
    }
    return deadpos;
}

bool C_Unite::getDeadStatut(void)
{
    return deadStatut;
}

void C_Unite::show(void)
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
    }
    else
    {
        SDL_RenderCopy(Window->getRenderer(), sprite, &frameSelect, &position);
    }
}

void C_Unite::loosePV(void)
{
    if (!deadStatut)
    {
        pv--;
        if (pv == 0)
        {
            ManagerSounds->getSound(C_ManagerSounds::S_FX, 0)->playSound(C_Sound::C_FX);
            dead();
        }
    }
}

void C_Unite::framePositionRefresh(void)
{
    frameSelect.x = frameSelect.w * frame;
}

void C_Unite::dead(void)
{
    deadStatut = true;
    frame = deadFrameStart;
    framePositionRefresh();
}
