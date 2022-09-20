#include <iostream>
#include "parametrage.hpp"
#include "errorusManagerus.hpp"
#include "filusManagerus.hpp"

bool writeLicenses()
{
    C_ErrorManager *ErrorManager = C_ErrorManager::getInstance();
    C_FileManager fichier;
    string contenu;
    fichier.setWriteMode("w");

    string progName = PROG_NAME;
    string version = VERSION;

    /// Manuel Projet
    fichier.setFilePath("Manual/FR " + progName + " V" + version + " Manual.txt");
    // Rédaction du fichier.
    contenu = "\n*** Comment jouer ***\n";
    contenu += "\n --------------------\n";
    contenu += "\nClavier :\n\n";
    contenu += "_ Déplacement : Fleches Gauche/Droite\n";
    contenu += "_ Tir : C\n";
    contenu += "\n --------------------\n";
    contenu += "\nManette :\n\n";
    contenu += "_ Déplacement : Fleches Gauche/Droite\n";
    contenu += "_ Tir : A\n";

    if (!fichier.writeFile(contenu))
    {
        ErrorManager->errorCode(fichier.getErrorCode(), C_ErrorManager::ERROR_FILUS_MANAGERUS);
        return false;
    }
    contenu = "";

    fichier.setFilePath("Manual/ENG " + progName + " V" + version + " Manual.txt");
    // Rédaction du fichier.
    contenu = "\n*** How to play ***\n";
    contenu += "\n --------------------\n";
    contenu += "\nKeyboard :\n\n";
    contenu += "_ Move : Right/Left arrows\n";
    contenu += "_ Shoot : C\n";
    contenu += "\n --------------------\n";
    contenu += "\nController :\n\n";
    contenu += "_ Move : Right/Left arrows\n";
    contenu += "_ Shoot : A\n";

    if (!fichier.writeFile(contenu))
    {
        ErrorManager->errorCode(fichier.getErrorCode(), C_ErrorManager::ERROR_FILUS_MANAGERUS);
        return false;
    }
    contenu = "";

    /// License Projet
    fichier.setFilePath("Licenses/FR " + progName + " V" + version + " License.txt");
    // Rédaction du fichier.
    contenu = "\n*** Credits ***\n";
    contenu += "*** " + progName + " V" + version + " ***\n";
    contenu += "\n --------------------\n";
    contenu += "\nCode :\n\n";
    contenu += "_ Tattus\n";
    contenu += "\n--------------------\n";
    contenu += "\nGraphismes :\n\n";
    contenu += "_ Tattus\n";
    contenu += "\n--------------------\n";
    contenu += "\nSons :\n\n";
    contenu += "_ Tattus\n";
    contenu += "\n--------------------\n";
    contenu += "\nPolices : \n\n";
    contenu += "_ Liberation Fonts Mono (https://fedorahosted.org/liberation-fonts/) sous licence \"SIL Open Font License\"";
    contenu += "\n--------------------\n";
    contenu += "\nBibliothèques utilisées :\n\n";
    contenu += "_ SDL 2.0 sous licence zlib\n";
    contenu += "_ SDL image sous licence zlib\n";
    contenu += "_ SDL TTF sous licence zlib\n";
    contenu += "_ zlib (via SDL IMG, SDL TTF) sous licence zlib\n";
    contenu += "_ PNG (via SDL Image) sous licence libpng\n";
    contenu += "_ freetype (via SDL TTF) sous licence FreeType\n";
    contenu += "copyright © 2013 The FreeType Project (www.freetype.org).  All rights reserved.\n";
    contenu += "_ FMOD Studio low level\n";
    contenu += "FMOD Studio, copyright © Firelight Technologies Pty, Ltd., 1994-2014.\n";
    contenu += "www.fmod.org/sales/\n";
    contenu += "\n--------------------\n";
    contenu += "\n--------------------\n";
    contenu += "\n*** Licence ***\n";
    contenu += "\n_ La diffusion gratuite de " + progName + " V" + version +", sans modifications est autorisée.\n";

    if (!fichier.writeFile(contenu))
    {
        ErrorManager->errorCode(fichier.getErrorCode(), C_ErrorManager::ERROR_FILUS_MANAGERUS);
        return false;
    }
    contenu = "";

    fichier.setFilePath("Licenses/ENG " + progName + " V" + version + " License.txt");
    // Rédaction du fichier.
    contenu = "\n*** Credits ***\n";
    contenu += "*** " + progName + " V" + version + " ***\n";
    contenu += "\n --------------------\n";
    contenu += "\nCode :\n";
    contenu += "\n_ Tattus\n";
    contenu += "\n--------------------\n";
    contenu += "\nGraphics :\n\n";
    contenu += "_ Tattus\n";
    contenu += "\nSounds :\n\n";
    contenu += "_ Tattus\n";
    contenu += "\n--------------------\n";
    contenu += "\n--------------------\n";
    contenu += "\nFonts : \n";
    contenu += "\n_ Liberation Fonts Mono  (https://fedorahosted.org/liberation-fonts/) under \"SIL Open Font License\" license\n";
    contenu += "\n--------------------\n";
    contenu += "\nLibraries used :\n\n";
    contenu += "_ SDL 2.0 under zlib license\n";
    contenu += "_ SDL image under zlib license\n";
    contenu += "_ SDL TTF under zlib license\n";
    contenu += "_ zlib (via SDL IMG, SDL TTF) under zlib license\n";
    contenu += "_ PNG (via SDL Image) under libpng license\n";
    contenu += "_ freetype (via SDL TTF) sous licence FreeType\n";
    contenu += "copyright © 2013 The FreeType Project (www.freetype.org).  All rights reserved.\n";
    contenu += "_ FMOD Studio low level\n";
    contenu += "FMOD Studio, copyright © Firelight Technologies Pty, Ltd., 1994-2014.\n";
    contenu += "www.fmod.org/sales/\n";
    contenu += "\n--------------------\n";
    contenu += "\n--------------------\n";
    contenu += "\n*** License ***\n";
    contenu += "\n_ Free redistribution without modifications of " + progName + " V" + version +" is allowed.\n";

    if (!fichier.writeFile(contenu))
    {
        ErrorManager->errorCode(fichier.getErrorCode(), C_ErrorManager::ERROR_FILUS_MANAGERUS);
        return false;
    }
    contenu = "";

    /// Versions Projet
    fichier.setFilePath("Version/FR " + progName + " V" + version + " Version.txt");
    // Rédaction du fichier.
    contenu = "\n*** Changement de la 0.1 à la 1.1 ***\n";
    contenu += "\n --------------------\n";
    contenu += "\nEquilibrage :\n\n";
    contenu += "_ Le vaisseau peut avoir jusqu'à 5 tirs simultanés au lieu de 3\n";
    contenu += "\n --------------------\n";
    contenu += "\nCorrection de bug :\n\n";
    contenu += "_ Le niveau 4 se termine maintenant correctement\n";
    contenu += "\n --------------------\n";
    contenu += "\nDivers :\n\n";
    contenu += "_ Le volume du jeu à été diminué\n";

    if (!fichier.writeFile(contenu))
    {
        ErrorManager->errorCode(fichier.getErrorCode(), C_ErrorManager::ERROR_FILUS_MANAGERUS);
        return false;
    }
    contenu = "";

    fichier.setFilePath("Version/ENG " + progName + " V" + version + " Version.txt");
    // Rédaction du fichier.
    contenu = "\n*** Changelog from 0.1 to 1.1 ***\n";
    contenu += "\n --------------------\n";
    contenu += "\nGamebalance :\n\n";
    contenu += "_ Spaceship can shoot 5 times simultaneous instead of 3\n";
    contenu += "\n --------------------\n";
    contenu += "\nBugfixes :\n\n";
    contenu += "_ Level 4 now ends correctly\n";
    contenu += "\n --------------------\n";
    contenu += "\nOthers :\n\n";
    contenu += "_ Game's volume has been decreased\n";

    if (!fichier.writeFile(contenu))
    {
        ErrorManager->errorCode(fichier.getErrorCode(), C_ErrorManager::ERROR_FILUS_MANAGERUS);
        return false;
    }
    contenu = "";

    /// License SDL
    #ifdef PARAM_SDL
        fichier.setFilePath("Licenses/LibLicenses/README-SDL2.txt");
        // Rédaction du fichier.
        contenu = "\nPlease distribute this file with the SDL runtime environment:\n\n";
        contenu += "The Simple DirectMedia Layer (SDL for short) is a cross-platfrom library\n";
        contenu += "designed to make it easy to write multi-media software, such as games and\n";
        contenu += "emulators.\n\n";
        contenu += "The Simple DirectMedia Layer library source code is available from:\n";
        contenu += "http://www.libsdl.org/\n\n";
        contenu += "This library is distributed under the terms of the zlib license:\n";
        contenu += "http://www.zlib.net/zlib_license.html\n";
        if (!fichier.writeFile(contenu))
        {
            ErrorManager->errorCode(fichier.getErrorCode(), C_ErrorManager::ERROR_FILUS_MANAGERUS);
            return false;
        }
        contenu = "";
    #endif

    /// License SDL IMG
    #ifdef PARAM_SDL_IMG
        fichier.setFilePath("Licenses/LibLicenses/README-SDL_IMG.txt");
        // Rédaction du fichier.
        contenu = "\nSDL_image 2.0\n\n";
        contenu += "The latest version of this library is available from:\n";
        contenu += "https://www.libsdl.org/projects/SDL_image/\n\n";
        contenu += "This is a simple library to load images of various formats as SDL surfaces.\n";
        contenu += "This library supports BMP, PNM (PPM/PGM/PBM), XPM, LBM, PCX, GIF, JPEG, PNG,\n";
        contenu += "TGA, and TIFF formats.\n";
        contenu += "This library is under the zlib License.\n";
        contenu += "http://www.zlib.net/zlib_license.html\n\n";
        contenu += "JPEG support requires the JPEG library: http://www.ijg.org/\n";
        contenu += "PNG support requires the PNG library: http://www.libpng.org/pub/png/libpng.html\n";
        contenu += "    and the Zlib library: http://www.gzip.org/zlib/\n";
        contenu += "TIFF support requires the TIFF library: ftp://ftp.sgi.com/graphics/tiff/\n";
        if (!fichier.writeFile(contenu))
        {
            ErrorManager->errorCode(fichier.getErrorCode(), C_ErrorManager::ERROR_FILUS_MANAGERUS);
            return false;
        }
        contenu = "";
    #endif

    /// License SDL TTF
    #ifdef PARAM_SDL_TTF
        fichier.setFilePath("Licenses/LibLicenses/README-SDL_TTF.txt");
        // Rédaction du fichier.
        contenu = "\nSDL_ttf 2.0:  A companion library to SDL for working with TrueType (tm) fonts\n\n";
        contenu += "Copyright (C) 1997-2013 Sam Lantinga <slouken@libsdl.org>\n";
        contenu += "https://www.libsdl.org/projects/SDL_ttf/\n\n";
        contenu += "Portions of this software are copyright © 2013 The FreeType Project (www.freetype.org).  All rights reserved.\n";
        contenu += "\thttp://www.freetype.org/\n\n";
        contenu += "This library is distributed under the terms of the zlib license:\n";
        contenu += "http://www.zlib.net/zlib_license.html\n";
        if (!fichier.writeFile(contenu))
        {
            ErrorManager->errorCode(fichier.getErrorCode(), C_ErrorManager::ERROR_FILUS_MANAGERUS);
            return false;
        }
        contenu = "";
    #endif

    /// License SDL MIX
    #ifdef PARAM_SDL_MIX
        fichier.setFilePath("Licenses/LibLicenses/README-SDL_MIX.txt");
        // Rédaction du fichier.
        contenu = "\nSDL_mixer 2.0\n\n";
        contenu += "The latest version of this library is available from:\n";
        contenu += "https://www.libsdl.org/projects/SDL_mixer/\n\n";
        contenu += "This library is under the zlib License.\n";
        contenu += "http://www.zlib.net/zlib_license.html\n";
        if (!fichier.writeFile(contenu))
        {
            ErrorManager->errorCode(fichier.getErrorCode(), C_ErrorManager::ERROR_FILUS_MANAGERUS);
            return false;
        }
        contenu = "";
    #endif

    /// License SDL NET
    #ifdef PARAM_SDL_NET
        fichier.setFilePath("Licenses/LibLicenses/README-SDL_NET.txt");
        // Rédaction du fichier.
        contenu = "\nSDL_net 2.0\n\n";
        contenu += "The latest version of this library is available from:\n";
        contenu += "https://www.libsdl.org/projects/SDL_net/\n\n";
        contenu += "Copyright (C) 1997-2013 Sam Lantinga <slouken@libsdl.org>\n";
        contenu += "This library is distributed under the terms of the zlib license:\n";
        contenu += "http://www.zlib.net/zlib_license.html\n";
        if (!fichier.writeFile(contenu))
        {
            ErrorManager->errorCode(fichier.getErrorCode(), C_ErrorManager::ERROR_FILUS_MANAGERUS);
            return false;
        }
        contenu = "";
    #endif

    /// License FMOD STUDIO
    #ifdef PARAM_FMOD_STUDIO_LOW
        fichier.setFilePath("Licenses/LibLicenses/FMOD-Studio.txt");
        // Rédaction du fichier.
        contenu = "\nFMOD Studio\n\n";
        contenu += "FMOD Studio, copyright © Firelight Technologies Pty, Ltd., 1994-2014.”\n";
        contenu += "www.fmod.org/sales/\n\n";
        if (!fichier.writeFile(contenu))
        {
            ErrorManager->errorCode(fichier.getErrorCode(), C_ErrorManager::ERROR_FILUS_MANAGERUS);
            return false;
        }
        contenu = "";
    #endif

    /// License TINY XML
    #ifdef PARAM_TINY_XML
        fichier.setFilePath("Licenses/LibLicenses/README-TinyXML2.txt");
        // Rédaction du fichier.
        contenu = "\nTinyXML 2\n\n";
        contenu += "http://www.grinninglizard.com/tinyxml2docs/index.html\n";
        contenu += "TinyXML-2 is released under the zlib license:\n";
        contenu += "http://www.zlib.net/zlib_license.html\n\n";
        if (!fichier.writeFile(contenu))
        {
            ErrorManager->errorCode(fichier.getErrorCode(), C_ErrorManager::ERROR_FILUS_MANAGERUS);
            return false;
        }
        contenu = "";
    #endif

    /// License LIBERATION FONT
    #ifdef PARAM_LIBERATION_FONT
        fichier.setFilePath("Licenses/Fonts/README-Liberation_Font.txt");
        // Rédaction du fichier.
        contenu = "Digitized data copyright (c) 2010 Google Corporation\n";
        contenu += "	with Reserved Font Arimo, Tinos and Cousine.\n";
        contenu += "Copyright (c) 2012 Red Hat, Inc.\n";
        contenu += "	with Reserved Font Name Liberation.\n";
        contenu += "This Font Software is licensed under the SIL Open Font License,\n";
        contenu += "Version 1.1.\n\n";
        contenu += "This license is copied below, and is also available with a FAQ at:\n";
        contenu += "http://scripts.sil.org/OFL\n\n";
        contenu += "SIL OPEN FONT LICENSE Version 1.1 - 26 February 2007\n\n";
        contenu += "PREAMBLE The goals of the Open Font License (OFL) are to stimulate\n";
        contenu += "worldwide development of collaborative font projects, to support the font\n";
        contenu += "creation efforts of academic and linguistic communities, and to provide\n";
        contenu += "a free and open framework in which fonts may be shared and improved in\n";
        contenu += "partnership with others.\n\n";
        contenu += "The OFL allows the licensed fonts to be used, studied, modified and\n";
        contenu += "redistributed freely as long as they are not sold by themselves.\n";
        contenu += "The fonts, including any derivative works, can be bundled, embedded,\n";
        contenu += "redistributed and/or sold with any software provided that any reserved\n";
        contenu += "names are not used by derivative works.  The fonts and derivatives,\n";
        contenu += "however, cannot be released under any other type of license.  The\n";
        contenu += "requirement for fonts to remain under this license does not apply to\n";
        contenu += "any document created using the fonts or their derivatives.\n\n\n\n";
        contenu += "DEFINITIONS\n";
        contenu += "\"Font Software\" refers to the set of files released by the Copyright\n";
        contenu += "Holder(s) under this license and clearly marked as such.\n";
        contenu += "This may include source files, build scripts and documentation.\n\n";
        contenu += "\"Reserved Font Name\" refers to any names specified as such after the\n";
        contenu += "copyright statement(s).\n\n";
        contenu += "\"Original Version\" refers to the collection of Font Software components\n";
        contenu += "as distributed by the Copyright Holder(s).\n\n";
        contenu += "\"Modified Version\" refers to any derivative made by adding to, deleting,\n";
        contenu += "or substituting ? in part or in whole ?\n";
        contenu += "any of the components of the Original Version, by changing formats or\n";
        contenu += "by porting the Font Software to a new environment.\n\n";
        contenu += "\"Author\" refers to any designer, engineer, programmer, technical writer\n";
        contenu += "or other person who contributed to the Font Software.\n\n\n";
        contenu += "PERMISSION & CONDITIONS\n\n";
        contenu += "Permission is hereby granted, free of charge, to any person obtaining a\n";
        contenu += "copy of the Font Software, to use, study, copy, merge, embed, modify,\n";
        contenu += "redistribute, and sell modified and unmodified copies of the Font\n";
        contenu += "Software, subject to the following conditions:\n\n";
        contenu += "1) Neither the Font Software nor any of its individual components,in\n";
        contenu += "   Original or Modified Versions, may be sold by itself.\n\n";
        contenu += "2) Original or Modified Versions of the Font Software may be bundled,\n";
        contenu += "   redistributed and/or sold with any software, provided that each copy\n";
        contenu += "   contains the above copyright notice and this license. These can be\n";
        contenu += "   included either as stand-alone text files, human-readable headers or\n";
        contenu += "   in the appropriate machine-readable metadata fields within text or\n";
        contenu += "   binary files as long as those fields can be easily viewed by the user.\n\n";
        contenu += "3) No Modified Version of the Font Software may use the Reserved Font\n";
        contenu += "   Name(s) unless explicit written permission is granted by the\n";
        contenu += "   corresponding Copyright Holder. This restriction only applies to the\n";
        contenu += "   primary font name as presented to the users.\n\n";
        contenu += "4) The name(s) of the Copyright Holder(s) or the Author(s) of the Font\n";
        contenu += "   Software shall not be used to promote, endorse or advertise any\n";
        contenu += "   Modified Version, except to acknowledge the contribution(s) of the\n";
        contenu += "   Copyright Holder(s) and the Author(s) or with their explicit written\n";
        contenu += "   permission.\n\n";
        contenu += "5) The Font Software, modified or unmodified, in part or in whole, must\n";
        contenu += "   be distributed entirely under this license, and must not be distributed\n";
        contenu += "   under any other license. The requirement for fonts to remain under\n";
        contenu += "   this license does not apply to any document created using the Font\n";
        contenu += "   Software.\n\n\n\n";
        contenu += "TERMINATION\n";
        contenu += "This license becomes null and void if any of the above conditions are not met.\n\n\n\n";
        contenu += "DISCLAIMER\n";
        contenu += "THE FONT SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND,\n";
        contenu += "EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO ANY WARRANTIES OF\n";
        contenu += "MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT\n";
        contenu += "OF COPYRIGHT, PATENT, TRADEMARK, OR OTHER RIGHT.  IN NO EVENT SHALL THE\n";
        contenu += "COPYRIGHT HOLDER BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,\n";
        contenu += "INCLUDING ANY GENERAL, SPECIAL, INDIRECT, INCIDENTAL, OR CONSEQUENTIAL\n";
        contenu += "DAMAGES, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING\n";
        contenu += "FROM, OUT OF THE USE OR INABILITY TO USE THE FONT SOFTWARE OR FROM OTHER\n";
        contenu += "DEALINGS IN THE FONT SOFTWARE.\n\n";
        if (!fichier.writeFile(contenu))
        {
            ErrorManager->errorCode(fichier.getErrorCode(), C_ErrorManager::ERROR_FILUS_MANAGERUS);
            return false;
        }
        contenu = "";
    #endif

    return true;
}

