inherit "room/room";
#include "/players/pavlik/guild/room/room.h";

object obj;

reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc="The Armory";
  long_desc=
    "The Citadel's Armory is a smaller building built into the huge\n"+
    "stone walls of the inner courtyard.  The Armory is heated by\n"+
    "a glowing forge and the heavy hammer of Uchidasu, the Meijin\n"+
    "weaponsmith.  The main courtyard is to the west.\n";

  dest_dir=({
    "/players/pavlik/guild/room/courtyard", "west",
  });

  if(!present("uchidasu", this_object())) {
	move_object(clone_object("players/pavlik/guild/npc/uchidasu"), this_object());
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
  add_action("xmove", "xmove");
}

