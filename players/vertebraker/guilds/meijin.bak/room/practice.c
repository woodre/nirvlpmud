inherit "room/room";
#include "/players/pavlik/guild/room/room.h";

object obj;

reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc="The Training Hall";
  long_desc=
    "This circular area has been cleared for combat training.\n"+
    "A stuffed training dummy hangs in the center of the room.\n"+
    "Meijin often come here to hone their weapon skills and test\n"+
    "the results of their training.  The main training wall is\n"+
    "located to the east.\n";

  dest_dir=({
    "/players/pavlik/guild/room/train", "east",
  });

  if(!present("dummy", this_object())) {
	move_object(clone_object("players/pavlik/guild/obj/practice_dummy"), this_object());
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

