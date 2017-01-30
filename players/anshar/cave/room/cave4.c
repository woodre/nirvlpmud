#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"

inherit "room/room";

reset(arg)
{
  if (arg) return 0;
  set_light(0);
  short_desc="A dark cave";
  long_desc=
"     A large underground cataract roars through this cave. Oversized\n\
pieces of cloth lay strewn about, and this seems a perfect place for\n\
taking a shower. Boulders are strewn about the area in a haphazard\n\
fashion.\n";
  items =
  ({
    "cataract",    "Water roars from the ceiling through a hole in the floor",
    "water",       "Water roars from the ceiling through a hole in the floor",
    "hole",        "A hole in the floor, it is very dark within",
    "cloth",       "Rags, towels, and discarded clothing. Very LARGE discarded clothing",
    "boulders",    "Boulders that appear to have been used for target practice with other boulders",
  });
  dest_dir =
  ({
    CROOM+"cave3", "west",
  });
}

init()
{
  ::init();
  add_action ("enter_hole", "enter");
}

enter_cave(str)
{
  if(!str) return 0;
  if(str != "hole")
  {
    write("Enter what?\n");
    return 1;
  }
  write("You plunge into the hole. Water crashes down on you, as you smash into rock.\n");
  this_player()->hit_player(50);
  this_player()->move_player("cave#"+CROOM+"water1");
  return 1;
}
