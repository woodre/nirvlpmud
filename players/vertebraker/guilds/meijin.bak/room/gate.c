inherit "room/room";
#include "/players/pavlik/guild/room/room.h";

reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc="The Citadel's Gate";
  long_desc=
    "Before you stands a gigantic fortress of stone.  The Citadels'\n"+
    "walls tower over you, casting you in shadow.  This is the sacred\n"+
    "monastery of the Meijin.  Only those that have dedicated their\n"+
    "life to perfection may pass through its gate.\n";

  items=({
  "gate",
  "The gate is closed and locked",
  });

  dest_dir=({
    "/players/pavlik/guild/room/village3", "south",
  });

  }
}

init() {
  ::init();
  if(!this_player()->is_player()) return 1;
  add_action("enter","enter");
  add_action("xmove", "xmove");
}

enter() {
  if(this_player()->query_guild_name() != "meijin") {
	write("The gate is locked.\n");
	return 1;
  }
  this_player()->move_player("into the Citadel#players/pavlik/guild/room/courtyard");
  return 1;
}

