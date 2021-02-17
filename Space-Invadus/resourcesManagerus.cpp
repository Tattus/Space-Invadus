/* resourcesManagerus.cpp
   ----------------------

   Créé par : Tattus
   le : 03/05/2015

   Modifié le : 15/05/2015
*/
#include "resourcesManagerus.hpp"

static C_ResourcesManager *myInstanceRM = NULL;

C_ResourcesManager::C_ResourcesManager()
{
    myErrorCode = NO_ERROR;
    myFileName = "";
    myRcContainer = "resources.dat";
    myRcPrefix = "rc_";
}

C_ResourcesManager::C_ResourcesManager(string rcContainer, string rcPrefix)
{
    myErrorCode = NO_ERROR;
    myFileName = "";

    if (rcContainer.length() > FILENAME_MAX)
    {
        myRcContainer = "resources.dat";
        myErrorCode = RC_CONTAINER_NAME_TOO_LONG;
    }
    else
    {
       myRcContainer = rcContainer;
    }
    if (rcPrefix.length() > 9)
    {
        myRcPrefix = "rc_";
        myErrorCode = RC_PREFIX_TOO_LONG;
    }
    else
    {
        myRcPrefix = rcPrefix;
    }
}

C_ResourcesManager::~C_ResourcesManager()
{
    //cout << "Destructor Resource Manager" << endl;
}

C_ResourcesManager *C_ResourcesManager::getInstance(void)
{
    if (myInstanceRM == NULL)
    {
        myInstanceRM = new C_ResourcesManager();
    }

    return myInstanceRM;
}

C_ResourcesManager *C_ResourcesManager::getInstance(string rcContainer, string rcPrefix)
{
    if (myInstanceRM == NULL)
    {
        myInstanceRM = new C_ResourcesManager(rcContainer, rcPrefix);
    }

    return myInstanceRM;
}

void C_ResourcesManager::kill(void)
{
    if (myInstanceRM != NULL)
    {
        delete(myInstanceRM);
        myInstanceRM = NULL;
    }
}

bool C_ResourcesManager::setRcContainer(string rcContainer)
{
    bool returnValue = true;

    if (rcContainer.length() > FILENAME_MAX)
    {
        myRcContainer = "resources.dat";
        myErrorCode = RC_CONTAINER_NAME_TOO_LONG;
        returnValue = false;
    }
    else
    {
        myRcContainer = rcContainer;
    }

    return returnValue;
}

bool C_ResourcesManager::setRcPrefix(string rcPrefix)
{
    bool returnValue = true;

    if (rcPrefix.length() > 9)
    {
        myRcPrefix = "rc_";
        myErrorCode = RC_PREFIX_TOO_LONG;
        returnValue = false;
    }
    else
    {
        myRcPrefix = rcPrefix;
    }

    return returnValue;
}

void C_ResourcesManager::closeRcFile(void)
{
    struct dirent *ent = NULL;
    DIR *dir = opendir(".");
    string fileName = "";

    if (dir != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            fileName = ent->d_name;
            if (fileName.compare(0, myRcPrefix.length(), myRcPrefix) == 0)
            {
                remove(fileName.c_str());
            }
        }
    }
}

void C_ResourcesManager::closeRcFile(string rcFile)
{
    string fileName = "";

    fileName = myRcPrefix + rcFile;

    remove(fileName.c_str());
}

int C_ResourcesManager::getErrorCode(void)
{
    return myErrorCode;
}

