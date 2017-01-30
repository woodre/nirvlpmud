inherit "room/room";
#include "/players/pavlik/guild/room/room.h";

object obj;

reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc="The Upper Hall";
  long_desc=
    "You stand at the top of the great spiraling staircase.  You\n"+
    "are now on the upper level of the Citadel.  The Meijin's\n"+
    "personal quarters are to the west a small dining hall is\n"+
    "located to the east.  Another stairway leads up to the roof.\n";

  dest_dir=({
    "/players/pavlik/guild/room/dine", "east",
    "/players/pavlik/guild/room/quarters", "west",
    "/players/pavlik/guild/room/lowerhall", "down",
  });

  }
}

init() {
  ::init();
  if(!this_player()->is_player()) return 1;
  if(this_player()->query_guild_name() != "meijin" && this_player()->query_level() < 20) {
	write("You are not permitted here.\n");
	write("You are carefully transported to the village church.\n");
	this_player()->move_player("abruptly#room/church");
	return 1;
  }
  if(!present("pavlik_guild_obj", this_player())) {
	obj = clone_object("players/pavlik/guild/gob");
	move_object(obj, this_player());
	obj->guild_init();
  }
  add_action("east","east");
  add_action("up","up");
  add_action("xmove","xmove");
}

east() {
  write("The dining hall is not open at this time.\n");
  return 1;
}

up() {
  this_player()->move_player("up#players/pavlik/guild/room/roof");
  return 1;
}

