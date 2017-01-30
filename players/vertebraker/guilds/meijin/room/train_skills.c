inherit "room/room";
#include "/players/vertebraker/guilds/meijin/room/room.h";

object obj;

reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc="The Training Hall";
  long_desc=
    "You are now in the skills area of the Training Hall.  This\n"+
    "area is large and free of obstacles, allowing trainees plenty\n"+
    "of room to manuever and practice their skills.  A section\n"+
    "further south is reserved for sparring.  There is always\n"+
    "a Master present to help members perfect their skills and\n"+
    "teach them new ones.\n";

  dest_dir=({
    "/players/vertebraker/guilds/meijin/room/train", "north",
    "/players/vertebraker/guilds/meijin/room/spar", "south",
  });

  if(!present("mosakou", this_object())) {
	move_object(clone_object("players/pavlik/guild/npc/mosakou"), this_object());
  }

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
  add_action("south", "south");
  add_action("xmove", "xmove");
}

south() {
  write("The sparring area is not avaliable at this time.\n");
  return 1;
}

