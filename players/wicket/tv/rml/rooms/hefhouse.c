inherit"/room/room";
#include <ansi.h>
 
reset(arg)
{
::reset(arg);
if(!present("heffer", this_object()))move_object(clone_object("/players/wicket/tv/rml/mobs/heffer.c"), this_object());
  set_light(1);
  short_desc = "The House of"+HIR+" Heffer "+HIY+"Wolfe"+NORM;
  long_desc = "        A small quiet little house where Heffer lives, there is trash \n\
  and empty bags all over the place. Flies are all over the house because\n\
  they are attracted by the filth and smell of the place. Old bags and other\n\
  things are just scattered everywhere around the house. The only reasonable\n\
  place to even rest is the recliner that is placed in front of the tv. The\n\
  tv has been left on and all of the lights in the house are on.\n";
  items = 
  ({
  "trash",
    "Piles and piles of emtpy snack containers and bags",
    "flies",
    "Flies that ae flying around those house from the trash",
    "recliner",
    "An old warn out comfortable recliner",
    "tv",
    "An old tv with a set of rabbit ears on top of it",
  });
    dest_dir=({
  "/players/wicket/tv/rml/rooms/otownstreet1.c","west",
  });
  } 