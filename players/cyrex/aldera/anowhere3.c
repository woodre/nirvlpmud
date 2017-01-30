inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Nowhere";
  long_desc = 
   "You find yourself on a path to nowhere. Everything seems to look alike. You\n"+
   "get another feeling of deja-vu.\n";
  no_exits = 1;
  dest_dir = ({"players/cyrex/aldera/anowhere2", "west",
               "players/cyrex/aldera/anowhere3", "north",
               "players/cyrex/aldera/anowhere1", "south",
               "players/cyrex/aldera/anowhere3", "east"});
  }
}
