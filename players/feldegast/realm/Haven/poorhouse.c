#include "../def.h"
inherit "room/room";
reset(arg) {
  if(!present("box")) {
    move_object(clone_object("/players/feldegast/obj/dbox"));
  }
  if (arg) return;
  set_light(1);
  short_desc="The Poorhouse";
  long_desc=
"    This decrepit building is the only home for many of\n"+
"the poorer residents of Haven.  In back are a row of cots\n"+
"with threadbare blankets on them.  Cracked mortar and bits\n"+
"of ceiling are sprinkled across the floor.\n";
  items=({
    "residents","The poorhouse is mostly empty right now due to a booming\n"+
                "economy and a good ruler",
    "cots","Simple wooden cots with threadbare blankets on them",
    "mortar","You get the feeling this building isn't well maintained",
    "ceiling","It probably leaks when it rains"
  });
  dest_dir=({
    PATH+"Haven/copper1","east"
  });
}   
