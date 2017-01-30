inherit "room/room";
#include "/players/vertebraker/guilds/meijin/room/room.h";

object obj;

reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc="The Training Hall";
  long_desc=
    "You have entered the vast Training Hall of the Meijin.  This\n"+
    "large open chamber provides ample space for guild members to\n"+
    "practice and hone their skills.  Numerous weight sets and other\n"+
    "exercise devices are to the north and a large sparring area is\n"+
    "located to the south.\n";

  dest_dir=({
    "/players/vertebraker/guilds/meijin/room/train_stats", "north",
    "/players/vertebraker/guilds/meijin/room/train_skills", "south",
    "/players/vertebraker/guilds/meijin/room/lowerhall", "east",
    "/players/vertebraker/guilds/meijin/room/practice", "west",
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

