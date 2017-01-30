inherit "room/room";
#include "/players/vertebraker/guilds/meijin/defs.h"
#include "/players/vertebraker/guilds/meijin/room/room.h";
#define Q_ROOM "players/pavlik/guild/room/quarters_room"

object obj;

reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc="A hallway";
  long_desc=
    "This hallway leads to the personal quarters of the Meijin.\n"+
    "Everyone Meijin, upon advancing past the initiate ranks,\n"+
    "is given their own personal chamber within the Citadel.\n"+
    "If you have your own chamber, or have been invited into\n"+
    "someoneelse's room you may continue west.  The upper hallway\n"+
    "is to the east.\n";

  dest_dir=({
    "/players/vertebraker/guilds/meijin/room/upperhall", "east",
    "/players/vertebraker/guilds/meijin/room/quarters_room", "west",
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
  add_action("west","west");
  add_action("xmove", "xmove");
}

west() {
  object myroom;
  string name;

  name = this_player()->query_real_name();

  if(this_player()->query_guild_rank() < 30) {
	write("You may not enter here until you have advanced\n");
	write("further in the guild.  Only those that have\n");
	write("surpassed rank 30 may enter here.\n");
	return 1;
  }
  if(!restore_object(SAVEPATH+"room/"+name)) {
	write("You enter your personal chamber.\n");
	say(capitalize(name)+" leaves west.\n");
	myroom = clone_object("players/pavlik/guild/room/personal_room.c");
	myroom->set_owner(name);
	move_object(myroom, Q_ROOM);
	move_object(this_player(), myroom);
	call_other(this_player(), "look", 0);
	return 1;
  }
  write("You enter your personal chamber.\n");
  say(capitalize(name)+" leaves west.\n");
  move_object(this_player(), Q_ROOM);
  if(present(name+"'s room", environment(this_player()))) {
	move_object(this_player(), present(name+"'s room", environment(this_player())));
	call_other(this_player(), "look", 0);
  }
  else {
	myroom = clone_object("players/pavlik/guild/room/personal_room");
	myroom->set_owner(name);
	move_object(myroom, Q_ROOM);
	move_object(this_player(), myroom);
	call_other(this_player(), "look", 0);
  }
  return 1;
}



