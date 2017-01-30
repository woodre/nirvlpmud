inherit	"room/room";

reset(arg) { 
 if(!present("aldera guard")) {
   move_object(clone_object("players/cyrex/aldera/aguard"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "Main Road";
  long_desc = 
   "You are standing on a well travelled road heading west and east. A slightly\n"+
   "visible forest path can be seen to the north. The castle is barely visible now\n"+
   "considering the distance you are at. To the south-west you can see a village\n"+
   "pub and further down a shop.\n";
  no_exits = 1;
  dest_dir = ({"players/cyrex/aldera/amain5", "west",
               "players/cyrex/aldera/aefentrance", "north",
               "players/cyrex/aldera/amain7", "east"});
  }
}
