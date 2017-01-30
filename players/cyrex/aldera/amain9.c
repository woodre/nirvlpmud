inherit	"room/room";

reset(arg) { 
 if(!present("large sign")) {
   move_object(clone_object("players/cyrex/aldera/asign"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "Main Road";
  long_desc = 
   "You are standing on a well travelled road that heads west and east. The road\n"+
   "continuous on towards the east into uninhabited territory. A sign is here\n"+
   "glowing with words of warning.\n";
  no_exits = 1;
  dest_dir = ({"players/cyrex/aldera/amain8", "west",
               "players/cyrex/aldera/anowhere3", "east",
               "players/cyrex/aldera/anowhere4", "north",
               "players/cyrex/aldera/anowhere5", "south"});
  }
}
