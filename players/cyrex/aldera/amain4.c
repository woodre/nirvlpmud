inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Main Road";
  long_desc = 
   "You are standing on a well travelled road heading west and east. A castle can\n"+
   "be seen to your west. Some sort of shop is to your south-west and a village\n"+
   "pub is visible to your south-east. A dense forest is looming closer to north-\n"+
   "east.\n";
  no_exits = 1;
  dest_dir = ({"players/cyrex/aldera/amain3", "west",
               "players/cyrex/aldera/amain5", "east",
               "players/cyrex/aldera/anowhere1", "north"});
  }
}
