inherit"/room/room";
#include <ansi.h>
 
reset(arg)
{
::reset(arg);
if(!present("sweetie", this_object()))move_object(clone_object("/players/wicket/tv/looney/mobs/sweetie.c"), this_object());
if(arg)return;
  set_light(1);
  short_desc = "A Small "+HIK+"Road "+NORM+"in "+HIC+"Tiny"+HIW+" Toon"+HIC+" Town"+NORM+"";
  long_desc = " A small simple road leading into tiny toon town. Off to the west of the\n\
  road a small field can be seen. A huge mansion sits up on top of the hill.\n\
  Gates made of solid gold protect the house. To the east of the road a small\n\
  field of flowers can be seen. Wildlife wanders all about the field and sounds\n\
  echo from the field. The road continues north deeper into the town or south\n\
  back to the entrance of toon land.\n";
  items = 
  ({
    "mansion",
    "A Huge mansion with solid gold gates around them",
    "gates",
    "Solid golden gates that surround a mansion and they appear to be open",
    "field",
    "A field with a lot of flowers and wildlife",
  });
   dest_dir=({
  "/players/wicket/tv/looney/rooms/tinyentrance.c","south",
  "/players/wicket/tv/looney/rooms/montanamansion.c","west",
  "/players/wicket/tv/looney/rooms/fieldofflower.c","east",
  "/players/wicket/tv/looney/rooms/toonroad2.c","north",
  });
  } 