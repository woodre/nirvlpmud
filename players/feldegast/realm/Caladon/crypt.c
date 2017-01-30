/*
File: crypt.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 2/1/01
Description:
  Barony of Caladon, Crypt in the graveyard
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  ::reset(arg);
  if(!present("revenant"))
    move_object(clone_object(MON_PATH+"revenant.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc="Crypt";
  long_desc=
"  This is a large square room, ten feet wide, ten feet long, and ten\n\
feet tall.  The walls, ceiling, and floor have all been scratched and\n\
marked as though something were attempting to escape.\n";
  items=({
    "room", "reflexive",
    "walls", "They have all been scratched and scraped, but appear to\n"+
             "remain solid",
    "ceiling", "It has been scratched and scraped, but appears to\n"+
               "remain solid",
    "floor", "It has been scratched and scraped, but appears to\n"+
             "remain solid",
  });
  dest_dir=({
    PATH+"3x7.c","out",
  });
}

  