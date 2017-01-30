inherit	"room/room";

reset(arg) { 
 if(!present("goat")) {
   move_object(clone_object("players/cyrex/aldera/agoat"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "Snowy Path";
  long_desc = 
   "You are standing on a snowy path heading up towards the mountains. You can\n"+
   "barely breathe or see in this snow storm. However, you do see up at top\n"+
   "some bright lights flashing. It is hard to tell where the path leads from\n"+
   "here...too much snow.\n";
  no_exits = 1;
  dest_dir = ({"players/cyrex/aldera/anowhere5", "north",
               "players/cyrex/aldera/anowhere5", "south",
               "players/cyrex/aldera/anowhere2", "west",
               "players/cyrex/aldera/ampath1", "east"});
  }
}
