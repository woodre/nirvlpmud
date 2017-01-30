inherit "room/room";
#include "/players/vertebraker/guilds/meijin/room/room.h";

object obj;

reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc="The Courtyard";
  long_desc=
    "You stand in the open courtyard of the Citadel.  Flags snap\n"+
    "in the brisk wind on the battlements above.  The Citadel's\n"+
    "Armory is to the east and the Great Hall is to the north.\n";

  dest_dir=({
    "/players/vertebraker/guilds/meijin/room/start", "north",
    "/players/vertebraker/guilds/meijin/room/gate", "south",
    "/players/vertebraker/guilds/meijin/room/armory", "east",
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
  add_action("xmove", "xmove");
}

