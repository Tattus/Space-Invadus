/* errorusManagerus.hpp
   --------------------

   Créé par : Tattus
   le : 30/04/2015

   Modifié le : 20/10/2016
   --------------------
   Nécessite datusManagerus.cpp, datusManagerus.hpp, filusManagerus.cpp et filusManagerus.hpp
*/
#ifndef DEF_ERRORUSMANAGERUS
#define DEF_ERRORUSMANAGERUS

/// Defines de l'OS -- Décommenter la ligne adéquate.
#define ERRORUS_WINDOWS
//#define ERRORUS_LINUX
//#define ERRORUS_MAC
/// ----------------------

/// Includes :
#include <iostream>
#include <string>
#include <fstream>
#include "datusManagerus.hpp"
#include "filusManagerus.hpp"

using namespace std;

/// Classe :
class C_ErrorManager
{
    public:
        /* Enumérations : */
        enum TypeError // Liste des codes d'erreurs
        {
            ERROR_STD = 1,
            ERROR_RC_LOADUS,
            ERROR_RESOURCES_MANAGERUS,
            ERROR_DATUS_MANAGERUS,
            ERROR_FILUS_MANAGERUS,
            ERROR_SDL,
            ERROR_SDLTTF,
            ERROR_SDLIMG,
            ERROR_SDLNET,
            ERROR_SDLMIX,
            ERROR_FMOD,
            ERROR_XML
        };
        /* Méthodes */
        static C_ErrorManager *getInstance(void);
        static void kill(void);
        //------------------
        // errorCode() // Méthode qui permet d'indiquer le code et le type de l'erreur et qui appelle la rédaction de cette dernière.
        void errorCode(int errorCode, int errorType);
        void errorCode(string errorCode, int errorType);
        void errorCode(int errorCode, int errorType, int errorCode2, int errorType2);
        void errorCode(string errorCode, int errorType, int errorCode2, int errorType2);
        void errorCode(int errorCode, int errorType, string errorCode2, int errorType2);
        void errorCode(string errorCode, int errorType, string errorCode2, int errorType2);
    protected:
    private:
        /* Méthodes */
        C_ErrorManager();
        virtual ~C_ErrorManager();
        //-------------------------
        void writeErrorFile(void); // Méthode qui rédige le fichier d'erreur.
        string enteteError(void); // Méthode qui indique l'entête de l'erreur.
        void textError(void); // Méthode qui indique le texte de l'erreur.
        /* Variables */
        int myErrorType;
        int myErrorCode;
        bool errorIsText;
        string myErrorText;
};

#endif // DEF_ERRORUSMANAGERUS
