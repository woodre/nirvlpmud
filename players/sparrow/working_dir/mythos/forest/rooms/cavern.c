#include "/players/mythos/closed/guild/def.h"
#include "/sys/ansi.h"
inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(0);
    short_desc = HIK+"Black Cavern"+NORM+" ["+HIK+"Entrance"+NORM+"]";
    long_desc =
    "You are at the entrance to a large cavern.\n"+
    BOLD+"Do not"+NORM+" step into it if you are not prepared....\n";
  items = ({
    "south","You can return to the less forbidding part of the forest",
    "enter","Cold air blows from the darkness....",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/forest/rooms/hunter2.c", "south",
    "/players/mythos/closed/guild/task/6/cavern.c","enter",
  });
} }

realm() { return "NT";}

