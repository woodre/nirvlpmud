inherit"/room/room";
#include <ansi.h>
 
reset(arg)
{
::reset(arg);
if(!present("rocko", this_object()))move_object(clone_object("/players/wicket/tv/rml/mobs/rocko.c"), this_object());
if(!present("spunky", this_object()))move_object(clone_object("/players/wicket/tv/rml/mobs/spunky.c"), this_object());
if(arg)return;
  set_light(1);
  short_desc = "A Small House in"+HIR+" O"+NORM+"\-"+RED+"Town"+NORM;
  long_desc = " A small quiet little house, this seems to be the place where Rocko \n\
  lives and hangs out with his friends. Their is a small comfortable\n\
  couch sitting next to the window with a blanket thrown across the back\n\
  of it. Directly across the room is a small tv with a pair of rabbit ears\n\
  sitting on top of it. A small circular rug is in the center of the floor\n\
  for decoration.\n";
  items = 
  ({
    "tv",
    "A small old tv that looks like a piece of junk",
    "rub",
    "A round dusty rug that just lays on the floor for decoration",
    "couch",
    "An old beat up and worn out couch",
    "blanket",
    "A nice warm blanket that is tossed on the couch to cover up stains",
  });
   dest_dir=({
  "/players/wicket/tv/rml/rooms/otownstreet1.c","east",
  });
  } 