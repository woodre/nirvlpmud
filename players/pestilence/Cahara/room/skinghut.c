#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

short_desc = ""+YEL+"King Kidema's Hut"+NORM+"";
long_desc =
  "    Bones fill this room.  Corpses from past victories and meals have been\n"+
  "discarded here.  The room is very full, with little room to move within it.  One\n"+
  "could feel a sense a feeling of uneasiness.  It's almost as if there is a feeling\n"+
  "that many of the corpses were thrown in here while they were still alive.\n";
set_light(1);

items = ({

});

dest_dir = ({
  "/players/pestilence/Cahara/room/kinghut.c","north",
});

}
