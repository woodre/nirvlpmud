inherit "room/room";

reset(arg) {
if(!arg){
set_light(1);
short_desc="At the Gate of Hells";
long_desc=
"You follow the lava river deeper into the underground.  The air is hot\n"+
"and thick, you find it increasingly hard to breathe.  The lava flow\n"+
"seems to pick up speed here, and the river rushes westward.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/hell11", "east",
 "/players/pavlik/ilstkarn/hell8", "west",
});

items=({
"river",
"The lava river flows much faster here",
"lava",
"The lava river flows much faster here",
});

if(!present("salamander", this_object())) {
  int i;
  for(i=0; i<3; i++) {
    move_object(clone_object("players/pavlik/monsters/ilstkarn/salamander_guard"), this_object());
  }
}

   }
}

query_ilstkarn(){ return "hell9"; }
realm(){ return "NT"; }


okay_follow() { return 1; }

