/* datusManagerus.hpp
   ------------------

   Créé par : Tattus
   le : 01/05/2015

   Modifié le : 19/10/2016
*/
#ifndef DEF_DATUSMANAGERUS
#define DEF_DATUSMANAGERUS

using namespace std;

/// Includes :
#include <iostream>
#include <cstddef>
#include <string>
#include <ctime>
#include <stdarg.h>

/// Classe :
class C_DateManager
{
    public:
        /* Méthodes */
        C_DateManager();
        ~C_DateManager();
        void setGlobalFormat(string globalFormat); // Permet d'indiquer le format que l'ont veut récuperer. Mettre des * pour les éléments de dates (Exemple *-*-* pour avoir un 2015-05-01).
        /* setFormat
            Permet d'indiquer les éléments que l'on désire avoir dans la date récupérée. Les éléments sont les caractères tirés de strftime().
            Le premier arguments correspond au  nombre d'éléments que l'on veut indiquer.
            On peut passer au maximum 100 éléments en arguments.
            Les éléments doivent être de type char.
            Exemple : pour avoir l'année au format "2015", pour strftime, on utilise %Y. Ici l'élément est Y.
            La méthode renvoie true s'il n'y a pas eu d'erreur et false s'il y a eu une erreur. */
        bool setFormat(int nbElements, ...);
        string getDate(void); // Méthode qui renvoie la date sous le format globale indiqué.
        int getErrorCode(void); // Méthode qui renvoie le code d'erreur.
    protected:
    private:
        /* Enumérations */
        enum ErrorCode // Liste des codes d'erreurs
        {
            NO_ERROR = 0,
            NB_ELEMENTS_INCORRECT
        };
        /* Variables */
        int myErrorCode;
        string myGlobalFormat;
        string myDate;
        int myNumberElements;
};

#endif // DEF_DATUSMANAGERUS
