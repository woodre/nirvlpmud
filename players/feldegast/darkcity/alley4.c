#include "def.h"
inherit MYROOM;
reset(arg) {
  if(!present("rain"))
    move_object(clone_object(PATH+"Npc/mrrain"),this_object());
  if (arg) return;
  set_light(0);
  set_pk(1);
  short_desc="An Alley";
  long_desc=
"     Shadows thankfully obscure most of the trash that litters this\n\
alley between two tall buildings.  Fire escapes crawl up the sides of\n\
the buildings like urban lichen.  The two buildings on either side of\n\
this alley are uncomfortably close.\n";
  items=({
    "shadows","There is a street lamp just outside the alley, but\n"+
              "it cannot seem to penetrate the thick shadows of\n"+
              "this city",
    "trash","You can't see it through the shadows",
    "street","A crowded street thick with cars",
    "fire escapes","They zig-zag up the side of the buildings, yet stay well\n"+
                   "above your reach",
    "buildings","For a split second, it seems as though the two buildings are\n"+
                "coming closer and closer"
  });
  dest_dir=({
    PATH+"street9","east"
  });
}   
