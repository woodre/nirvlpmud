inherit "room/room";
#include "/players/vertebraker/guilds/meijin/room/room.h";

object obj;

reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc="The Low Hall";
  long_desc=
    "You are in the lower hall of the great Citadel.  A grand\n"+
    "staircase spirals upwards to the keep's second level.  A\n"+
    "shorter hallway to the west leads to the training rooms and\n"+
    "a heavy iron door in the east wall leads to the Vault.  The\n"+
    "Great Hall is to the south from here.\n";

  dest_dir=({
    "/players/vertebraker/guilds/meijin/room/start", "south",
    "/players/vertebraker/guilds/meijin/room/vault", "east",
    "/players/vertebraker/guilds/meijin/room/train", "west",
    "/players/vertebraker/guilds/meijin/room/upperhall", "up",
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

