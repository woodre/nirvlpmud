#include "def.h"

inherit MYROOM;

reset(arg) {
  if(!present("stranger"))
    move_object(clone_object(PATH+"Npc/mrhand"),this_object());
  if (arg) return;
  set_light(0);
  short_desc=BLU+"Underworld"+NORM;
  long_desc=
"     The labyrinthine depths of this underworld are filled with\n\
technological wonders beyond humanity's ability to recreate.  A\n\
shadowy bridge extends across a yawning abyss cloaked in darkness\n\
and ends in a gigantic archway leading into the inner caverns of this\n\
structure.\n";
  items=({
    "wonders","These corridors appear to riddle the framework of some\n"+
              "gargantuan machine whose purpose remains unknown",
    "corridor","The corridor leads through the great machine",
    "bridge","The bridge extends twenty yards across a yawning abyss",
    "abyss","You can make out odd pinpoints of light at a great distance\n"+
            "deep inside the abyss",
    "archway","The archway is wide enough for half a dozen men to walk\n"+
              "through it standing side by side"
  });
  dest_dir=({
    PATH+"ug3","north",
    PATH+"ug1","south"
  });
}   

init() {
  ::init();
  add_action("cmd_north","north");
}

cmd_north() {
  if(present("hand")) {
    write("Mr. Hand says: I can't let you pass.\n");
    say("Mr. Hand blocks "+TPN+".\n");
    return 1;
  }
}
