#include "/players/softly/closed/define.h"
#include "/players/softly/point/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc=(RED + "R" + NORM + "ocky " + RED + "P" + NORM + "oint");
long_desc ="   Footing is treacherous on the large slick boulders.\n"+
           "To the northeast a  red and white striped lighthouse is\n"+
           "supported by sturdy iron bracing.  The mist closes in\n"+
           "over the slippery rock surface and envelops the top of\n"+
           "the lighthouse.  The rocks continue to the northeast and\n"+
           "south.\n";

items = ({
  "boulders", "The grey black boulders are covered with algae and very wet",
  "bracing","The sturdy iron bracing anchors the lighthouse on the rocks",
  "sea","The blue-green sea stretches as far as the eye can see",
  "mist","The air is white with mist, which hangs heavily over\n"+
         "the sand and the surface of the sea.  It is warm and\n"+
         "dense, surrounding everything like a cloak",
  "lighthouse","The tall red and white striped lighthouse stands on\n"+
               "large boulders that rise from the sea.  It might be\n"+
               "reachable over the rocks",
  "surface","The surface is composed entirely of huge boulders\n"+
          "stacked to create a barrier against the sea",
  "rocks", "Large dark wet rocks dot the entire area",
  });
}

init()  {
 ::init();
add_action("northeast","northeast");
add_action("south","south");
}
south()  {
write("You slowly climb over the large slippery rocks.\n");
say(this_player()->query_name()+" moves south across the jetty.\n");
call_other(this_player(),"move_player","south#/players/softly/point/rooms/for16.c");
  return 1;
}

northeast() {
write("Careful of your footing, you make your way northeast across the jetty.\n");
say(this_player()->query_name()+" moves east across the jetty.\n");
call_other(this_player(),"move_player","northeast#/players/softly/point/rooms/pt5.c");
  return 1;
}
