#include <ansi.h>

inherit "room/room.c";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(0);
  short_desc = HIC+"Cavern Basin"+NORM;
  long_desc =
" It appears you are admist's a boat. Looking out of the boat it\n\
appears this area is at the end of a low river stream. The stream\n\
appears to flow down hill fast with a couple of heavy rapid's.\n";

items =
  ({
   });
  dest_dir =
  ({
  });
}

init() {
  ::init();
    add_action("move","row");
    add_action("climb", "climb");
}

move(str) {
	say(capitalize(this_player()->query_name())+
	"releases the rope and the scafold drops down 50 yeards.\n");
    this_player()->move_player(
    "releases the rope and drops futher into the cavern#/players/angel/area/mansion/room/cavern_basin_02");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}

climb(str) {
	say(capitalize(this_player()->query_name())+
    "releases the rope and the scafold drops down 50 yeards.\n");
    this_player()->move_player(
    "releases the rope and drops futher into the cavern#/players/angel/area/mansion/room/hiram_lair_02");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}
