inherit "room/room";

reset(arg) {
if(!arg){
set_light(1);
short_desc="The Lava Tunnels";
long_desc=
"The Lava river turns west here and runs deeper into the depths of\n"+
"the world.  A strong red glow can be seen to the west.  The corridor\n"+
"also continues northward.  The north tunnel appears very cold and very\n"+
"dark due to the abscense of the bubbling lava.  There are some strange\n"+
"markings on the walls here, they might be some sort of heiroglyphics.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/hell10", "east",
 "/players/pavlik/ilstkarn/hell9", "north",
 "/players/pavlik/ilstkarn/hell6", "south",
});

items=({
"heiroglyphics",
"You examine the crude cravings on the walls of this cavern.  The\n"+
"markings seem to be totally random and incomprehensible to you",
"markings",
"You examine the crude cravings on the walls of this cavern.  The\n"+
"markings seem to be totally random and incomprehensible to you",
"wall",
"You examine the crude cravings on the walls of this cavern.  The\n"+
"markings seem to be totally random and incomprehensible to you",
});

if(!present("hzsade", this_object())) {
  move_object(clone_object("players/pavlik/monsters/ilstkarn/lava_dragon"),
  this_object());
}

   }
}

query_ilstkarn(){ return "hell8"; }
realm(){ return "NT"; }


okay_follow() { return 1; }
