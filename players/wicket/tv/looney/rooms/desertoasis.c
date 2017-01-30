inherit"/room/room";
#include <ansi.h>
 
reset(arg)
{
::reset(arg);
if(!present("condor", this_object()))move_object(clone_object("/players/wicket/tv/looney/mobs/condor.c"), this_object());
if(arg)return;
  set_light(1);
  short_desc = "A Small "+HIY+"Desert Canyon "+HIC+"Oasis"+NORM;
  long_desc = " A small desert canyon oasis that provides some protection from the heat.\n\
  A small pool of water is in the middle of the oasis. The oasis is filled\n\
  with huge palm trees. Foliage of all kinds fills the ground around the\n\
  oasis. Small fruits grow on the small bushes around the area and small\n\
  coconuts are all over the ground where they have dropped from the palm \n\
  trees.\n";
  items = 
  ({
    "pool",
    "A small pool of sparkling clear water",
    "water",
    "A small pool of sparkling clear water",
    "trees",
    "Massive palm trees that are shade the area and producing food",
    "foliage",
    "Small tropical plants that line the floor around the oasis",
    "trees",
    "Huge palm trees that provide shade to the oasis",
    "fruits",
    "Delicious fruits that grow on the bushes to provide food to the wildlife",
    "coconuts",
    "Small coconuts lying all over the ground that fell from the palm trees",
    "foliage",
    "All kinds of small bushes and plants that fill the oasis floor",
  });
    dest_dir=({
  "/players/wicket/tv/looney/rooms/canyon.c","south",
  });
  } 