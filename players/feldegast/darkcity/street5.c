#include "def.h"

inherit MYROOM;

reset(arg) {
  if (arg) return;
  set_light(1);
  set_pk(1);
  short_desc=HIB+"Dark City"+NORM;
  long_desc=
"     Shadows rule this city of darkness and mystery.  This crowded\n\
street is filled with shops closed down for the perpetual night.\n\
Skyscrapers from different eras of history block the skyline, making\n\
you doubt whether or not there is an end to these maze-like streets.\n\
A flight of stairs leads down into the subway.\n";
  items=({
    "shadows","Inky blots of darkness spread by the occasional streetlight",
    "street","Dark-hued cars roll through the streets of the city",
    "shops","Pawn shops, toy stores, repair shops, barber shops, everything you\n"+
            "can imagine, but none of it is open",
    "skyscrapers","Bleak edifices of humanity's achievements block the sky as far\n"+
                  "as you can see",
    "skyline","Buildings, large and small, as far as you can see",
    "stairs","They lead down into the subway"
  });
  dest_dir=({
    PATH+"street6","north",
    PATH+"street4","west",
    PATH+"subway","down"
  });
  set_config(call_other(PATH+"controller","query_config"));
}   

void set_config(int arg) {
  switch(arg) {
    case 0:
      dest_dir=({
        PATH+"street6","north",
        PATH+"street4","west",
        PATH+"subway","down"
      });
      break;
    case 1:
      dest_dir=({
        PATH+"street4","west",
        PATH+"subway","down"
      });
      break;
    case 2:
      dest_dir=({
        PATH+"street4","north",
        PATH+"street9","east",
        PATH+"subway","down"
      });
      break;
    case 3:
      dest_dir=({
        PATH+"street6","east",
        PATH+"subway","down"
      });
  }
}
