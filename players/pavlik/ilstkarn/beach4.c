inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="On the Beach";
  long_desc=
  "You stand on the southern shore of the underground lake.  The coarse black\n"+
  "sand is quite hot beneath your feet.  Even the walls of this underground\n"+
  "cavern seem to be giving off a large amount of heat.  You are beginning\n"+
  "to sweat.  You have an evil foreboding about this place.\n"+
  "The black sand beach surrounds the lake on all sides.\n";
  dest_dir=({
	"/players/pavlik/ilstkarn/beach3", "east",
	"/players/pavlik/ilstkarn/beach1", "west",
  });
}

query_ilstkarn(){ return "beach4"; }
realm(){ return "NT"; }

init() {
  ::init();
  add_action("dive", "dive");
}

dive() {
  int i;
  i = random(6) + 1;
  write("You dive into the lake!\n");
  this_player()->move_player("into the lake#players/pavlik/ilstkarn/lake"+i);
  return 1;
}

okay_follow() { return 1; }
