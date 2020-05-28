/* collisions.hpp
   --------------

   Créé par Tattus
   le : 21/03/2015

   Modifié le : 23/08/2016
   --------------
   Prototypes et structures des fonction de collisions.cpp
   Nécessite la SDL 2.
*/
#ifndef DEF_COLLISIONS
#define DEF_COLLISIONS

using namespace std;

/// Includes :
#include <iostream>
#include <SDL2/SDL.h>

/// Structures :
typedef struct Cercle Cercle; // Structure d'un cercle.
struct Cercle
{
    int x, y; // Coordonnées du centre.
    int rayon; // Rayon du cercle en px.
    SDL_Rect positionSurface; // Coordonnées de la surface dans laquelle est le cercle.
};

/// Prototypes :
bool collisionPoint_AABB(int point_x, int point_y, SDL_Rect AABB); // Fonction qui gère la collision d'un point sur une surface.
bool collisionAABB_AABB(SDL_Rect AABB1, SDL_Rect AABB2); // Fonction qui gère la collision d'une surface sur une surface (Rectangle et Rectangle).
bool collisionPoint_Cercle(int x, int y, Cercle cercle); // Fonction qui gère la collision d'un point dans un cercle.
bool collisionCercle_Cercle(Cercle cercle1, Cercle cercle2); // Fonction qui gère la collision d'un cercle avec un autre cercle.

#endif // DEF_COLLISIONS
