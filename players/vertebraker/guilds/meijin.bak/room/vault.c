inherit "room/room";
#include "/players/pavlik/guild/room/room.h";

object obj;

reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc="The Vault";
  long_desc=
    "This giant room serves of the Meijin's storage vault.  Guild\n"+
    "members often deposit useful items here for those who might\n"+
    "need them.  The vault's location is deep within the Citadel\n"+
    "and the room's heavy iron door can be swung closed and locked\n"+
    "soundly to keep out unwanted guests.\n";

  dest_dir=({
    "/players/pavlik/guild/room/lowerhall", "west",
  });

  if(!present("meijin_vault", this_object())) {
	move_object(clone_object("players/pavlik/guild/obj/vault"), this_object());
  }

  }
}

clean_up() { return 1; }

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

