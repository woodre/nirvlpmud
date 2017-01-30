#include "/players/catacomb/misc/ansi.h"
inherit "room/room";

reset(arg) 
{
  if(arg) return;
  set_light(1);

  short_desc ="Kami's Lookout" ;
  long_desc =(
  " A calm breeze flows through the lookout, bringing about a sense\n"+
  "of tranquility.  Clouds form miscellaneous shapes under the\n"+
  "lookout.  Stairs lead up to a small building.  To the east is \n"+
  "the center of the lookout.\n"); 

  items = ({
    "shapes",
    "The clouds float by forming different shapes",
    "cloud",
    "Thin layers of clouds float by",
    "clouds",
    "Thin wispy clouds are all that can be seen under the lookout",
    "building",
    "The building rests at the top of the stairs",
    "stairs",
    "The marble stairs lead gradually up to a small building"
    
  });

  dest_dir = ({
    "/players/catacomb/saiyan/donation.c","stairs",
    "/players/catacomb/saiyan/lookout1.c","east" 
  });
  
}

