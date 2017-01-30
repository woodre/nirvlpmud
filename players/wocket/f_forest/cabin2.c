#include "/players/wocket/closed/ansi.h"
#include "defs.h"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
  if(arg) return;
  short_desc = "A log cabin";
  long_desc = "   "+
     YEL+"The bedroom to this log cabin.  There is a dresser along the \n"+
         "east wall and a window that faces to the north.  A small fire\n"+
         "burns in a fireplace along the west all.  The large bed takes\n"+
         "up the rest of the room.  Oak pillars attach the bed from to \n"+
         "floor, spirling up to the ceiling.  It is nice and warm here.\n"+OFF;
  dest_dir = ({
    DIR+"cabin1.c","west",
  });
  items = ({
    "walls","They are old and grey logs from the forest",
    "celing","They are old and grey logs from the forest",
    "floor","It is very smooth soft packed dirt",
    "fire","It burns softly in the fireplace",
    "fireplace","An old rock fireplace, set into the wall",
    "bed","A large soft bed",
    "dresser","It is finely carved with a large mirror above it",
  });
  smells = ({ "default","You smell pine of the logs", });
  listens = ({ "default","You hear the living forest outside",});
  set_light(1);
}

init(){
  ::init();
  add_action("mirror_look","look");
  add_action("mirror_look","l");
}

mirror_look(str){
  if(str == "at mirror"){
    write(BOLD+"You look into the mirror and see:\n\n"+OFF);
    command("look at "+this_player()->query_real_name(),this_player());
    return 1;
  }
  return 0;
}