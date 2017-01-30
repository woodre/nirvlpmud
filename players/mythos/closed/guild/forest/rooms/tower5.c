#include "/players/mythos/closed/guild/def.h"

inherit "room/room";
reset(arg) {
  if(!present("dread")) {
    move_object(clone_object("/players/mythos/closed/guild/forest/mon/dread.c"),
      this_object()); }
  if(!arg) {
  set_light(-2);
    short_desc = "Forbidden Castle South Tower Top";
    long_desc =
    "You enter a mist filled room.  Its hard to see....\n"+
    "In the center is a large black creature, and you\n"+
    "don't like the look of it...\n";
  items = ({
   "down","You may leave the room",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/forest/rooms/tower2.c", "down",
  });
} }
realm() { return "NT";}

init() {
  ::init();
    this_player()->set_fight_area();
}
