inherit"/room/room";
#include <ansi.h>
 
reset(arg)
{
::reset(arg);
  set_light(1);
  short_desc = "A nice quiet"+HIK+" Road "+NORM+"in "+HIR+"O"+NORM+" \-"+HIR+" Town"+NORM;
  long_desc = "  A small quiet street in O\-town where every thing seems to move along at\n\
  a nice slow calm pace. The air is warm and relaxing, the birds singing away\n\
  in the nice warm sun. It is a nice small neighborhood with houses down each\n\
  side of the street. The grass in the yards are neatly trimed and the bushes\n\
  are well rounded. To the south you can see the entrance to town and to the\n\
  north you can see deeper into town\n";
  items = 
  ({
  "birds",
    "A variety of song birds flying around chirping",
    "house",
    "Small cute little house in a quiet neighborhood",
    "grass",
    "Well tended grass that has a smooth green color to it",
    "sun",
    "The bright warm sun that seems to shine bright and warm",
    "street",
    "a well maintaned and clean road where people walk and drive",
  });
    dest_dir=({
  "/players/wicket/tv/rml/rooms/otownstreet1.c","south",
  "/players/wicket/tv/rml/rooms/filberthouse.c","east",
  });
  } 