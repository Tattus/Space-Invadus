#include "filusManagerus.hpp"

C_FileManager::C_FileManager()
{
    myErrorCode = NO_ERROR;
    relativePath = false;
    myFilePath = "";
    myWriteMode = "";
    position = 0;
}

C_FileManager::~C_FileManager()
{

}

void C_FileManager::setFilePath(string filePath)
{
    size_t found;
    myFilePath = filePath;

    if (myFilePath.find("/") != string::npos)
    {
        relativePath = true;
    }
    else
    {
         relativePath = false;
    }
    found = myFilePath.find_last_of("/\\");
    myDirPath = myFilePath.substr(0, found);
}

void C_FileManager::setWriteMode(string writeMode)
{
    myWriteMode = writeMode;
}

void C_FileManager::createDir(string directoryPath)
{
    string occurence = "/";
    if (directoryPath.find(occurence) != string::npos)
    {
        relativePath = true;
    }
    else
    {
         relativePath = false;
    }
    string dirPath = directoryPath + "/";
    string dirPathTemp = "";
    size_t found;



    if (relativePath)
    {
        while (found != string::npos)
        {
            found = dirPath.find(occurence);
            if (found != string::npos)
            {
                dirPathTemp = dirPathTemp + occurence + dirPath.substr(0, found);
                dirPath = dirPath.substr(found + 1);
                dirCreation(dirPathTemp);
            }
        }
    }
    else
    {
        dirCreation(directoryPath);
    }
}

