inherit "room/room";

reset(arg) {
if(!arg){
set_light(1);
short_desc="Slivak Lair";
long_desc=
"A smaller cavern deep below the Earth's suface.  The walls here appear\n"+
"to be burned and scorched by intense heat.  The air is so hot and still\n"+
"it is hard to breathe.  The overpowering smell of sulfur burns your\n"+
"throat.  Many charred, blackened bones are spread about the floor of\n"+
"this chamber.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/hell1", "east",
});

if(!present("slivak", this_object())) {
  move_object(clone_object("players/pavlik/monsters/ilstkarn/slivak"),
  this_object());
}

items=({
"bones",
"Many charred and blackened bones are strewn about this chamber",
});

  }
}

query_ilstkarn(){ return "hell2"; }
realm(){ return "NT"; }


okay_follow() { return 1; }
