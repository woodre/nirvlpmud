inherit "room/room";
#include "/players/illarion/dfns.h"

reset(arg) {
  if(!present("Adam Pierson",this_object()))
    move_object(clone_object(HMON+"pierson"),this_object());
  if(arg) return;

  set_light(1);
  short_desc="A modern kitchen";
  long_desc=
"All the conveniences of a kitchen surround you, packed just closely enough\n"+
"to become inconvenient again.  Counters border a strip of tile to the north\n"+
"and south.  To the south is a sink, with a cabinet hung above, and to the\n"+
"south is a stove and oven, seperated by a brief stretch of counter from a\n"+
"refrigerator.  To the east are the elevator and the stairs, and to the west\n"+
"the kitchen ends at a window.\n";

  items= ({
    "kitchen","It's small, but fairly nice",
    "counters","A light shade of grey, setting off the tile well",
    "tile","Just slightly off-white, and spotless",
    "sink","A large metal sink for dishes and pans",
    "cabinets","The cabinets are expertly made, with perfectly hung doors",
    "stove","Four eyes of varying size.  One of the coils catches your\n"+
            "attention",
    "coil","The spiral pattern is mesmerizing, creating a mild compusion to\n"+
           BLD("gaze")+" at it",
    "oven","Uually used to cook things at high temperatures",
    "elevator","Usually these go up and down, but this one doesn't move",
    "window","Mostly covered by curtains, but gives a partial view of an alley",
  });
  dest_dir= ({
    HROOM+"loftent","east",
  });
}
/* function to change the window description.  called by high/mon/pierson */
break_window() {
  int n;
  n=member_array("window",items);
  if(n!=-1)
    items[n+1]="This window overlooks an alleyway below.  Somehow, the\n"+
               "window has gotten broken from the inside, and the curtains\n"+
               "ripped along with it";
}
init() {
  ::init();
  add_action("cmd_gaze","gaze");
}

cmd_gaze(string str) {
  if(str != "at coil") FAIL("Gaze at what?\n");
  write("You gaze at the coil for a while, and your surroundings suddenly change!\n");
  say(TPN+" spends some quality time looking at the stove.\n");
  TP->move_player("into a shimmer in reality#"+HROOM+"mhall_audience");
  return 1;
}
