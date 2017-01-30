#include "/players/softly/closed/define.h"
#include "/players/softly/point/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc=(RED + "R" + NORM + "ocky " + RED + "P" + NORM + "oint");
long_desc ="  A tall lighthouse painted in a spiral of red and white,\n"+
           "towers overhead.  At its base it seems to expand into a\n"+
           "tiny house.  The door stands slightly ajar.  Footing is\n"+
           "treacherous on the large slick boulders that continue\n"+
           "to the southwest.  Mist hides the top of the lighthouse\n"+
           "and the sea.\n";

items = ({
  "boulders", "The grey black boulders are covered with algae and very wet",
  "sea","The blue-green sea stretches as far as the eye can see",
  "mist","The air is white with mist, which hangs heavily over\n"+
         "the sand and the surface of the sea.  It is warm and\n"+
         "dense, surrounding everything like a cloak",
  "lighthouse","The tall red and white striped lighthouse stands on\n"+
               "iron bracing and large boulders that rise from the sea",
  "house","A tiny white house seems to emerge from the base of the\n"+
          "lighthouse.  The windows have white curtains and the door\n"+
          "stands slightly ajar",
  "door","A weathered door that was once painted brick red is\n"+
         "in the center of the tiny house.  The brass knocker\n"+
         "has weathered gracefully.  The door is slightly open",

  });
dest_dir = ({
  "/players/softly/point/rooms/lh1.c","enter",
  });
}

init()  {
 ::init();
add_action("southwest","southwest");
}
southwest()  {
write("You slowly climb over the large slippery rocks.\n");
say(this_player()->query_name()+" moves southwest across the jetty.\n");
call_other(this_player(),"move_player","southwest#/players/softly/point/rooms/pt4.c");
  return 1;
}
