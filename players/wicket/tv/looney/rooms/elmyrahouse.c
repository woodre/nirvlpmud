inherit"/room/room";
#include <ansi.h>
 
reset(arg)
{
::reset(arg);
if(!present("elmyra", this_object()))move_object(clone_object("/players/wicket/tv/looney/mobs/elmyra.c"), this_object());
if(arg)return;
  set_light(1);
  short_desc = HIC+"Elmyra "+HIW+"Duff "+NORM+"\'"+HIW+"s"+NORM+" House";
  long_desc = " A small cozy little house that is very well furnished. Soft fuzzy blue\n\
  carpet covers the floors. The windows have white edging around them\n\
  as the sun softly beams through lighting up the whole house. Animal\n\
  cages fill one side of the room with all kinds of small critters that\n\
  are scared to death. A chair is placed in front of the mantle that holds\n\
  a picture of Elmyra herself. A small table is next to the chair with a\n\
  small remote lying on it that controls the tv. Elmyra\'s bed is next to\n\
  the cages of animals so she can keep a close eye on them\n";
  items = 
  ({
    "cages",
    "A bunch of small cages that contains all kinds of small animals",
    "animals",
    "Small animals like rabbits and bear cubs that are scared to death of Elmyra",
    "picture",
    "A scary looking picture of Elmyra holding an animal squeezing it to death",
    "tv",
    "A small blue tv with a blank screen",
    "table",
    "A small table holding the remote for the tv",
    "bed",
    "A small bed next to the cages so Elmyra can sleep next to the animals to watch them",
    "remote",
    "A small remote to control the television",
  });
    dest_dir=({
  "/players/wicket/tv/looney/rooms/toonroad4.c","west",
  });
  } 