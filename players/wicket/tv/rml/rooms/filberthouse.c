inherit"/room/room";
#include <ansi.h>
 
reset(arg)
{
::reset(arg);
if(!present("filbert", this_object()))move_object(clone_object("/players/wicket/tv/rml/mobs/filbert.c"), this_object());
  set_light(1);
  short_desc = "The House of"+HIK+"Filbert"+NORM+" the"+HIG+"Turtle"+NORM;
  long_desc = "		A small quiet little house where Filbert lives, it is all\n\
  nice neat and organized. It seems like everything has its proper place and\n\
  label. Everything is spotless and dustfree. The Cough is nice and orderly\n\
  with the pillows placed just right as well as the tv screen is dusted and\n\
  the antenna is placed just in the right way to pick up strong signals.\n";
  items = 
  ({
  "tv",
    "An old tv thats dust free and looks almost brand new",
    "couch",
    "The couch is well cleaned there is not even a wrinkle in the fabric",
    "pillows",
    "A nice set of pillows that have been placed just right one the couch",
   });
    dest_dir=({
  "/players/wicket/tv/rml/rooms/otownstreet2.c","west",
  });
  } 