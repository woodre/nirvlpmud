inherit "room/room";

reset(arg) {
if(!arg){
set_light(1);
short_desc="Slivak Lair";
long_desc=
"A smaller cavern deep below the Earth's suface.  The walls here appear\n"+
"to be burned and scorched by intense heat.  The air is so hot and still\n"+
"it is hard to breathe.  The overpowering smell of sulfur burns your\n"+
"throat.  The northern wall of this chamber seems to be shimmering.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/hell5", "south",
});

if(!present("soldier", this_object())) {
  move_object(clone_object("players/pavlik/monsters/ilstkarn/soldier"),
  this_object());
}

items=({
"wall",
"The north seems to be shimmering, as if it was not really there.  You\n"+
"reach out and touch the wall, and sure enough it is solid as a rock",
});

  }
}

query_ilstkarn(){ return "hell7"; }
realm(){ return "NT"; }


okay_follow() { return 1; }
