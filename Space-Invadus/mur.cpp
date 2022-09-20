#include "mur.hpp"

C_Mur::C_Mur() : C_Unite()
{
    setPV(3);
}

C_Mur::C_Mur(SDL_Texture *image, int w, int h, int vitesse, int tempsAnimeDeath, int frameDeadStart, int frameDeadEnd) : C_Unite(image, w, h, vitesse, tempsAnimeDeath, frameDeadStart, frameDeadEnd)
{
    setPV(3);
}

C_Mur::~C_Mur()
{

}

void C_Mur::loosePV(void)
{
    if (!deadStatut)
    {
        pv--;
        ManagerSounds->getSound(C_ManagerSounds::S_FX, 4)->playSound(C_Sound::C_FX);
        frame++;
        framePositionRefresh();
        if (pv == 0)
        {
            dead();
        }
        else if (pv == 1)
        {
            frameSelect.y = 13;
            frameSelect.h = 16;
            position.y += 13;
            position.h = 16;
        }
    }
}
