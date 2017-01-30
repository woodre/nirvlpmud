inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Nowhere";
  long_desc = 
   "You find yourself on a path to nowhere. Everything seems to look alike. You\n"+
   "get another feeling of deja-vu.\n";
  no_exits = 1;
  property = ({"NT"});
  dest_dir = ({"players/cyrex/aldera/anowhere5", "north",
               "players/cyrex/aldera/anowhere2", "south",
               "players/cyrex/aldera/anowhere2", "east",
               "players/cyrex/aldera/anowhere5", "west",
               "players/cyrex/aldera/ampath", "nowhere"});
  }
}
