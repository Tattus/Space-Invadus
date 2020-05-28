/* errorusManagerus.cpp
   --------------------

   Créé par : Tattus
   le : 30/04/2015

   Modifié le : 20/10/2016
   --------------------
   Nécessite datusManagerus.cpp et datusManagerus.h
*/
#include "errorusManagerus.hpp"

static C_ErrorManager *myInstanceEM = NULL;

C_ErrorManager::C_ErrorManager()
{
    myErrorCode = 0;
    errorIsText = false;
    myErrorType = 0;
    myErrorText = "";
}

C_ErrorManager::~C_ErrorManager()
{

}

C_ErrorManager *C_ErrorManager::getInstance(void)
{
    if (myInstanceEM == NULL)
    {
        myInstanceEM = new C_ErrorManager();
    }

    return myInstanceEM;
}

void C_ErrorManager::kill(void)
{
    if (myInstanceEM != NULL)
    {
        delete(myInstanceEM);
        myInstanceEM = NULL;
    }
}

void C_ErrorManager::errorCode(int errorCode, int errorType)
{
    myErrorCode = errorCode;
    myErrorType = errorType;
    writeErrorFile();
}

void C_ErrorManager::errorCode(string errorCode, int errorType)
{
    myErrorText = errorCode;
    errorIsText = true;
    myErrorType = errorType;
    writeErrorFile();
}

void C_ErrorManager::errorCode(string errorCode, int errorType, int errorCode2, int errorType2)
{

    if (errorCode2 != 0) // Erreur de type numérique.
    {
        this->errorCode(errorCode2, errorType2);
    }
    else if (errorType == ERROR_SDL || errorType == ERROR_SDLTTF || errorType == ERROR_SDLIMG || errorType == ERROR_SDLNET || errorType == ERROR_SDLMIX) // Erreur de type SDL (texte).
    {
        if (errorCode == "")
        {
            this->errorCode(errorCode, errorType);
        }
    }
    else if (errorType == ERROR_STD) // Erreur de type STD.
    {
        this->errorCode(errorCode, errorType);
    }
}

void C_ErrorManager::errorCode(int errorCode, int errorType, string errorCode2, int errorType2)
{
    this->errorCode(errorCode2, errorType2, errorCode, errorType); // On interchange les deux.
}

void C_ErrorManager::errorCode(int errorCode, int errorType, int errorCode2, int errorType2)
{
    if (errorCode != 0) // Erreur de type numérique sur le premier élément.
    {
        this->errorCode(errorCode, errorType);
    }
    else if (errorCode2 != 0) // Erreur de type numérique sur le deuxième élément.
    {
        this->errorCode(errorCode2, errorType2);
    }
}

void C_ErrorManager::errorCode(string errorCode, int errorType, string errorCode2, int errorType2)
{
    if (errorType == ERROR_SDL || errorType == ERROR_SDLTTF || errorType == ERROR_SDLIMG || errorType == ERROR_SDLNET || errorType == ERROR_SDLMIX) // Erreur de type SDL (texte) sur le 1er élément.
    {
        if (errorCode == "")
        {
            this->errorCode(errorCode, errorType);
        }
    }
    else if (errorType2 == ERROR_SDL || errorType2 == ERROR_SDLTTF || errorType2 == ERROR_SDLIMG || errorType2 == ERROR_SDLNET || errorType2 == ERROR_SDLMIX) // Erreur de type SDL (texte) sur le 2e élément.
    {
        if (errorCode2 == "")
        {
            this->errorCode(errorCode2, errorType2);
        }
    }
    else if (errorType == ERROR_STD) // Erreur de type STD sur le 1er élément.
    {
        this->errorCode(errorCode, errorType);
    }
    else if (errorType2 == ERROR_STD) // Erreur de type STD sur le 2e élément.
    {
        this->errorCode(errorCode2, errorType2);
    }
}

void C_ErrorManager::writeErrorFile(void)
{
    string date = "";
    string errorPath = "";
    string entete;
    C_DateManager *myDate = NULL;
    C_FileManager *myFile = NULL;

    entete = enteteError();
    if (!errorIsText)
    {
        textError();
    }

    myDate = new C_DateManager();

    myDate->setGlobalFormat("*-*-*");
    myDate->setFormat(3, 'Y', 'm', 'd');
    date = myDate->getDate();

    delete(myDate);

    errorPath = "Error_Report/" + date + "-error_report.txt";

    myFile = new C_FileManager();

    myFile->setFilePath(errorPath);
    myFile->setWriteMode("a");

    myFile->writeFile("--------------Next Error-------------\n");
    myFile->writeFile(entete);
    myFile->writeFile(myErrorText + "\n\n");

    delete(myFile);
}

