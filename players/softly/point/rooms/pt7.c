#include "/players/softly/closed/define.h"
#include "/players/softly/point/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(!present("hull")) 
  move_object(clone_object("players/softly/point/obj/hull.c"),this_object());
  if(!present("bird")) 
  move_object(clone_object("players/softly/point/mobs/bird.c"),this_object());
  if(!random(2))move_object(clone_object("players/softly/point/mobs/bird.c"),this_object());
  if(arg) return;

set_light(1);

short_desc=(RED + "R" + NORM + "ocky " + RED + "P" + NORM + "oint Harbor");
long_desc ="  A weathered grey boardwalk passes over the rocky sand\n"+
           "creating a stable surface to walk on.  A soft mist rolls\n"+
           "in from the sea as it gently laps the rocky sand. \n";

items = ({
  "sand", "The pale grey sand ends at the water's edge",
  "sea","The blue-green sea stretches as far as the eye can see",
  "mist","The air is white with mist, which hangs heavily over\n"+
         "the sand and the surface of the sea.  It is warm and\n"+
         "dense, surrounding everything like a cloak",
  "lighthouse","The tall red and white striped lighthouse stands on\n"+
               "large boulders that rise from the sea.  It might be\n"+
               "reachable over the rocks",
  "boardwalk","Grey weathered boards rise from the sand to create a path",


  });
dest_dir = ({
  "/players/softly/point/rooms/pt6.c","east",
  "/players/softly/point/rooms/h1.c","enter",
  });
}

