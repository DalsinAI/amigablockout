BlockOut II 2.5 for AmigaOS 3.x
===============================

BlockOut II (Jean-Luc Pons, http://www.blockout.net/blockout2), the 3D
falling-blocks game after California Dreams' BlockOut (1989): turn and drop
the polycubes into the pit, seen from above, and fill whole layers. For
AmigaOS 3.x on a 68040 or 68060 with an FPU and an RTG screen, on OpenGPU's
SDL 1.2 (sdl12-compat) and OpenGL.

Base: bl25-src.tar.gz from SourceForge (sha256
3abf61c4a7bd921988596a2239d76a5800fc94d8fd84dcc82c720d4d4f84cf0f); the
game's data (data/: images, sounds, README.txt) from bl25-linux-x64.tar.gz
(sha256 f273f241a8f6db8ac7289e138a49bcb794a72b9272fba2b51b5f91d6d7963b48),
second commit; three of Debian's patches (blockout2 2.5+dfsg1-2), third.
Branch team2/blockout-amiga.

Status: builds; not yet run in the lab.


What you need
-------------

- A 68040 or 68060 with an FPU, AmigaOS 3.x, an RTG card (or the
  AmigaChrome lab).
- GFOpenUp 0.8.18 or later: opengpu.library, LIBS:OpenGPU/SDL2.module and
  GL.module. BlockOut II draws only with OpenGL: on AmigaChrome GL runs on
  the GPU; elsewhere it is Mesa's softpipe on the 68k, which is slow.


How to play
-----------

Open the BlockOut icon, or run BlockOut from a Shell. The game reads its
pictures and sounds from the drawer's data/ and keeps its setup and high
scores in user/ there. The online hall of fame is not there: its server
(blockout.net) is gone, and this build has no network.


Building
--------

    make -f amiga/Makefile.amigaos -j2 dist

with GFOpenAmigaGCC 16.2.0-open4, the OpenNDK headers, the OpenGPU kit and
the Team's static libpng and zlib (see the Makefile's head), and the host's
GStreamer (gst-launch-1.0) for the credits music. The drawer is
dist/BlockOut (and dist/BlockOut.info).


What was changed
----------------

- BlockOut/BlockOut.cpp: main() first moves into the drawer
  (amiga/amiga_start.c), and closes at exit the screens SDL2.module 0.6 can
  leave (amiga/amiga_screens.c). amiga/stack.c: 512 KB of stack.
- BlockOut/Utils.cpp, CheckEnv(): the data in PROGDIR:data and the setup
  and scores in PROGDIR:user (upstream: $BL2_HOME and ~/.bl2).
- BlockOut/SoundManager.cpp: the credits music is data/sounds/music.wav,
  IMA ADPCM made from upstream's music.ogg (amiga/tools/ogg2wav.py): the
  68k does not decode Vorbis.
- BlockOut/GLApp/GLApp.cpp: no $DISPLAY warning.
- ImageLib/src/png/hpng.c: on the Team's libpng 1.6 (png_jmpbuf, as
  Debian's ftbfs-with-libpng15 patch does), not the bundled libpng 1.2.
- amiga/http_none.cpp, built in place of BlockOut/Http.cpp: no network.
- amiga/sdl_mixer_lite.c (the Team's SDL_mixer 1.2 stand-in, WAV, with
  Mix_ReserveChannels added) and amiga/amiga_glu.c (gluPerspective,
  gluLookAt): the kit has no SDL_mixer 1.2 and no GLU.
- amiga/COPYING: the GPL 2 text (the source tarball has none).


Licences
--------

BlockOut II and its data: GPL 2 or later (COPYING.txt; upstream's
README-BlockOut.txt). The Amiga files (amiga/): the AmiCradle Team, GPL 2
or later; the SDL_mixer stand-in comes from the Team's Wizznic and
Gigalomania ports and is GPL 3 or later, so the program as built here is
GPL 3 or later.
