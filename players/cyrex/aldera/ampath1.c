inherit	"room/room";

reset(arg) { 
 if(!present("goat")) {
   move_object(clone_object("players/cyrex/aldera/agoat"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "Snowy path";
  long_desc = 
   "You are standing in a blazing snow storm. You can barely see your hands in\n"+
   "front of you. Aside from not being able to see, you are freezing to death.\n"+
   "You still cannot make out what where the path is heading too.\n";
  no_exits = 1;
  dest_dir = ({"players/cyrex/aldera/ampath", "west",
            "players/cyrex/aldera/anowhere2", "north",
            "players/cyrex/aldera/anowhere2", "south",
               "players/cyrex/aldera/ampath2", "east"});
  }
}