string C_ErrorManager::enteteError(void)
{
    string entete = "";

    switch(myErrorType)
    {
        case ERROR_STD:
            entete = "Error STD:\n";
            break;
        case ERROR_RC_LOADUS:
            entete = "Error LOADER :\n";
            break;
        case ERROR_RESOURCES_MANAGERUS:
            entete = "Error Resources Manager :\n";
            break;
        case ERROR_DATUS_MANAGERUS:
            entete = "Error Dates Manager :\n";
            break;
        case ERROR_FILUS_MANAGERUS:
            entete = "Error Files Manager :\n";
            break;
        case ERROR_SDL:
            entete = "Error SDL :\n";
            break;
        case ERROR_SDLTTF:
            entete = "Error SDL_TTF :\n";
            break;
        case ERROR_SDLIMG:
            entete = "Error SDL_IMG :\n";
            break;
        case ERROR_SDLNET:
            entete = "Error SDL_NET :\n";
            break;
        case ERROR_SDLMIX:
            entete = "Error SDL_MIX :\n";
            break;
        case ERROR_FMOD:
            entete = "Error FMOD :\n";
            break;
        case ERROR_XML:
            entete = "Error XML :\n";
            break;
        default:
            entete =  "";
            break;
    }

    return entete;
}

void C_ErrorManager::textError(void)
{
    switch(myErrorType)
    {
        case ERROR_RC_LOADUS:
            switch(myErrorCode)
            {
                case 10:
                    myErrorText = "The resource container can't be found.";
                    break;
                case 11:
                    myErrorText = "The resource container is empty.";
                    break;
                case 12:
                    myErrorText = "The resource can't be found.";
                    break;
                default:
                    myErrorText = "";
                    break;
            }
            break;
        case ERROR_RESOURCES_MANAGERUS:
            switch(myErrorCode)
            {
                case 1:
                    myErrorText = "The name of the resources container is too long.";
                    break;
                case 2:
                    myErrorText = "The prefix is too long.";
                    break;
                case 3:
                    myErrorText = "The resource container can't be found.";
                    break;
                case 4:
                    myErrorText = "The resource container is empty.";
                    break;
                case 5:
                    myErrorText = "The resource can't be found.";
                    break;
                default:
                    myErrorText = "";
                    break;
            }
            break;
        case ERROR_DATUS_MANAGERUS:
            switch(myErrorCode)
            {
                case 1:
                    myErrorText = "Number asterisk != number elements.";
                    break;
                default:
                    myErrorText = "";
                    break;
            }
            break;
        case ERROR_FILUS_MANAGERUS:
            switch(myErrorCode)
            {
                case 1:
                    myErrorText = "Open file failure.";
                    break;
                case 2:
                    myErrorText = "The line read not found.";
                    break;
                case 3:
                    myErrorText = "The character read not found.";
                    break;
                case 4:
                    myErrorText = "The opening mode is wrong.";
                    break;
                default:
                    myErrorText = "";
                    break;
            }
            break;
        case ERROR_FMOD:
            switch(myErrorCode)
            {
                case 1:
                    myErrorText = "Tried to call a function on a data type that does not allow this type of functionality.";
                    break;
                case 2:
                    myErrorText = "Error trying to allocate a channel.";
                    break;
                case 3:
                    myErrorText = "The specified channel has been reused to play another sound.";
                    break;
                case 4:
                    myErrorText = "DMA Failure. See debug output for more information.";
                    break;
                case 5:
                    myErrorText = "DSP connection error. Connection possibly caused a cyclic dependency or connected dsps with incompatible buffer counts.";
                    break;
                case 6:
                    myErrorText = "DSP return code form a DSP process query callback. Tells mixer not to call the process callback and therefore not consume CPU. Use this to optimize the DSP graph.";
                    break;
                case 7:
                    myErrorText = "DSP Format error. A DSP unit may have attempted to connect tot his network with the wrong format, or a matrix may have been set with the wrong size if the target unit has a specified channel map.";
                    break;
                case 8:
                    myErrorText = "DSP is already in the mixer's DSP network. It must be removed before being reinserted or released.";
                    break;
                case 9:
                    myErrorText = "DSP connection error. Couldn't find the DSP unit specified.";
                    break;
                case 10:
                    myErrorText = "DSP operation error. Cannot perform operation on this DSP as it is reserved by the system.";
                    break;
                case 11:
                    myErrorText = "DSP return code from a DSP process query callback. Tells mixer silence would be produces from read, so go idle and not consume CPU. Use this to optimize the DSP graph.";
                    break;
                case 12:
                    myErrorText = "DSP operation cannot be performed on a DSP of this type.";
                    break;
                case 13:
                    myErrorText = "Error loading file.";
                    break;
                case 14:
                    myErrorText = "Counldn't perform seek operation. This is a limitation of the medium or the file format.";
                    break;
                case 15:
                    myErrorText = "Media was ejected while reading.";
                    break;
                case 16:
                    myErrorText = "End of file unexpectedly reached while trying to read essential data.";
                    break;
                case 17:
                    myErrorText = "End of current chunk reached while trying to read data.";
                    break;
                case 18:
                    myErrorText = "File not found.";
                    break;
                case 19:
                    myErrorText = "Unsupported file or audio format.";
                    break;
                case 20:
                    myErrorText = "There is a version mismatch between the FMOD header and either the FMOD Studio library or the FMOD Low Level Library.";
                    break;
                case 21:
                    myErrorText = "A HTTP error occurred. This is a catch-all for HTTP error not listed elsewhere.";
                    break;
                case 22:
                    myErrorText = "The specified resource requites authentication or is forbidden.";
                    break;
                case 23:
                    myErrorText = "Proxy authentication is required to access the specified resource.";
                    break;
                case 24:
                    myErrorText = "A HTTP server error occurred.";
                    break;
                case 25:
                    myErrorText = "A HTTP request timed out.";
                    break;
                case 26:
                    myErrorText = "FMOD was not initialized correctly to support this function.";
                    break;
                case 27:
                    myErrorText = "Cannot call this command after System::init.";
                    break;
                case 28:
                    myErrorText = "An error occured that wasn't supposed to. Contact support.";
                    break;
                case 29:
                    myErrorText = "Value passed in was a NaN, Inf or denormalized float.";
                    break;
                case 30:
                    myErrorText = "An invalid object handle was used.";
                    break;
                case 31:
                    myErrorText = "An invalid parameter was passed to this function.";
                    break;
                case 32:
                    myErrorText = "An invalid seek position was passed to this function.";
                    break;
                case 33:
                    myErrorText = "An invalid speaker was passed to this function based on the current speaker mode.";
                    break;
                case 34:
                    myErrorText = "The syncpoint did not come from this sound handle.";
                    break;
                case 35:
                    myErrorText = "Tried to call a function on a thread that is not supported.";
                    break;
                case 36:
                    myErrorText = "The vectors passed in are not unit length, or perpendicular.";
                    break;
                case 37:
                    myErrorText = "Reached maximum audible playback count for this sound's soundgroup.";
                    break;
                case 38:
                    myErrorText = "Not enough memory or resources.";
                    break;
                case 39:
                    myErrorText = "Can't use FMOD_OPENMEMORY_POINT on non PCM source data, or non mp3/xma/adpcm data if FMOD_CREATECOMPRESSEDSAMPLE was used.";
                    break;
                case 40:
                    myErrorText = "Tried to call a command on a 2d sound when the command was meant for 3d sound.";
                    break;
                case 41:
                    myErrorText = "Tried to use a feature that requires hardware support.";
                    break;
                case 42:
                    myErrorText = "Couldn't connect to the specified host.";
                    break;
                case 43:
                    myErrorText = "A socket error occurred. This is a catch-all for socket-related errors not listed elsewhere.";
                    break;
                case 44:
                    myErrorText = "The specified URL couldn't be resolved.";
                    break;
                case 45:
                    myErrorText = "Operation on a non-blocking socket could not complete immediately.";
                    break;
                case 46:
                    myErrorText = "Operation could not be performed because specified sound/DSP connextion is not ready.";
                    break;
                case 47:
                    myErrorText = "Error initializing output device, but more specifically, the output device is already in use and cannot be reused.";
                    break;
                case 48:
                    myErrorText = "Error creating hardware sound buffer.";
                    break;
                case 49:
                    myErrorText = "A call to a standard soundcard driver failed, which could possibly mean a bug in the driver or resources were missing or exhausted.";
                    break;
                case 50:
                    myErrorText = "Soundcard does not support the specified format.";
                    break;
                case 51:
                    myErrorText = "Error initializing output device.";
                    break;
                case 52:
                    myErrorText = "The output device has no drivers installed. If pre-init, FMOD_OUTPUT_NOSOUND is selected as the output mode. If post-init, the function just fails.";
                    break;
                case 53:
                    myErrorText = "An unspecified error has been returned from a plugin.";
                    break;
                case 54:
                    myErrorText = "A requested output, dsp unit type or codec was not available.";
                    break;
                case 55:
                    myErrorText = "A resource that the plugin requires cannot be found.";
                    break;
                case 56:
                    myErrorText = "A plugin was built with an unsupported SDK version.";
                    break;
                case 57:
                    myErrorText = "An error occurred trying to initialize the recording device.";
                    break;
                case 58:
                    myErrorText = "Reverb properties cannot be set on this channel because a parent channelgroup owns the reverb connection.";
                    break;
                case 59:
                    myErrorText = "Specified instance in FMOD_REVERB_PROPERTIES couldn't be set. Most likely because it is an invalid instance number or the reverb doesn't exist.";
                    break;
                case 60:
                    myErrorText = "The occurred because the sound referenced contains subsounds when it shouldn't have, or it doesn't contain subsounds when it should have. The operation may also not be able to be performed on a parrent sound.";
                    break;
                case 61:
                    myErrorText = "This subsound is already being used by another sound, you cannot have more than one parent to a sound. Null out the other parent's entry first.";
                    break;
                case 62:
                    myErrorText = "Shared subsounds cannot be replaced or moved from their parent stream, such as when the parent stream is an FSB file.";
                    break;
                case 63:
                    myErrorText = "The specified tag could not be found or there are no tags.";
                    break;
                case 64:
                    myErrorText = "The sound created exceeds the allowable input channel count. This can be increased using the 'maxinputchannels' parameter in system::setSoftwareFormat.";
                    break;
                case 65:
                    myErrorText = "The retrieved string is too long to fit in the supplied buffer and has been truncated.";
                    break;
                case 66:
                    myErrorText = "Something in FMOD hasn't been implemented when it should be ! Contact support !";
                    break;
                case 67:
                    myErrorText = "This command failed because System::init or System::setDriver was not called.";
                    break;
                case 68:
                    myErrorText = "A command issued was not supported by this object. Possibly a plugin without certain callbacks specified.";
                    break;
                case 69:
                    myErrorText = "The version number of this file format is not supported.";
                    break;
                case 70:
                    myErrorText = "The specified bank has already been loaded.";
                    break;
                case 71:
                    myErrorText = "The live update connection failed due to the game already being connected.";
                    break;
                case 72:
                    myErrorText = "The live update connection failed due to the game data being out of sync with the tool.";
                    break;
                case 73:
                    myErrorText = "The live update connection timed out.";
                    break;
                case 74:
                    myErrorText = "The requested event, bus or vca could not be found.";
                    break;
                case 75:
                    myErrorText = "The Studio::System object is not yet initialized.";
                    break;
                case 76:
                    myErrorText = "The specified resource is not loaded, so it can't be unloaded.";
                    break;
                case 77:
                    myErrorText = "An invalid string was passed to this function.";
                    break;
                case 78:
                    myErrorText = "The specified resource is already locked.";
                    break;
                case 79:
                    myErrorText = "The specified resource is not locked, so it can't be unlocked.";
                    break;
                default:
                    myErrorText = "";
                    break;
            }
            break;
        case ERROR_XML:
            switch(myErrorCode)
            {
                case 1:
                    myErrorText = "The attribute doesn't exist.";
                    break;
                case 2:
                    myErrorText = "The attribute type is wrong.";
                    break;
                case 3:
                    myErrorText = "File not found.";
                    break;
                case 4:
                    myErrorText = "File couldn't be opened.";
                    break;
                case 5:
                    myErrorText = "File read error.";
                    break;
                case 6:
                    myErrorText = "Element mismatch.";
                    break;
                case 7:
                    myErrorText = "Error parsing element.";
                    break;
                case 8:
                    myErrorText = "Error parsing attribute.";
                    break;
                case 9:
                    myErrorText = "Error identifying type.";
                    break;
                case 10:
                    myErrorText = "Error parsing text.";
                    break;
                case 11:
                    myErrorText = "Error parsing cdata.";
                    break;
                case 12:
                    myErrorText = "Error parsing comment.";
                    break;
                case 13:
                    myErrorText = "Error parsing declaration.";
                    break;
                case 14:
                    myErrorText = "Error parsing unknown.";
                    break;
                case 15:
                    myErrorText = "Empty document.";
                    break;
                case 16:
                    myErrorText = "Mismatched element.";
                    break;
                case 17:
                    myErrorText = "Error parsing.";
                    break;
                case 18:
                    myErrorText = "Canno't convert text.";
                    break;
                case 19:
                    myErrorText = "No text node.";
                    break;
                case 20:
                    myErrorText = "Error count.";
                    break;
                default:
                    myErrorText = "";
                    break;
            }
            break;
        default:
            break;
    }
}
