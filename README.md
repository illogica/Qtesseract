#Qtesseract

###What is this?

Qtesseract is a fork of the Tesseract game engine extended with the Qt5 libraries.
WARNING: this is pre-alpha code. Basically still just a bunch of experiments.

Currently the only features of this repo are:

* Ability *edit*, *build* and *debug* Tesseract using QtCreator IDE
* Build tested under Windows with mingw32 and MSVC2015
* Build tested under Linux (Fedora) with gcc 5.3.1
* Access to all Qt5 features
* Initial support for javascript by means of QJSEngine
* Automatic reloading of .js files - no server restart needed

###How does it work?

Take Tesseract source files, decouple some structs into separate classes. Have some
of these classes extend QObject. Add some Qt goodies here and there, be careful of what
you do or it's going to `SEGFAULT` with no mercy. Voilà, you have Qtesseract.

### How do I run it?
Install Qt5.6 or greater. Get yourself the latest and greatest QtCreator (4.x branch as of now).

The recommended way: git pull from inside QtCreator
- Launch QtCreator
- Choose File>New File or Project...>Import Project>Git Clone
- Enter the address of this repo (https://github.com/illogica/Qtesseract.git)
QtCreator will download and open the project for you.

####Compilation
- The very first time you open the project, click Build>Run QMake
- Press the "build" button on the bottom left (the one with the brown hammer) or use the "Build" menu.
Build WILL fail. Read through the "Issues" window what dependencies you are missing.
Reiterate this process until you fix all dependencies. (Yes, I know. I'm working on it.)

####Run
QtCreator needs a tiny configuration for this.
- Edit your *run* configuration (use the "Project" button). Make sure the "Working directory" is "[...]\Qtesseract", not "[...]\Qtesseract\bin"

- To run the client:
 - For Windows, in the "Command Line Arguments" field paste: `-u "$HOME\My Games\Tesseract"`
 - For Linux, in the "Command Line Arguments" field paste: `-u${HOME}/.tesseract`

- To run the server:
 - For both Linux and Windows,, in the "Command Line Arguments" field paste: `-d`

-Press the "Run" button (or Ctrl+r)

####Debug
Just press "Start Debugging" button (or F5).

### (TODO) Requirements
A part from the usual Tesseract dependencies, Qtesseract depends also on Qt5.
Qt version used as of this writing is 5.6.0

###License
All the files in this repository are released under the Zlib license

Copyright (C) 2016 Loris Pederiva

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
