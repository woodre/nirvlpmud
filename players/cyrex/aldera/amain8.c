inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Main Road";
  long_desc = 
   "You are standing on a well travelled road heading west and east. The mountain\n"+
   "is coming into better view. You can barely see a slight snow-cap on the top\n"+
   "of the mountain. Something is glimmering brightly to your east.\n";
  no_exits = 1;
  dest_dir = ({"players/cyrex/aldera/amain7", "west",
               "players/cyrex/aldera/amain9", "east",
               "players/cyrex/aldera/anowhere2", "south"});
  }
}
