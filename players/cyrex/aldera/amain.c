inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Main Road";
  long_desc = 
   "You are standing on a Main dirt road that runs in all directions from this\n"+
   "point. However, it looks like the Main road runs west and east through this\n"+
   "village. A church is visible far to your north and a endless path to nowhere\n"+
   "is to your south.\n";
  no_exits = 1;
  dest_dir = ({"players/cyrex/aldera/achurch", "north",
               "players/cyrex/aldera/anowhere", "south",
               "players/cyrex/aldera/amain1", "west",
               "players/cyrex/aldera/amain2", "east"});
  }
}
