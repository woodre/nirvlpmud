inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Main Road";
  long_desc = 
   "You are standing on a well travelled road heading west and east. A castle is\n"+
   "now barely visible far down to the west. The forest path seems to be coming\n"+
   "into view to your north-east. A path south to the village pub is directly\n"+
   "in front of you.\n";
  no_exits = 1;
  dest_dir = ({"players/cyrex/aldera/amain4", "west",
               "players/cyrex/aldera/apath", "south",
               "players/cyrex/aldera/amain6", "east"});
  }
}
