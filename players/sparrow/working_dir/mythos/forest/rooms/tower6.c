#include "/players/mythos/closed/guild/def.h"

inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(-2);
    short_desc = "Forbidden Castle North Tower Top";
    long_desc =
    "You are at the Top of the North Tower.\n"+
    "Blood is all over the place and glass is shattered\n"+
    "everywhere.  Something feels wrong.\n";
  items = ({
    "down","You may leave the room",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/forest/rooms/tower3.c", "down",
  });
} }
realm() { return "NT";}

init() {
  ::init();
    this_player()->set_fight_area();
}
