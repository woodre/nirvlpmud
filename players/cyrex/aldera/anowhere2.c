inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Nowhere";
  long_desc = 
   "You find yourself on a path to nowhere. Everything seems to look alike. You\n"+
   "get another feeling of deja-vu.\n";
  no_exits = 1;
  property = ({"NT", "NF"});
  dest_dir = ({"players/cyrex/aldera/anowhere2", "north",
               "players/cyrex/aldera/anowhere2", "south",
               "players/cyrex/aldera/anowhere2", "east",
               "players/cyrex/aldera/anowhere2", "west",
               "players/cyrex/aldera/anowhere4", "nowhere"});
  }
}
