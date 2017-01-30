#include "../def.h"

inherit "/room/room";

reset(arg)
{
  if(arg) return;
  set_light(1);
  set_short("Dojo - Armory");
  set_long("\
Dojo - Armory\n\
In the armory, you are surrounded by glinting mail armors\n\
and wakizashis, katanas, and naginatas of various sizes.\n\
A few discarded bows rest in the corner. You see a staircase\n\
leading upstairs.\n");
  items = ({
  });
  dest_dir = ({
    ROOMDIR+"dojo_musashi","up",
    ROOMDIR+"dojo_sc","west",
  });
}

init() {
  ::init();
 add_action("up","up");
}

up(){
  if((ROOMDIR+"dojo_musashi")->query_cnt()) {
    write("You can't enter while someone else is in there.\n");
    return 1;
  }
}
