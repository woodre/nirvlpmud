inherit	"room/room";

reset(arg) { 
 if(!present("alderan guard")) {
   move_object(clone_object("players/cyrex/aldera/aguard"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "Castle Entrance";
  long_desc = 
   "You are standing on a Main road heading west from the village church. You\n"+
   "see a entrance to some kind of castle to your west. A castle keep can be seen\n"+
   "to the far north-west. The road heads back on east towards some forest.\n";
  no_exits = 1;
  dest_dir = ({"players/cyrex/aldera/acentrance", "west",
               "players/cyrex/aldera/amain", "east"});
  }
}
