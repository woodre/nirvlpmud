inherit        "room/room";
 
reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "A hallway of good music";
  long_desc = 
   "You have entered the good part of the musical section.  You\n"+
   "will find the groups in this part are somewhat better than\n"+
   "the others.  Everybody around here plays their own instruments.\n"+
   "\n";
  dest_dir = ({"players/astaroth/gdmusic2", "east",
               "players/astaroth/music1", "west",
               "players/astaroth/sinead", "north"});
  }
}
