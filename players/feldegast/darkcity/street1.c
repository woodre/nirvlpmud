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
To the north is a huge sign.\n";
  items=({
    "shadows","Inky blots of darkness spread by the occasional streetlight",
    "street","Dark-hued cars roll through the streets of the city",
    "shops","Pawn shops, toy stores, repair shops, barber shops, everything you\n"+
            "can imagine, but none of it is open",
    "skyscrapers","Bleak edifices of humanity's achievements block the sky as far\n"+
                  "as you can see",
    "skyline","Buildings, large and small, as far as you can see",
    "sign","The sign is an advertisement for Shell Beach.  There is an alleyway\n"+
           "beneath the sign",
    "alleyway","It is too dim to see inside"
  });
  dest_dir=({
    PATH+"alley1","north",
    PATH+"street2","east"
  });
  set_config(call_other(PATH+"controller","query_config"));
}   

void set_config(int arg) {
  switch(arg) {
    case 0: dest_dir=({
              PATH+"alley1","north",
              PATH+"street2","east",
            });
            break;
    case 1: dest_dir=({
              PATH+"alley1","north",
              PATH+"street2","east",
              PATH+"street9","south",
            });
            break;
    case 2: dest_dir=({
              PATH+"alley1","north",
              PATH+"street7","west",
              PATH+"street2","east",
            });
            break;
    case 3: dest_dir=({
              PATH+"alley1","north",
              PATH+"street2","east",
            });
            break;
    default:  dest_dir=({
                PATH+"alley1","north",
                PATH+"street2","east",
              });
  }
}
