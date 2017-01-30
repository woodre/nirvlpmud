inherit "room/room";
#include "/players/vertebraker/guilds/meijin/room/room.h";

object seated;

reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc="In a Hut";
  long_desc=
    "This tiny grass hut is apparently empty.  Dim sunlight filters\n"+
    "through the thatched roof.  The hut is devoid of any furnishings\n"+
    "except for a small mat in the far corner.\n";

  items=({
  "mat",
  "A small woven mat lies here.  It is about the right size for\n"+
  "someone to sit on",
  });

  dest_dir=({
    "/players/vertebraker/guilds/meijin/room/village2", "out",
  });

  }
}

init() {
  ::init();
  if(!this_player()->is_player()) return 1;
  add_action("sit","sit");
  add_action("xmove", "xmove");
}

sit() {
  if(!this_player()->is_player()) return 0;
  if(seated == this_player()) {
	write("You are already sitting.\n");
	return 1;
  }
  if(seated && present(seated, this_object())) {
	write(capitalize(seated->query_name())+" is already seated on the mat.\n");
	return 1;
  }
  write("You sit on the mat.\n");
  say(capitalize(this_player()->query_name())+" sits on the mat.\n");
  seated = this_player();
  return 1;
}