bool C_FileManager::writeFile(string data)
{
    bool returnValue = true;

    createDir(myDirPath);
    if (myWriteMode == "a")
    {
        ofstream fichier(myFilePath.c_str(), ios::app);
        if (fichier)
        {
            fichier << data;
            fichier.close();
        }
        else
        {
            myErrorCode = OPEN_FILE_FAILURE;
            returnValue = false;
        }
    }
    else if (myWriteMode == "w")
    {
        ofstream fichier(myFilePath.c_str(), ios::trunc);
        if (fichier)
        {
            fichier << data;
            fichier.close();
        }
        else
        {
            myErrorCode = OPEN_FILE_FAILURE;
            returnValue = false;
        }
    }
    else if (myWriteMode == "ab")
    {
        ofstream fichier(myFilePath.c_str(), ios::app | ios::binary);
        if (fichier)
        {
            fichier.write(data.c_str(), data.size());
            fichier.close();
        }
        else
        {
            myErrorCode = OPEN_FILE_FAILURE;
            returnValue = false;
        }
    }
    else if (myWriteMode == "wb")
    {
        ofstream fichier(myFilePath.c_str(), ios::trunc | ios::binary);
        if (fichier)
        {
            fichier.write(data.c_str(), data.size());
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

bool C_FileManager::writeFile(char data)
{
    bool returnValue = true;

    createDir(myDirPath);
    if (myWriteMode == "a")
    {
        ofstream fichier(myFilePath.c_str(), ios::app);
        if (fichier)
        {
            fichier << data;
            fichier.close();
        }
        else
        {
            myErrorCode = OPEN_FILE_FAILURE;
            returnValue = false;
        }
    }
    else if (myWriteMode == "w")
    {
        ofstream fichier(myFilePath.c_str(), ios::trunc);
        if (fichier)
        {
            fichier << data;
            fichier.close();
        }
        else
        {
            myErrorCode = OPEN_FILE_FAILURE;
            returnValue = false;
        }
    }
    else if (myWriteMode == "ab")
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
    else if (myWriteMode == "wb")
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

bool C_FileManager::writeFile(int data)
{
    bool returnValue = true;

    createDir(myDirPath);
    if (myWriteMode == "a")
    {
        ofstream fichier(myFilePath.c_str(), ios::app);
        if (fichier)
        {
            fichier << data;
            fichier.close();
        }
        else
        {
            myErrorCode = OPEN_FILE_FAILURE;
            returnValue = false;
        }
    }
    else if (myWriteMode == "w")
    {
        ofstream fichier(myFilePath.c_str(), ios::trunc);
        if (fichier)
        {
            fichier << data;
            fichier.close();
        }
        else
        {
            myErrorCode = OPEN_FILE_FAILURE;
            returnValue = false;
        }
    }
    else if (myWriteMode == "ab")
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
    else if (myWriteMode == "wb")
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

bool C_FileManager::writeFile(long data)
{
    bool returnValue = true;

    createDir(myDirPath);
    if (myWriteMode == "a")
    {
        ofstream fichier(myFilePath.c_str(), ios::app);
        if (fichier)
        {
            fichier << data;
            fichier.close();
        }
        else
        {
            myErrorCode = OPEN_FILE_FAILURE;
            returnValue = false;
        }
    }
    else if (myWriteMode == "w")
    {
        ofstream fichier(myFilePath.c_str(), ios::trunc);
        if (fichier)
        {
            fichier << data;
            fichier.close();
        }
        else
        {
            myErrorCode = OPEN_FILE_FAILURE;
            returnValue = false;
        }
    }
    else if (myWriteMode == "ab")
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
    else if (myWriteMode == "wb")
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

bool C_FileManager::writeFile(double data)
{
    bool returnValue = true;

    createDir(myDirPath);
    if (myWriteMode == "a")
    {
        ofstream fichier(myFilePath.c_str(), ios::app);
        if (fichier)
        {
            fichier << data;
            fichier.close();
        }
        else
        {
            myErrorCode = OPEN_FILE_FAILURE;
            returnValue = false;
        }
    }
    else if (myWriteMode == "w")
    {
        ofstream fichier(myFilePath.c_str(), ios::trunc);
        if (fichier)
        {
            fichier << data;
            fichier.close();
        }
        else
        {
            myErrorCode = OPEN_FILE_FAILURE;
            returnValue = false;
        }
    }
    else if (myWriteMode == "ab")
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
    else if (myWriteMode == "wb")
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

bool C_FileManager::getEntireFile(string *data)
{
    bool returnValue = true;
    string ligne;

    ifstream fichier(myFilePath.c_str());
    if (fichier)
    {
        while(getline(fichier, ligne))
        {
            *data += ligne + "\n";
        }
        fichier.close();
    }
    else
    {
        myErrorCode = OPEN_FILE_FAILURE;
        returnValue = false;
    }

    return returnValue;
}

bool C_FileManager::readLine(string *data, int numLine)
{
    bool returnValue = true;
    int i;
    string ligne;

    ifstream fichier(myFilePath.c_str());
    if (fichier)
    {
        for (i = 0 ; i < numLine ; i++)
        {
            if (getline(fichier, ligne))
            {
                if ((i + 1) == numLine)
                {
                    *data = ligne;
                }
            }
            else
            {
                myErrorCode = LINE_NOT_FOUND;
                returnValue = false;
                break;
            }
        }
        fichier.close();
    }
    else
    {
        myErrorCode = OPEN_FILE_FAILURE;
        returnValue = false;
    }

    return returnValue;
}

bool C_FileManager::readLineInt(int *data, int numLine)
{
    bool returnValue = true;
    int i;
    string ligne;

    ifstream fichier(myFilePath.c_str());
    if (fichier)
    {
        for (i = 0 ; i < numLine ; i++)
        {
            if (getline(fichier, ligne))
            {
                if ((i + 1) == numLine)
                {
                    *data = atoi(ligne.c_str());
                }
            }
            else
            {
                myErrorCode = LINE_NOT_FOUND;
                returnValue = false;
                break;
            }
        }
        fichier.close();
    }
    else
    {
        myErrorCode = OPEN_FILE_FAILURE;
        returnValue = false;
    }

    return returnValue;
}

bool C_FileManager::readLineLong(long *data, int numLine)
{
    bool returnValue = true;
    int i;
    string ligne;

    ifstream fichier(myFilePath.c_str());
    if (fichier)
    {
        for (i = 0 ; i < numLine ; i++)
        {
            if (getline(fichier, ligne))
            {
                if ((i + 1) == numLine)
                {
                    *data = atol(ligne.c_str());
                }
            }
            else
            {
                myErrorCode = LINE_NOT_FOUND;
                returnValue = false;
                break;
            }
        }
        fichier.close();
    }
    else
    {
        myErrorCode = OPEN_FILE_FAILURE;
        returnValue = false;
    }

    return returnValue;
}

bool C_FileManager::readChar(char *data, int numChar)
{
    bool returnValue = true;
    int i;
    char character;

    ifstream fichier(myFilePath.c_str());
    if (fichier)
    {
        for (i = 0 ; i < numChar ; i++)
        {
            fichier.get(character);
            if (character != EOF)
            {
                if ((i + 1) == numChar)
                {
                    *data = character;
                }
            }
            else
            {
                myErrorCode = CHAR_NOT_FOUND;
                returnValue = false;
                break;
            }
        }
        fichier.close();
    }
    else
    {
        myErrorCode = OPEN_FILE_FAILURE;
        returnValue = false;
    }

    return returnValue;
}

bool C_FileManager::readCharBinary(char *data, int taille, int position)
{
    bool returnValue = true;

    ifstream fichier(myFilePath.c_str(), ios::binary);
    if (fichier)
    {
        fichier.seekg(position);
        fichier.read(data, taille - 1);
        data[taille] = '\0';
        fichier.close();
    }
    else
    {
        myErrorCode = OPEN_FILE_FAILURE;
        returnValue = false;
    }

    return returnValue;
}

bool C_FileManager::readIntBinary(int *data, int position)
{
    bool returnValue = true;

    ifstream fichier(myFilePath.c_str(), ios::binary);
    if (fichier)
    {
        fichier.seekg(position * sizeof(int));
        fichier.read((char*)data, sizeof(int));
        fichier.close();
    }
    else
    {
        myErrorCode = OPEN_FILE_FAILURE;
        returnValue = false;
    }

    return returnValue;
}

bool C_FileManager::readLongBinary(long *data, int position)
{
    bool returnValue = true;

    ifstream fichier(myFilePath.c_str(), ios::binary);
    if (fichier)
    {
        fichier.seekg(position * sizeof(long));
        fichier.read((char*)data, sizeof(long));
        fichier.close();
    }
    else
    {
        myErrorCode = OPEN_FILE_FAILURE;
        returnValue = false;
    }

    return returnValue;
}

bool C_FileManager::readDoubleBinary(double *data, int position)
{
    bool returnValue = true;

    ifstream fichier(myFilePath.c_str(), ios::binary);
    if (fichier)
    {
        fichier.seekg(position * sizeof(double));
        fichier.read((char*)data, sizeof(double));
        fichier.close();
    }
    else
    {
        myErrorCode = OPEN_FILE_FAILURE;
        returnValue = false;
    }

    return returnValue;
}

void C_FileManager::dirCreation(string directory)
{
    string myDirectory = "";

    if (relativePath)
    {
        myDirectory = "." + directory;
        #ifdef FILUS_LINUX
            mkdir(myDirectory.c_str(), 0770);
        #else
            mkdir(myDirectory.c_str());
        #endif
    }
    else
    {
        #ifdef FILUS_LINUX
            mkdir(directory.c_str(), 0770);
        #else
            mkdir(directory.c_str());
        #endif
    }
}

int C_FileManager::getErrorCode(void)
{
    return myErrorCode;
}
