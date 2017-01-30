#include "def.h"

inherit ROOM;

reset(arg) {
  if(!present("tree"))
    move_object(clone_object(PATH+"obj/great_tree"),this_object());
  if(arg)return;
  set_no_teleport(1);
  set_light(1);
  no_clean = 1;
  short_desc=GRN+"Healer's Grove"+NORM;
  long_desc=
    "  Confined within the walls of the healer compound, beautiful trees still\n"+
    "thrive in this grove.  In the center of the grove, the trees form\n"+
    "a circle around one immense tree which rises high up above the compound\n"+
    "walls.  To the south, a wooden porch leads inside.\n";
  items=({
    "grove","reflexive",
    "walls","You can see the walls of the castle to the north and to\n"+
            "the east",
    "trees","Maybe three of four dozen trees of several varieties make up this\n"+
            "grove",
    "porch","A wooden porch is attached the the stone walls of the healer hall, where\n"+
            "healers can sit and rest a while",
  });
  dest_dir=({
    ROOMPATH+"garden1","west",
    ROOMPATH+"east_hall","south",
  });
}

