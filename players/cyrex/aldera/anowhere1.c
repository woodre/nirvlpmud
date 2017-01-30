inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Main Road";
  long_desc = 
"You find yourself on a path to nowhere. Everything seems to look alike. You\n"+
"get another feeling of deja-vu.\n";
  no_exits = 1;
  dest_dir = ({"players/cyrex/aldera/anowhere1", "north",
                "players/cyrex/aldera/anowhere", "west",
                "players/cyrex/aldera/anowhere1", "east",
               "/players/cyrex/aldera/anowhere", "south"});
  }
}
