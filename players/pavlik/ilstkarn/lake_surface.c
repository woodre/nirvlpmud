inherit "room/room";

reset(arg) {
  if(arg);
  set_light(1);
  short_desc="On the Lake";
  long_desc=
  "You tred water at the center of the large underground lake.  A\n"+
  "ghost-like mist hangs low over the water and shrouds your vision.\n"+
  "You can barely discern the sandy beaches that surround the lake.\n";
  dest_dir=({
	"/players/pavlik/ilstkarn/beach1", "west",
	"/players/pavlik/ilstkarn/beach2", "north",
	"/players/pavlik/ilstkarn/beach3", "east",
	"/players/pavlik/ilstkarn/beach4", "south",
	"/players/pavlik/ilstkarn/null", "down",
  });
}

query_ilstkarn(){ return "lake1"; }
realm(){ return "NT"; }
/* query_nofollow(){ return 1; } */
query_no_teleport(){ return 1; }

init() {
  ::init();
  add_action("dive","down");
}

dive() {
  int i;

  write("You take a deep breath and then dive down into the water.\n");
  say(capitalize(this_player()->query_name())+" dives underwater.\n");
  i = 1+random(6);
  move_object(this_player(), "players/pavlik/ilstkarn/lake"+i);
  command("look", this_player());
  return 1;
}


okay_follow() { return 1; }
