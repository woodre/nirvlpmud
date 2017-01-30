inherit"/room/room";
#include <ansi.h>
 
reset(arg)
{
::reset(arg);
if(!present("buster", this_object()))move_object(clone_object("/players/wicket/tv/looney/mobs/buster.c"), this_object());
if(arg)return;
  set_light(1);
  short_desc = HIC+"Buster Bunny"+NORM+"\'"+HIC+"s"+YEL+" Den"+NORM;
  long_desc = " A huge whole in the ground that seems to have been carved out very well.\n\
  A unique blue bed with soft white sheets and a fluffy pillow fills part\n\
  of the den in one spot. Piles and piles of carrots are near a small\n\
  television set, A cozy little chair sits in front of the glowing tv,\n\
  a remote setting on the small arm of the chair. A little rug is placed\n\
  at the entrance of the den.\n";
  items = 
  ({
    "rug",
    "A small woven rug that is a soft blue color",
    "chair",
    "A cozy little chair with a small white blanket placed across the back of it",
    "carrots",
    "A HUGE pile of carrots that seems to be stored up for food",
    "bed",
    "A comfortable normal looking bed",
    "pillow",
    "A soft fluffy pillow that has a small indentation on it where it has been layed on",
    "tv",
    "A small tv used for entertainment when the owner is bored",
    "remote",
    "A complex remote used to control the tv and turn the channels",
    "chair",
    "A small comfortable chair",
  });
    dest_dir=({
  "/players/wicket/tv/looney/rooms/fieldofflower.c","up",
  });
  } 