//**********************************************************************************************************************************
// getRcFile :
//****************
//  cette fonction prend en arguments :
//		le nom d'une ressource contenant un fichier,texte ou binaire . par exemple "monfic.txt".
//		un pointeur sur un int qui sera renvoyé/chargé avec la taille utilisable des données
//   Elle va créer un fichier temporaire "rc_monfic.txt", puis allouer (malloc) une zone de mémoire équivalente à la taille
//   du fichier, puis charger le contenu du fichier temporaire dans cette zone de mémoire allouée, + 1 octet pour un 0x00 à la fin.
//   le fichier temporaire rc_monfichier.txt est immédiatement détruit.
//  La fonction renvoie le contenu dans un string.
//**********************************************************************************************************************************
string C_ResourcesManager::getRcFile(string a_pResName)
{
    char *ptrdata;
	string *tempFileName;
	string contenu;
	int  taille;
	FILE    *fp;

	tempFileName = getTempResFile(a_pResName, &taille, NULL);
	if(!tempFileName)
    {
        return "";
    }
	fp = fopen(tempFileName->c_str(), "rb");
	if(!fp)
    {
        return "";
    }
    ptrdata = (char*)malloc(taille + 1);
	fread((unsigned char *)ptrdata, taille, 1, fp);
	ptrdata[taille] = 0x00;
	fclose(fp);
	remove(tempFileName->c_str());
	contenu = ptrdata;
	free(ptrdata);
	return contenu;
}

#ifdef DEF_RCFMODCORE
FMOD_RESULT C_ResourcesManager::FMOD_System_CreateRcSound(FMOD_SYSTEM *a_system, string a_rcname, FMOD_MODE a_mode, FMOD_CREATESOUNDEXINFO *a_finfo, FMOD_SOUND **a_ppsound)
{
	string *tempFileName;
	FMOD_RESULT	result;

	tempFileName = getTempResFile(a_rcname, NULL, NULL);
	if (!tempFileName)
    {
        return FMOD_ERR_FILE_NOTFOUND;
    }
	result = FMOD_System_CreateSound(a_system, tempFileName->c_str(), a_mode, a_finfo, a_ppsound);
    remove(tempFileName->c_str());
    return result;
}
FMOD_RESULT C_ResourcesManager::FMOD_System_CreateRcSoundNoDel(FMOD_SYSTEM *a_system, string a_rcname, FMOD_MODE a_mode, FMOD_CREATESOUNDEXINFO *a_finfo, FMOD_SOUND **a_ppsound)
{
	string *tempFileName;
	FMOD_RESULT	result;

	tempFileName = getTempResFile(a_rcname, NULL, NULL);
	if (!tempFileName)
    {
        return FMOD_ERR_FILE_NOTFOUND;
    }
	result = FMOD_System_CreateSound(a_system, tempFileName->c_str(), a_mode, a_finfo, a_ppsound);
    remove(tempFileName->c_str());
    return result;
}
#endif //DEF_RCFMODCORE

#ifdef DEF_RCSDL2TTF
TTF_Font *C_ResourcesManager::TTF_OpenRcFontNoDel(string a_FontName, int ptsize)
{
    TTF_Font *fontsToReturn;
	string *tempFileName;

	tempFileName = getTempResFile(a_FontName, NULL, NULL);
	if (!tempFileName)
    {
        return NULL;
    }
	fontsToReturn = TTF_OpenFont(tempFileName->c_str(), ptsize);
	return fontsToReturn;
}
#endif // DEF_RCSDL2FONTS

#ifdef DEF_RCSDL2IMAGE
SDL_Surface *C_ResourcesManager::IMG_RcLoad(string a_ImgName)
{
    SDL_Surface *surfaceToReturn;
	string *tempFileName;

	tempFileName = getTempResFile(a_ImgName, NULL, NULL);
	if (!tempFileName)
    {
        return NULL;
    }
	surfaceToReturn = IMG_Load(tempFileName->c_str());
    remove(tempFileName->c_str());
    return surfaceToReturn;
}
#endif // DEF_RCSDL2IMAGE

#ifdef DEF_RCSDL2
SDL_Surface *C_ResourcesManager::LoadRcBitmap(string a_BmpName)
{
    SDL_Surface *surfaceToReturn;
	string *tempFileName;

	tempFileName = getTempResFile(a_BmpName, NULL, NULL);
	if (!tempFileName)
    {
        return NULL;
    }
    surfaceToReturn = SDL_LoadBMP(tempFileName->c_str());
    remove(tempFileName->c_str());
    return surfaceToReturn;
}
#endif // DEF_RCSDL2

