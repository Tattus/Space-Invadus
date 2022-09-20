#include "sound.hpp"

C_Sound::C_Sound()
{
    ErrorManager = C_ErrorManager::getInstance();
    ResourcesManager = C_ResourcesManager::getInstance();
    SoundManager = C_SoundManager::getInstance();
    mySound = NULL;
    myChannel = 0;
    fromNoDel = false;
}

C_Sound::~C_Sound()
{
    if (mySound != NULL)
    {
        FMOD_Sound_Release(mySound);
    }
    if (fromNoDel)
    {
        ResourcesManager->closeRcFile();
    }
}

bool C_Sound::loadSound(string soundName, int FMODFlags)
{
    FMOD_RESULT verifFMOD = FMOD_OK;
    verifFMOD = FMOD_System_CreateSound(SoundManager->getSystem(), soundName.c_str(), FMODFlags, NULL, &mySound);
    if (verifFMOD != FMOD_OK)
    {
        ErrorManager->errorCode(verifFMOD, C_ErrorManager::ERROR_FMOD);
        return false;
    }
    return true;
}

bool C_Sound::loadRcSound(string soundName, int FMODFlags)
{
    FMOD_RESULT verifFMOD = FMOD_OK;
    verifFMOD = ResourcesManager->FMOD_System_CreateRcSound(SoundManager->getSystem(), soundName.c_str(), FMODFlags, NULL, &mySound);
    if (verifFMOD != FMOD_OK)
    {
        ErrorManager->errorCode(verifFMOD, C_ErrorManager::ERROR_FMOD);
        return false;
    }
    return true;
}

bool C_Sound::loadRcSoundNoDel(string soundName, int FMODFlags)
{
    FMOD_RESULT verifFMOD = FMOD_OK;
    verifFMOD = ResourcesManager->FMOD_System_CreateRcSoundNoDel(SoundManager->getSystem(), soundName.c_str(), FMODFlags, NULL, &mySound);
    if (verifFMOD != FMOD_OK)
    {
        ErrorManager->errorCode(verifFMOD, C_ErrorManager::ERROR_FMOD);
        return false;
    }
    fromNoDel = true;
    return true;
}

FMOD_SOUND *C_Sound::getSound(void)
{
    return mySound;
}

void C_Sound::playSound(int canal)
{
    myChannel = canal;
    switch(myChannel)
    {
        case C_FX:
            FMOD_System_PlaySound(SoundManager->getSystem(), mySound, SoundManager->getFxChannelGroup(), 0, NULL);
            break;
        case C_VOICE:
            FMOD_System_PlaySound(SoundManager->getSystem(), mySound, SoundManager->getVoiceChannelGroup(), 0, NULL);
            break;
        case C_MUSIC:
            FMOD_System_PlaySound(SoundManager->getSystem(), mySound, SoundManager->getMusicChannelGroup(), 0, NULL);
            break;
    }
}

void C_Sound::stopSound(void)
{
    FMOD_ChannelGroup_Stop(SoundManager->getMusicChannelGroup());
}
