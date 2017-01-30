#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "4th & north H";
  long_desc =
"  To the north is the entrance to the Colony Way Subdivision.  Fourth and North H street.\n";

  items =
  ({
  
});
  dest_dir =
  ({
"/players/angel/area/town/room/colony_01", "north",
"/players/angel/area/town/room/5thnh", "east",
  });
}

init() {
    add_action("enter"); add_verb ("enter");   
}

enter(str) {
	say(capitalize(this_player()->query_name())+
    "Walks forward along the grocery isle.\n");
    this_player()->move_player(
    "entering the grocery isle#/players/angel/area/school/room/foyer.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}