//*******************************************************************************************************************
// fonction: bIsRcNameFound
//    objet: va rechercher dans le fichier RC si une ressource existe.
//        La ressource est connue avec son nom original de fichier, par exemple "monfic.bmp"
//    Arguments:
//        FILE *fp              : Le fichier de ressources doit être ouvert (fopen déjà effectué)
//        char *a_pResourceName : Le nom de la ressource à trouver, par exemple "monfic.bmp"
//        int *a_nRcOffset      : Pointeur sur un int. la fonction mettra dedans l'offset dans le fichier de ressources
//                                  correspondant aux data de la ressource concernée
//        int *a_nRcSize        : Contiendra la taille de la partie data de la ressource si elle est trouvée
//        a_nOrder              : Le numéro d'ordre de la ressource concernée, commence à zéro
//*******************************************************************************************************************
int C_ResourcesManager::bIsRcNameFound(FILE *fp, const char *a_pResourceName, int *a_nRcOffset, int *a_nRcSize, int a_nOrder)
{
    int     offsetRcStruct;  // Contiendra le int qui définit l'offset dans le fichier de ressources pour trouver l'entête de la ressource considérée
    int     resourceSize;    // Contendra le nombre d'octets (la taille) de la ressource
    int     resourceNameLength; // Longeur du nom de la ressource sans le zéro final. par exemple, si c'est toto.bmp, contiendra 8
    char    resourceName[FILENAME_MAX];  //** Buffer qui recevra le nom de la ressource
    int     rc;
    // Se positionner au début du pointeur d'offset dans le fichier de ressources pour ce N° de ressource
    // fseek retourne zéro si c'est ok. Sinon je fais un return( 0 ) pour dire que l'on ne l'a pas trouvé
    //if( fseek( fp, (4+(4*a_nOrder)), SEEK_SET ) ) return( 0 );
    rc = fseek(fp, (4 + (4 * a_nOrder)) + 1, SEEK_SET);
    if (rc != 0) return 0;
    // Lire le déplacement de cette ressource
    rc = freadRcCrypted((unsigned char *)&offsetRcStruct, sizeof(int), 1, fp);
    if (rc != 1) return 0;
    // Se déplacer au début du nom de cette ressource dans le fichier de ressources
    rc = fseek(fp, offsetRcStruct, SEEK_SET);
    if (rc != 0) return 0;
    // Nous pointons maintenant sur la taille des datas de cette structure. La lire
    rc = freadRcCrypted( (unsigned char *)&resourceSize, sizeof(int), 1, fp );
    if (rc != 1) return 0;
    // Lire maintenant la taille du nom de cette ressource
    rc = freadRcCrypted( (unsigned char *)&resourceNameLength, sizeof(int), 1, fp );
    if (rc != 1) return 0;
    if (resourceNameLength >=  (int)(FILENAME_MAX - myRcPrefix.length())) return 0; // - strlen(gs_rcTempPrefix) car je vais préfixer avec "gs_rcTempPrefix" en créant le fichier temporaire
    // Lire maintenant le nom de ectte ressource
    rc = freadRcCrypted((unsigned char *)resourceName, resourceNameLength, 1, fp);
    if (rc != 1) return 0;
    // Mettre un zéro binaire pour terminer le string
    resourceName[resourceNameLength] = 0x00;
    // Comparer avec le nom de ressource demandé
    if (!strcmp(resourceName, a_pResourceName))
    {
        // Oui c'est la bonne ressource
        // Garder le déplacement sur les data de cette ressource
        *a_nRcOffset = ftell(fp);
        *a_nRcSize = resourceSize;
        return 1;
    }
    else
    {
        //** Non, le nom ne correspond pas
        *a_nRcOffset = -1;
        return 0;

    }
    return 1;
}

