#ifndef DEF_EVENTUSMANAGERUS
#define DEF_EVENTUSMANAGERUS

/// Includes :
#include <iostream>
#include <SDL2/SDL.h>
#include "parametrage.hpp"
#ifdef PARAM_SDL_JOYSTICK
    #include <vector>
    #include "managerJoystick.hpp"
#endif

using namespace std;

/// Classe :
class C_EventManager
{
    public:
        /* Méthodes */
        static C_EventManager *getInstance(void);
        static void kill(void);
        //------------------
        void updateEvents(void); // Méthode qui met la liste d'évènements à jour.
        bool quit(void); // Méthode qui indique si on quitte la boucle (evenement de la fenetre). True = quitter.
        void setRepeatKeyButton(bool statut); // Méthode qui défini si les toutes les touches du clavier sont répétées ou non.
        void setRepeatKeyButton(bool statut, SDL_Scancode key); // Méthode qui défini si la touche indiquée du clavier est répétée ou non.
        void setRepeatMouseButton(bool statut); // Méthode qui défini si les boutons de la souris sont répétées ou non.
        void setRepeatMouseButton(bool statut, Uint8 button); // Méthode qui défini si le bouton indiqué de la souris est répété ou non.
        bool getKeyState(SDL_Scancode key); // Méthode qui renvoie le statut d'une touche du clavier. True = touche enfoncée.
        bool getMouseButtonState(Uint8 button); // Méthode qui renvoie le statut d'un bouton de la souris. True = bouton enfoncé.
        bool mouseMoving(void); // Méthode qui indique si la position de la souris a changée. True = position changée.
        int getMouseX(void); // Méthode qui permet d'obtenir la position X de la souris.
        int getMouseY(void); // Méthode qui permet d'obtenir la position Y de la souris.
        int getMouseRelX(void); // Méthode qui permet d'obtenir la position X Relative de la souris.
        int getMouseRelY(void); // Méthode qui permet d'obtenir la position Y relative de la souris.
        void showCursor(bool state); // Méthode qui permet de montrer ou cacher le curseur de la souris.
        void captureCursor(bool state); // Permet d'activer le mode relatif de la souris.
        #ifdef PARAM_SDL_JOYSTICK
            void setRepeatJoystickButton(bool statut); // Méthode qui défini si les boutons du joystick sont répétées ou non.
            void setRepeatJoystickButton(bool statut, unsigned int button); // Méthode qui défini si le bouton du joystick indiqué est répété ou non.
            bool getJoyButtonState(int joystick, unsigned int button); // Méthode qui renvoie le statut d'un bouton du joystick. True = touche enfoncée.
            int getJoyAxisState(int joystick, unsigned int axis); // Méthode qui renvoie la valeur d'un axe du joystick.
        #endif
    protected:
    private:
        /* Méthodes */
        C_EventManager();
        ~C_EventManager();
        /* Variables */
        SDL_Event myEvent;
        const Uint8* keyboardState;
        Uint32 mouseState;
        bool repeatKeyButton[SDL_NUM_SCANCODES];
        bool myKeyButton[SDL_NUM_SCANCODES];
        bool myKeyButtonOff[SDL_NUM_SCANCODES];
        bool repeatMouseButton[6];
        bool myMouseButton[6];
        bool myMouseButtonOff[6];
        int myMouseX;
        int myMouseY;
        int myMouseRelX;
        int myMouseRelY;
        bool myQuit;
        #ifdef PARAM_SDL_JOYSTICK
            C_ManagerJoystick *ManagerJoystick;
            bool repeatJoyButton[30];
            vector< vector<bool> > myJoyButtonOff;
            vector< vector<bool> > myJoyButton;
            vector< vector<int> > myJoyAxis;
        #endif
};

#endif // DEF_EVENTUSMANAGERUS
