TEMPLATE = app

TARGET = tesseract

CONFIG += object_parallel_to_source
CONFIG += warn_off
CONFIG += rtti_off
CONFIG += exceptions_off

CONFIG += c++14

contains(QMAKESPEC, "g++"){

    win32 { #statinc linking for mingw builds
        QMAKE_LFLAGS += -static-libgcc -static-libstdc++
    }

    QMAKE_CFLAGS += -Wall
    QMAKE_CXXFLAGS += -Wall
    QMAKE_CXXFLAGS_RELEASE -= -O2
    QMAKE_CXXFLAGS_RELEASE += -O3 -fomit-frame-pointer -ffast-math -fsigned-char
}

RC_FILE += $$PWD/src/vcpp/mingw.rc

QT += gui network sql

DEFINES -= UNICODE

INCLUDEPATH += src/engine \
        src/game \
        src/shared \
        "src/include" \
        "src/enet/include" \
        bin

unix{
    libenet.commands = cd $$PWD/src/enet && $(MAKE) -f Makefile

    QMAKE_EXTRA_TARGETS += libenet
    PRE_TARGETDEPS += libenet

    DESTDIR = $$PWD/bin_unix
    INCLUDEPATH += -I/usr/X11R6/include
    QMAKE_CXXFLAGS +=  `sdl2-config --cflags`

    LIBS += -L$$PWD/src/enet -lenet
    LIBS += -L/usr/X11R6/lib -lX11 `sdl2-config --libs` -lSDL2_image -lSDL2_mixer -lz -lGL -lrt
}

win32 {

    CONFIG += windows

    !contains(QMAKE_TARGET.arch, x86_64) {

        ## Windows x86 (32bit) specific build here
        DESTDIR = $$PWD/bin

        LIBS += "$$PWD/src/lib/enet.lib"# -lenet
        LIBS += "$$PWD/src/lib/SDL2.lib" # -lSDL2
        LIBS += "$$PWD/src/lib/SDL2_image.lib"# -lSDL2_image
        LIBS += "$$PWD/src/lib/SDL2_mixer.lib"# -lSDL2_mixer
        LIBS += "$$PWD/src/lib/zdll.lib"# -lzdll

    } else {

        ## Windows x64 (64bit) specific build here
        DESTDIR = $$PWD/bin64

        LIBS += "$$PWD/src/lib64/enet.lib"# -lenet
        LIBS += "$$PWD/src/lib64/SDL2.lib" # -lSDL2
        LIBS += "$$PWD/src/lib64/SDL2_image.lib"# -lSDL2_image
        LIBS += "$$PWD/src/lib64/SDL2_mixer.lib"# -lSDL2_mixer
        LIBS += "$$PWD/src/lib64/zdll.lib"# -lzdll
    }


    LIBS += -lopengl32
    LIBS += -lws2_32
    LIBS += -lwinmm
    LIBS += -lkernel32
    LIBS += -luser32
}

SOURCES += src/shared/crypto.cpp \
    src/shared/geom.cpp \
    src/shared/glemu.cpp \
    src/shared/stream.cpp \
    src/shared/tools.cpp \
    src/shared/zip.cpp \
    src/engine/aa.cpp \
    src/engine/bih.cpp \
    src/engine/blend.cpp \
    src/engine/client.cpp \
    src/engine/command.cpp \
    src/engine/console.cpp \
    src/engine/dynlight.cpp \
    src/engine/grass.cpp \
    src/engine/light.cpp \
    src/engine/main.cpp \
    src/engine/material.cpp \
    src/engine/menus.cpp \
    src/engine/movie.cpp \
    src/engine/normal.cpp \
    src/engine/octa.cpp \
    src/engine/octaedit.cpp \
    src/engine/octarender.cpp \
    src/engine/physics.cpp \
    src/engine/pvs.cpp \
    src/engine/rendergl.cpp \
    src/engine/renderlights.cpp \
    src/engine/rendermodel.cpp \
    src/engine/renderparticles.cpp \
    src/engine/rendersky.cpp \
    src/engine/rendertext.cpp \
    src/engine/renderva.cpp \
    src/engine/server.cpp \
    src/engine/serverbrowser.cpp \
    src/engine/shader.cpp \
    src/engine/sound.cpp \
    src/engine/stain.cpp \
    src/engine/texture.cpp \
    src/engine/ui.cpp \
    src/engine/water.cpp \
    src/engine/world.cpp \
    src/engine/worldio.cpp \
    src/game/ai.cpp \
    src/game/entities.cpp \
    src/game/game.cpp \
    src/game/render.cpp \
    src/game/scoreboard.cpp \
    src/game/server.cpp \
    src/game/waypoint.cpp \
    src/game/weapon.cpp \
    src/game/client.cpp
#    src/qt/hooks.cpp

HEADERS +=  src/shared/cube.h \
    src/shared/glemu.h \
    src/shared/tools.h \
    src/shared/geom.h \
    src/shared/ents.h \
    src/shared/command.h \
    src/shared/glexts.h \
    src/shared/iengine.h \
    src/shared/igame.h \
    src/engine/engine.h \
    src/engine/world.h \
    src/engine/octa.h \
    src/engine/light.h \
    src/engine/texture.h \
    src/engine/bih.h \
    src/engine/model.h \
    src/engine/animmodel.h \
    src/engine/explosion.h \
    src/engine/hitzone.h \
    src/engine/iqm.h \
    src/engine/lensflare.h \
    src/engine/lightning.h \
    src/engine/md2.h \
    src/engine/md3.h \
    src/engine/md5.h \
    src/engine/mpr.h \
    src/engine/obj.h \
    src/engine/ragdoll.h \
    src/engine/scale.h \
    src/engine/skelmodel.h \
    src/engine/smd.h \
    src/engine/textedit.h \
    src/engine/vertmodel.h \
    src/game/game.h \
    src/game/ai.h \
    src/game/ctf.h \
    src/game/extinfo.h \
    src/game/aiman.h
#   src/qt/hooks.h









