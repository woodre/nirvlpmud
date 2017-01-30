inherit "room/room";
#include "/players/pavlik/guild/room/room.h";

/**************************************************************/
/* This is the guild exchange room.  Here guild members can   */
/* convert regular game experience to guild experience.  The  */
/* exchange ratio is 3:1 (3 exp = 1 guild exp)                */
/**************************************************************/

object seated;

reset(arg) {
  if(!arg) {
  set_light(1);
  short_desc="In a Hut";
  long_desc=
    "The hut's interior is small and dark.  It takes a moment for\n"+
    "your eyes to adjust to the dimness.  A low table and two straw\n"+
    "mats are the only furnishing in this tiny room.  A water clock\n"+
    "hangs in the rear wall of the hut.  The rythmic sound of dripping\n"+
    "water is soothing ... drip ... drip ... drip.\n";

  items=({
  "table",
  "A low table occupies most of the room.  The table is made of a smooth\n"+
  "polished wood.  A small brazier sits at the center of the table",
  "mat",
  "There is two straw mats on the floor, one on either side of the table",
  "mats",
  "There is two straw mats on the floor, one on either side of the table",
  "sandles",
  "A pair of small wooden sandles",
  });

  dest_dir=({
    "/players/pavlik/guild/room/village2", "out",
  });

  if(!present("tainin", this_object())) {
	move_object(clone_object("players/pavlik/guild/npc/tainin"), this_object());
  }

  }
}

realm() { return "NT"; }

init() {
  ::init();
  if(!this_player()->is_player()) return 1;
  add_action("sit","sit");
  add_action("stand","stand");
  add_action("out","out");
  add_action("xmove", "xmove");
}

query_seated() { return seated; }
set_seated(ob) { seated = ob; }

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
  seated = this_player();
  write("You sit on the grass mat.\n");
  say(capitalize(this_player()->query_name())+" sits on the grass mat.\n");
  return 1;
}

stand() {
  if(this_player() == seated) {
	write("You stand up.\n");
	say(capitalize(this_player()->query_name())+" stands up.\n");
	seated = 0;
	return 1;
  }
}

out() {
  if(this_player() == seated) {
	write("You are sitting down.  Maybe you should stand first.\n");
	return 1;
  }
  this_player()->move_player("out#players/pavlik/guild/room/village2");
  return 1;
}

