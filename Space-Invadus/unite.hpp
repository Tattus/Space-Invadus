/* unite.hpp
   ---------------

   Créé par : Tattus
   le : 25/10/2016

   Modifié le : 05/11/2016
*/
#ifndef DEF_UNITE
#define DEF_UNITE

using namespace std;

/// Includes :
#include <iostream>
#include <SDL2/SDL.h>
#include <FMOD/fmod.h>
#include "eventusManagerus.hpp"
#include "window.hpp"
#include "managerSounds.hpp"

/// Classe :
class C_Unite
{
    public:
        /* Méthodes */
        C_Unite();
        C_Unite(SDL_Texture *image, int w, int h, int vitesse, int tempsAnimeDeath, int frameDeadStart, int frameDeadEnd);
        ~C_Unite();
        void setSprite(SDL_Texture *image);
        void setFrameSize(int w, int h);
        void setStartPosition(int x, int y);
        void setSpeed(int vitesse);
        void setPV(int hp);
        void setTimeDeathAnime(int time);
        void setDeadSprite(int frameDeadStart, int frameDeadEnd);
        SDL_Rect getPosition(void);
        bool getDeadStatut(void);
        void show(void);
        void loosePV(void);
    protected:
        /* Méthodes */
        void framePositionRefresh(void);
        void dead(void);
        /* Attributs */
        C_EventManager *EventManager;
        C_Window *Window;
        C_ManagerSounds *ManagerSounds;
        SDL_Texture *sprite;
        SDL_Rect position;
        SDL_Rect frameSelect;
        int speed;
        int frame;
        int deadFrameStart;
        int deadFrameEnd;
        int tempsAnim;
        int deathAnimeTime;
        bool deadStatut;
        int pv;
    private:
};

#endif // DEF_UNITE
