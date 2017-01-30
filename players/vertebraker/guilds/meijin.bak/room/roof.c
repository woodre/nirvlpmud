inherit "room/room";
#include "/players/pavlik/guild/room/room.h";

object obj;

reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc="The Upper Hall";
  long_desc=
    "You know stand on the roof of the great Citadel.  A brisk\n"+
    "wind snaps at you.  From this vantage point you can see the\n"+
    "surround village and mountain peaks.  The cool air feels\n"+
    "refreshing.  A small staircase leads back down into the keep.\n";

  dest_dir=({
    "/players/pavlik/guild/room/upperhall", "down",
  });

  if(!present("kitaeru", this_object())) {
	move_object(clone_object("players/pavlik/guild/npc/kitaeru"), this_object());
  }

  }
}

query_xsummon() { return 1; }

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

