inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Main Road";
  long_desc = 
   "You are standing on a well travelled road heading west and east. You can\n"+
   "barely notice from this spot a huge mountain looming in the far east. The\n"+
   "castle is slowly fading from view.\n";
  no_exits = 1;
  dest_dir = ({"players/cyrex/aldera/amain6", "west",
               "players/cyrex/aldera/amain8", "east"});
  }
}
