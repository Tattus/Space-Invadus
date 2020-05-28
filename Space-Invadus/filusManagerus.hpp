/* filusManagerus.hpp
   ------------------

   Créé par : Tattus
   le : 02/05/2015

   Modifié le : 16/04/2017
*/
#ifndef DEF_FILUSMANAGERUS
#define DEF_FILUSMANAGERUS

using namespace std;

/// Defines de l'OS -- Décommenter la ligne adéquate.
#define FILUS_WINDOWS
//#define FILUS_LINUX
//#define FILUS_MAC
/// ----------------------

/// Includes :
#include <dirent.h>
#ifdef FILUS_LINUX
    #include <sys/stat.h>
#endif
#include <iostream>
#include <cstddef>
#include <string>
#include <fstream>
#include <cstdlib>

#ifdef FILUS_LINUX
    /// Prototype mkdir :
    int mkdir(const char *path, mode_t mode);
#endif

/// Classe :
class C_FileManager
{
    public:
        /* Méthodes */
        C_FileManager();
        ~C_FileManager();
        void setFilePath(string filePath); // Permet d'indiquer le chemin et le nom du fichier. -> "./test.txt" = le fichier se trouve dans le dossier parent.
        void setWriteMode(string writeMode); // Permet d'indiquer le mode d'ouverture (a / w / ab / wb).
        void createDir(string directoryPath); // Permet de créer un dossier.
        // writeFile() // Permet d'indiquer ce qu'on veut écrire dans le fichier. La méthode renvoie true si elle s'est déroulée avec sucès et false s'il y a eu une erreur.
        bool writeFile(string data);
        bool writeFile(char data);
        bool writeFile(int data);
        bool writeFile(long data);
        bool writeFile(double data);
        template <typename T>
        bool writeObject(T data); // Permet d'enregistrer un objet ou une structure dans un fichier. La méthode renvoie true si elle s'est déroulée avec sucès et false s'il y a eu une erreur.
        bool getEntireFile(string *data); // Récupère tout le contenu d'un fichier dans un string. La méthode renvoie true si elle s'est déroulée avec sucès et false s'il y a eu une erreur.
        bool readLine(string *data, int numLine); // Récupère le contenu de la ligne indiqué dans un string. La méthode renvoie true si elle s'est déroulée avec sucès et false s'il y a eu une erreur.
        bool readLineInt(int *data, int numLine); // Récupère le contenue de la ligne indiqué dans un int. La méthode renvoie true si elle s'est déroulée avec sucès et false s'il y a eu une erreur.
        bool readLineLong(long *data, int numLine); // Récupère le contenue de la ligne indiqué dans un long. La méthode renvoie true si elle s'est déroulée avec sucès et false s'il y a eu une erreur.
        bool readChar(char *data, int numChar); // Récupère le contenu du charactère indiqué dans un char. La méthode renvoie true si elle s'est déroulée avec sucès et false s'il y a eu une erreur.
        bool readCharBinary(char *data, int taille, int position); // Récupère le contenu d'une chaine de caractere enregistré en binaire. La méthode renvoie true si elle s'est déroulée avec sucès et false s'il y a eu une erreur.
        bool readIntBinary(int *data, int position); // Récupère le contenu d'un int enregistré en binaire. La méthode renvoie true si elle s'est déroulée avec sucès et false s'il y a eu une erreur.
        bool readLongBinary(long *data, int position); // Récupère le contenu d'un long caractere enregistré en binaire. La méthode renvoie true si elle s'est déroulée avec sucès et false s'il y a eu une erreur.
        bool readDoubleBinary(double *data, int position); // Récupère le contenu d'un double caractere enregistré en binaire. La méthode renvoie true si elle s'est déroulée avec sucès et false s'il y a eu une erreur.
        template <typename T2>
        bool readObject(T2 *data, int position); // Récupère un objet ou une structure d'un fichier. La méthode renvoie true si elle s'est déroulée avec sucès et false s'il y a eu une erreur.
        int getErrorCode(void); // Permet d'obtenir le dernier code d'erreur.
    protected:
    private:
        /* Enumérations */
        enum ErrorCode // Liste des codes d'erreurs
        {
            NO_ERROR = 0,
            OPEN_FILE_FAILURE,
            LINE_NOT_FOUND,
            CHAR_NOT_FOUND,
            WRONG_WRITE_MODE
        };
        /* Méthodes */
        void dirCreation(string directory); // Méthode qui créé le dossier.
        /* Variables */
        int myErrorCode;
        string myFilePath;
        string myDirPath;
        bool relativePath;
        string myWriteMode;
        int position;
};

/// Méthodes utilisant un template :

template <typename T>
bool C_FileManager::writeObject(T data)
{
    bool returnValue = true;

    createDir(myDirPath);
    if (myWriteMode == "ab" || myWriteMode == "a")
    {
        ofstream fichier(myFilePath.c_str(), ios::app | ios::binary);
        if (fichier)
        {
            fichier.write((char*)&data, sizeof(data));
            fichier.close();
        }
        else
        {
            myErrorCode = OPEN_FILE_FAILURE;
            returnValue = false;
        }
    }
    else if (myWriteMode == "wb" || myWriteMode == "w")
    {
        ofstream fichier(myFilePath.c_str(), ios::trunc | ios::binary);
        if (fichier)
        {
            fichier.write((char*)&data, sizeof(data));
            fichier.close();
        }
        else
        {
            myErrorCode = OPEN_FILE_FAILURE;
            returnValue = false;
        }
    }
    else
    {
        myErrorCode = WRONG_WRITE_MODE;
        returnValue = false;
    }

    return returnValue;
}

template <typename T2>
bool C_FileManager::readObject(T2 *data, int position)
{
    bool returnValue = true;

    ifstream fichier(myFilePath.c_str(), ios::binary);
    if (fichier)
    {
        fichier.seekg(position * sizeof(*data));
        fichier.read((char*)data, sizeof(*data));
        fichier.close();
    }
    else
    {
        myErrorCode = OPEN_FILE_FAILURE;
        returnValue = false;
    }

    return returnValue;
}

#endif // DEF_FILUSMANAGERUS
