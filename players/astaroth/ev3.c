inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Another evil hallway";
  long_desc = 
   "This still feel pretty evil and you wonder what you are\n"+
   "getting yourself in to.  You hear the sounds of rappers\n"+
   "to the east and west.\n"+
   "\n";
  dest_dir = ({"players/astaroth/ice", "west",
               "players/astaroth/base", "east",
               "players/astaroth/evmusic", "south"});
  }
}
