#include "/players/softly/closed/define.h"
#include "/players/softly/point/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(!present("bird")) 
  move_object(clone_object("players/softly/point/mobs/bird.c"),this_object());
  if(arg) return;

set_light(1);

short_desc = RED + "R" + NORM + "ocky" + RED + " P" + NORM + "oint";
long_desc ="  At water's edge the sand is rocky.  Many large boulders\n"+
           "to the north support a red and white striped lighthouse.\n"+
           "Eastward a long rock jetty juts out into the sea, the\n"+
           "end shrouded in mist.  Northwest is a weathered boardwalk.\n";

items = ({
  "boulders","The wet dark brown boulders are stacked high to create\n"+
             "a long jetty.  It stretches into the mist",   
  "sand", "The pale grey sand ends at the water's edge",
  "sea","The blue-green sea stretches as far as the eye can see",
  "mist","The air is white with mist, which hangs heavily over\n"+
         "the sand and the surface of the sea.  It is warm and\n"+
         "dense, surrounding everything like a cloak",
  "lighthouse","The tall red and white striped lighthouse stands on\n"+
               "large bounders that rise from the sea.  It might be\n"+
               "reachable over the rocks",
  "jetty","The broad jetty is composed entirely of huge boulders\n"+
          "stacked to create a barrier against the sea.  The top\n"+
          "is very broad and flat",
  "boardwarlk","Grey weathered boards rise from the sand to create a path",
  "water","Waves crash into the sand where the blue-green sea\n"+
          "meets the pale grey sand",

  });
dest_dir = ({
  "/players/softly/point/rooms/for11.c","southwest",
  "/players/softly/point/rooms/pt6.c","northwest",
  });
}

init()  {
 ::init();
add_action("north","north");
add_action("east","east");
}
north()  {
write("You slowly climb over the large slippery rocks\n");
say(this_player()->query_name()+" moves north across the rocks.\n");
call_other(this_player(),"move_player","north#/players/softly/point/rooms/pt4.c");
  return 1;
}

east() {
write("Careful of your footing, you make your way east across the jetty.\n");
say(this_player()->query_name()+" moves east across the jetty\n");
call_other(this_player(),"move_player","east#/players/softly/point/rooms/pt1.c");
  return 1;
}
