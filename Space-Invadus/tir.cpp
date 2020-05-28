/* tir.cpp
   ---------------

   Créé par : Tattus
   le : 27/10/2016

   Modifié le : 27/10/2016
*/
#include "tir.hpp"

C_Tir::C_Tir() : C_Unite()
{

}

C_Tir::C_Tir(SDL_Texture *image, int x, int y, int vitesse) : C_Unite()
{
    this->setSprite(image);
    this->setStartPosition(x, y);
    this->setFrameSize(2, 6);
    speed = vitesse;
}

C_Tir::~C_Tir()
{

}

bool C_Tir::moving(void)
{
    position.y += speed;
    if (position.y <= -5 || position.y >= 806)
    {
        return false;
    }
    return true;
}
