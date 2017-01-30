#include "/players/softly/misc/ansi.h"

inherit "/room/room";

reset(arg) {
  if(!present("box")) {
  move_object(clone_object("players/softly/winter/srbox"),this_object());
  }

  if(arg) return;
set_light(1);

short_desc = "Frozen Lake Edge";
long_desc ="  A blindingly bright frozen lake is nestled in a ring of dying\n"+
           "trees.  The air is very cold.  To the north is the lake surface.\n"+
           "A small shack is visible to the west.  A trail enters a forest\n"+
           "to the south.  Eastward there is a great deal of debris, but it\n"+
           "might be possible to get through it.\n";

items = ({
  "trail", "A slippery forest trail continues downward to the south",
  "trees", "Although evergreens remain, the leafless dying branches\n"+
           "of once healthy trees dominate the landscape",
  "forest","The southern forest is has many pine and oak trees.  It\n"+
           "seems very old with a few breaks in the trees",
  "lake",  "The ice is quite thick covering the surface of the solidly\n"+
         "frozen lake",
  "air",   "The air is frigid",
  "debris","Broken branches and brambles cover what was once a trail",
  "shack", "A small shack has smoke rising above it.  It bears investigating",
  });

dest_dir = ({
  "/players/softly/winter/rooms/pond6.c","north",
  "/players/softly/winter/rooms/pond11.c","east",
  "/players/softly/winter/rooms/for3.c","south",
  "/players/softly/winter/rooms/pond2.c","west",
  });
}
status skates_check()
{
    int x;
    object *inv;
    inv = all_inventory(this_player());
    for(x = 0; x < sizeof(inv); x ++)
    {
      if(inv[x]->id("ice skates"))
      write("You think to yourself 'I should return these skates.'\n");
    }
    return 1;
}