//***************************************************************************************************************************************************
// getTempResFile :
//********************
//        Fonction interne.
//          Elle va chercher dans le fichier de ressources gs_NomFichierResources et essayer de trouver la ressource dont le nom est dans a_pResName.
//        Arguments:
//          a_pResName  : Nom de la ressource, par exemple mymage.bmp
//          a_pnSize    : Pointeur sur un int, peut être NULL. Si pas NULL, je mets dedans la taille trouvée pour al ressource
//          a_pnOffset  : Pointeur sur un int, offset de la ressource par rapport au début du fichier de ressources. peut être NULL
//
//        Valeurs de retour :
//              NULL        = Ressource non trouvée
//              non NULL    = Nom du fichier temporaire créé (et chargé et non-ouvert) si la ressource est trouvée
//***************************************************************************************************************************************************
string *C_ResourcesManager::getTempResFile(string a_pResName, int *a_pnSize, int *a_pnOffset)
{
    FILE    *fp;
    int     nbFilesInRc;
    int     i;
    int     rcOffset;
    int     bFlagRcFound;
    int     rcSize;
    void    *ptrdata;
	FILE	*fpTemp;

    fp = fopen(myRcContainer.c_str(), "rb");
    if (!fp)
    {
        myErrorCode = RC_CONTAINER_UNKNOWN;
        return NULL;
    }
    // Lire le 1er octet pour savoir si c'est crypté
    isCrypted = 0;
    freadRcCrypted((unsigned char *)&isCrypted, 1, 1, fp);
    // Combien de ressources dans ce fichier de ressources ?
    freadRcCrypted((unsigned char *)&nbFilesInRc, sizeof(int), 1, fp);

    // Si pas de fichiers, RC_FILE_EMPTY
    if (!nbFilesInRc)
    {
        fclose(fp);
        myErrorCode = RC_CONTAINER_EMPTY;
        return NULL;
    }
    // Balayer les noms des ressources
    bFlagRcFound  = 0;
    for (i = 0 ; i < nbFilesInRc ; i++)
    {
         if (bIsRcNameFound(fp, a_pResName.c_str(), &rcOffset, &rcSize, i))
         {
             bFlagRcFound = 1;
             if(a_pnSize)
             {
                 *a_pnSize   = rcSize;
             }
             if(a_pnOffset)
             {
                 *a_pnOffset = rcOffset;
             }
             break;
         }
    }
    if (!bFlagRcFound)
    {
        fclose(fp);
        myErrorCode = RC_FILE_NOT_FOUND;
        return NULL;
    }
    // Ici la ressource a été trouvée, rcOffset est le déplacement dans le fichier de ressources des data de la ressource cherchée
    // En attendant de faire mieux, je vais créer un fichier temporaire pour cette ressource, la charger, puis effacer le fichier
    myFileName = myRcPrefix + a_pResName;
    fpTemp = fopen(myFileName.c_str(), "w+b");
    ptrdata = malloc(rcSize);
    freadRcCrypted((unsigned char *)ptrdata, rcSize, 1, fp);
    fwrite(ptrdata, rcSize, 1, fpTemp);
    fclose(fpTemp);
    fclose(fp);
    free(ptrdata);
	return &myFileName;
}

int C_ResourcesManager::freadRcCrypted(unsigned char *a_buffer, int a_size, int a_nbElem, FILE *a_fp)
{
    int i;
	unsigned char temp;
	unsigned char l_cX;
	int  crypted;
	int  rc;

    crypted  = isCrypted;
	rc = fread((void *)a_buffer, a_size, a_nbElem, a_fp);
    if (crypted > 0)
    {
        for (i = 0 ; i < (a_size * a_nbElem) ; i++)
        {
            l_cX = a_buffer[i]<<6;
            temp = a_buffer[i]>>2;
            a_buffer[i] = l_cX | temp;
        }
    }
    return rc;
}
