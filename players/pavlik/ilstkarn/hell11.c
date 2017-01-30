inherit "room/room";

reset(arg) {
if(!arg){
set_light(1);
short_desc="Lava Falls";
long_desc=
"The heat is so intense here you feel likely to burst into flames at\n"+
"any second.  The swiftly flowing lava river comes to an end here where\n"+
"the hot lava spills into a deep, dark gorge.  The lava-fall churns\n"+
"noisily as the boiling magma drops into the bottomless hole.\n";

dest_dir=({
 "/players/pavlik/ilstkarn/hell10", "west",
 "/players/pavlik/ilstkarn/null", "down",
});

if(!present("ferucche", this_object())) {
  move_object(clone_object("players/pavlik/monsters/ilstkarn/salamander_king"),
  this_object());
}

   }
}

query_ilstkarn(){ return "hell9"; }
realm(){ return "NT"; }

init() {
  ::init();
  add_action("nope", "down");
}

nope() {
  write("You consider jumping into a bottomless hole, but decide against it.\n");
  return 1;
}


okay_follow() { return 1; }

