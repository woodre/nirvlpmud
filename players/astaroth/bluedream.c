inherit        "room/room";
 
reset(arg) { 
 if(!present("satriani")) {
   move_object(clone_object("players/astaroth/satch.c"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "You are flying in a blue dream";
  long_desc = 
   "You find yourself facing the great guitarist Joe Satriani.\n"+
   "He is really jamming now, and he is sure to start kicking your ass\n"+
   "if you try to stop him...\n"+
   "Be careful, he looks really tough.\n"+
   "\n";
  dest_dir = ({"players/astaroth/gdmusic2", "west",
               "players/astaroth/paul", "south",
               "players/astaroth/stu", "north"});
  }
}
