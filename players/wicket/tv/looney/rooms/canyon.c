inherit"/room/room";
#include <ansi.h>
 
reset(arg)
{
::reset(arg);
if(!present("beeper", this_object()))move_object(clone_object("/players/wicket/tv/looney/mobs/beeper.c"), this_object());
if(!present("calamity", this_object()))move_object(clone_object("/players/wicket/tv/looney/mobs/calamity.c"), this_object());
if(arg)return;
  set_light(1);
  short_desc = "A Small "+HIY+"Desert Canyon"+NORM;
  long_desc = " A small desert canyon that has sun beating down from the sky. The heat\n\
  is very intense. Small cacti and desert grass grows in random areas\n\
  in the canyon. Massive rocks and boulders fill the edge of the very\n\
  top of the cliffs. Down below the bottom of the canyon floor can hardly\n\
  be seen. Sounds of the desert wildlife echo through the area. Roadrunner\n\
  tracks and coyote tracks can be seen in the sand. To the north a desert\n\
  oasis can be seen.\n";
  items = 
  ({
    "tracks",
    "Coyote and roadrunner tracks are all over the floor of the desert canyon",
    "rocks",
    "Rocks of all shapes and sizes line the sand",
    "boulders",
    "Massive desert boulders sit in the sand with cracks all over them",
    "cacti",
    "Small cactus with a pink flow on top of them",
    "grass",
    "Small patches of grass growing on the dry desert floor",
    "cliffs",
    "Small cliffs on the walls of the desert canyon",
    "oasis",
    "A small desert oasis off in the distance",
  });
    dest_dir=({
  "/players/wicket/tv/looney/rooms/toonroad4.c","south",
  "/players/wicket/tv/looney/rooms/desertoasis.c","north",
  });
  } 