#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"

inherit "room/room";

reset(arg)
{
  if (arg) return 0;
  set_light(0);
  short_desc="A dark cave";
  long_desc =
"     This is the neatest area of the complex. There are shelves set in \n\
the stone walls that contain assorted items. Furs hang along the walls \n\
holding the warmth in this room. A large pallet lies to one side and an\n\
open box is set near the pallet.\n";
  items =
  ({
    "walls",       "Dark granite walls, covered with furs, lined with shelves",
    "shelves",     "Shelves carved into the stone walls containing various items",
    "items",       "Assorted items, worthless to anyone but a shaman",
    "furs",        "Large pelts line the walls, as decoration and practicality",
    "pallets",     "Dirty, worthless hides, for sleeping",
    "hides",       "Dirty, worthless hides, for sleeping",
    "box",         "A box filled with large dirty clothing",
    "clothing",    "Large clothing, unsuitable for any but a giant",
   });
  dest_dir =
  ({
    CROOM+"cave5", "north",
    CROOM+"cave7", "south",
  });
}

init()
{
  ::init();
  add_action("south","south");
}

south()
{
  if(present("shaman"))
  {
    write("The shaman will not let you pass.\n"); 
    say("The shaman prevents " + this_player()->query_name() +
      " from going south.\n");
    return 1;
  }
  this_player()->move_player("south#/players/anshar/cave/room/cave7");
  return 1; 
}
