inherit        "room/room";
 
reset(arg) { 
 if(!present("man")) {
   move_object(clone_object("/players/astaroth/prosser.c"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "A house about to get demolished";
  long_desc = 
   "You are in the front yard of someone's house that is ready to get\n"+
   "demolished by the large yellow bulldozer sitting to your left,\n"+
   "and a path going east and west.\n"+
   "\n";
  items = ({"bulldozer",
            "A big, yellow bulldozer.  You are not certain how big it is, but\nyou certainly don't want to get in its way.  You are sure of that.",
            "house",
            "This is a totally unspectacular house, but I'm sure the owner is\nnot so pleased at the idea of it getting demolished."});
  dest_dir = ({"players/astaroth/house", "in",
               "players/astaroth/junct", "east",
               "players/astaroth/path1", "west"});
  }
}
