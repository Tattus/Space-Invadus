/* soundusManagerus.cpp
   --------------------

   Créé par : Tattus
   le : 10/05/2015

   Modifié le : 22/10/2016

*/
#include "soundusManagerus.hpp"

static C_SoundManager *myInstanceSM = NULL;

C_SoundManager::C_SoundManager()
{
    int i;

    ErrorManager = NULL;
    mySystem = NULL;
    masterChannelGroup = NULL;
    fxChannelGroup = NULL;
    voiceChannelGroup = NULL;
    musicChannelGroup = NULL;
    myNbChannel = 0;
    for (i = 0 ; i < 4093 ; i++)
    {
        myChannel[i] = NULL;
    }
}

C_SoundManager::~C_SoundManager()
{
    if (masterChannelGroup != NULL)
    {
        FMOD_ChannelGroup_Release(masterChannelGroup);
    }
    if (fxChannelGroup != NULL)
    {
        FMOD_ChannelGroup_Release(fxChannelGroup);
    }
    if (voiceChannelGroup != NULL)
    {
        FMOD_ChannelGroup_Release(voiceChannelGroup);
    }
    if (musicChannelGroup != NULL)
    {
        FMOD_ChannelGroup_Release(musicChannelGroup);
    }
}

C_SoundManager *C_SoundManager::getInstance(void)
{
    if (myInstanceSM == NULL)
    {
        myInstanceSM = new C_SoundManager();
    }

    return myInstanceSM;
}

void C_SoundManager::kill(void)
{
    if (myInstanceSM != NULL)
    {
        delete(myInstanceSM);
        myInstanceSM = NULL;
    }
}

void C_SoundManager::setSystem(FMOD_SYSTEM *system, int nbChannel)
{
    mySystem = system;
    myNbChannel = nbChannel;
    setChannel();
    setMasterChannelGroup();
}

FMOD_SYSTEM *C_SoundManager::getSystem(void)
{
    return mySystem;
}

void C_SoundManager::setChannel(void)
{
    FMOD_RESULT verifFMOD = FMOD_OK;
    int i;

    for (i = 0 ; i < myNbChannel ; i++)
    {
        verifFMOD = FMOD_System_GetChannel(mySystem, i, &myChannel[i]);
        if (verifFMOD != FMOD_OK)
        {
            ErrorManager->errorCode(verifFMOD, C_ErrorManager::ERROR_FMOD);
        }
    }
}

void C_SoundManager::setMasterChannelGroup(void)
{
    FMOD_RESULT verifFMOD = FMOD_OK;

    verifFMOD = FMOD_System_CreateChannelGroup(mySystem, NULL, &masterChannelGroup);
    if (verifFMOD != FMOD_OK)
    {
        ErrorManager->errorCode(verifFMOD, C_ErrorManager::ERROR_FMOD);
    }
    verifFMOD = FMOD_System_GetMasterChannelGroup(mySystem, &masterChannelGroup);
    if (verifFMOD != FMOD_OK)
    {
        ErrorManager->errorCode(verifFMOD, C_ErrorManager::ERROR_FMOD);
    }
}

void C_SoundManager::setFxChannelGroup(int startChannel, int lastChannel)
{
    FMOD_RESULT verifFMOD = FMOD_OK;
    int i;

    verifFMOD = FMOD_System_CreateChannelGroup(mySystem, NULL, &fxChannelGroup);
    if (verifFMOD != FMOD_OK)
    {
        ErrorManager->errorCode(verifFMOD, C_ErrorManager::ERROR_FMOD);
    }
    for (i = startChannel ; i <= lastChannel ; i++)
    {
        verifFMOD = FMOD_Channel_SetChannelGroup(myChannel[i], fxChannelGroup);
        if (verifFMOD != FMOD_OK)
        {
            ErrorManager->errorCode(verifFMOD, C_ErrorManager::ERROR_FMOD);
        }
    }
}

void C_SoundManager::setVoiceChannelGroup(int startChannel, int lastChannel)
{
    FMOD_RESULT verifFMOD = FMOD_OK;
    int i;

    verifFMOD = FMOD_System_CreateChannelGroup(mySystem, NULL, &voiceChannelGroup);
    if (verifFMOD != FMOD_OK)
    {
        ErrorManager->errorCode(verifFMOD, C_ErrorManager::ERROR_FMOD);
    }
    for (i = startChannel ; i <= lastChannel ; i++)
    {
        verifFMOD = FMOD_Channel_SetChannelGroup(myChannel[i], voiceChannelGroup);
        if (verifFMOD != FMOD_OK)
        {
            ErrorManager->errorCode(verifFMOD, C_ErrorManager::ERROR_FMOD);
        }
    }
}

void C_SoundManager::setMusicChannelGroup(int startChannel, int lastChannel)
{
    FMOD_RESULT verifFMOD = FMOD_OK;
    int i;

    verifFMOD = FMOD_System_CreateChannelGroup(mySystem, NULL, &musicChannelGroup);
    if (verifFMOD != FMOD_OK)
    {
        ErrorManager->errorCode(verifFMOD, C_ErrorManager::ERROR_FMOD);
    }
    for (i = startChannel ; i <= lastChannel ; i++)
    {
        verifFMOD = FMOD_Channel_SetChannelGroup(myChannel[i], musicChannelGroup);
        if (verifFMOD != FMOD_OK)
        {
            ErrorManager->errorCode(verifFMOD, C_ErrorManager::ERROR_FMOD);
        }
    }
}

FMOD_CHANNELGROUP *C_SoundManager::getMasterChannelGroup(void)
{
    return masterChannelGroup;
}

FMOD_CHANNELGROUP *C_SoundManager::getFxChannelGroup(void)
{
    return fxChannelGroup;
}

FMOD_CHANNELGROUP *C_SoundManager::getVoiceChannelGroup(void)
{
    return voiceChannelGroup;
}

FMOD_CHANNELGROUP *C_SoundManager::getMusicChannelGroup(void)
{
    return musicChannelGroup;
}

FMOD_CHANNEL *C_SoundManager::getChannel(int numChannel)
{
    return myChannel[numChannel];
}
