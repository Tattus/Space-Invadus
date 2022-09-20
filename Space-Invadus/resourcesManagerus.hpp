/// Defines de parametrage -- Décommenter la ligne adéquate.
#define DEF_RCFMODCORE
#define DEF_RCSDL2
#define DEF_RCSDL2IMAGE
#define DEF_RCSDL2TTF
/// ----------------------

#ifndef DEF_RESOURCESMANAGERUS
#define DEF_RESOURCESMANAGERUS

/// Includes :
#ifdef DEF_RCFMODCORE
    #include <FMOD/fmod.hpp>
#endif // DEF_RCFMODCORE
#ifdef DEF_RCSDL2
    #include <SDL2/SDL.h>
#endif // DEF_RCSDL2
#ifdef DEF_RCSDL2IMAGE
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
#endif // DEF_RCSDL2IMAGE
#ifdef DEF_RCSDL2TTF
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_ttf.h>
#endif // DEF_RCSDL2TTF

#include <dirent.h>
#include <string.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstddef>
#include <string>

using namespace std;

/// Classe :
class C_ResourcesManager
{
    public:
        /* Méthodes */
        static C_ResourcesManager *getInstance(void);
        static C_ResourcesManager *getInstance(string rcContainer, string rcPrefix);
        static void kill(void);
        //-------------------
        bool setRcContainer(string rcContainer); // Permet d'indiquer le conteneur de ressources.
        bool setRcPrefix(string rcPrefix); // Permet de définir un préfixe.
        // closeRcFile // Supprime la ressource résiduelle indiquée ou toutes les ressources.
        void closeRcFile(void);
        void closeRcFile(string rcFile);
        int getErrorCode(void); // Permet d'obtenir le dernier code d'erreur.
        string getRcFile(string a_pResName); // Charge un fichier texte et renvoie le texte de ce dernier.
        #ifdef DEF_RCFMODCORE
            FMOD_RESULT FMOD_System_CreateRcSound(FMOD_SYSTEM *a_system, string a_rcname, FMOD_MODE a_mode, FMOD_CREATESOUNDEXINFO *a_finfo, FMOD_SOUND **a_ppsound); // Charge un son provenant du conteneur de ressources via FMOD Studio Low. Elle renvoie FMOD_RESULT.
            FMOD_RESULT FMOD_System_CreateRcSoundNoDel(FMOD_SYSTEM *a_system, string a_rcname, FMOD_MODE a_mode, FMOD_CREATESOUNDEXINFO *a_finfo, FMOD_SOUND **a_ppsound); // Charge un son provenant du conteneur de ressources via FMOD Studio Low. Elle renvoie FMOD_RESULT. La fonction ne supprime pas le fichier temporaire créé pour la lecture.
        #endif // DEF_RCFMODCORE
        #ifdef DEF_RCSDL2TTF
            TTF_Font *TTF_OpenRcFontNoDel(string a_FontName, int ptsize); // Charge une police provenant du conteneur de ressources via SDL_TTF. Elle renvoie la police chargée.
        #endif // DEF_RCSDL2TTF
        #ifdef DEF_RCSDL2IMAGE
            SDL_Surface *IMG_RcLoad(string a_ImgName); // Charge une image provenant du conteneur de ressources via SDL2_image. Elle renvoie l'image chargée.
        #endif // DEF_RCSDL2IMAGE
        #ifdef DEF_RCSDL2
            SDL_Surface *LoadRcBitmap(string a_BmpName); // Charge une image provenant du conteneur de ressources au format BMP par la SDL2. Elle renvoie l'image chargée.
        #endif // DEF_RCSDL2
    protected:
    private:
        /* Enumérations */
        enum ErrorCode // Liste des codes d'erreurs
        {
            NO_ERROR = 0,
            RC_CONTAINER_NAME_TOO_LONG,
            RC_PREFIX_TOO_LONG,
            RC_CONTAINER_UNKNOWN,
            RC_CONTAINER_EMPTY,
            RC_FILE_NOT_FOUND
        };
        /* Méthodes */
        // Constructeur //
        C_ResourcesManager();
        C_ResourcesManager(string rcContainer, string rcPrefix);
        ~C_ResourcesManager();
        //------------------------------
        int bIsRcNameFound(FILE *fp, const char *a_pResourceName, int *a_nRcOffset, int *a_nRcSize, int a_nOrder); // Fonction qui va rechercher dans le fichier RC si une ressource existe.
        string *getTempResFile(string a_pResName, int *a_pnSize, int *a_pnOffset); // Fonction qui va creer le fichier temporaire de la ressource.
        int freadRcCrypted(unsigned char *a_buffer, int a_size, int a_nbElem, FILE *a_fp); // Fonction qui lit une ressource crypté.
        /* Variables */
        int myErrorCode;
        string myRcContainer;
        string myRcPrefix;
        string  myFileName;
        bool isCrypted;
};

#endif // DEF_RESOURCESMANAGERUS
