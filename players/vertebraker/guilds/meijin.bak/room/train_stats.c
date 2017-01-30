inherit "room/room";
#include "/players/pavlik/guild/room/room.h";

object obj;

reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc="The Training Hall";
  long_desc=
    "This area is full of weights, jump ropes and other exercise\n"+
    "equipment.  You cannot help but to be inspired by the large\n"+
    "number of people who come here to improve and perfect their\n"+
    "body and mind.  There is always a Master present to\n"+
    "encourage trainees and help them sharpen their skills.\n";

  dest_dir=({
    "/players/pavlik/guild/room/train", "south",
  });

  if(!present("reidai", this_object())) {
	move_object(clone_object("players/pavlik/guild/npc/reidai"), this_object());
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

