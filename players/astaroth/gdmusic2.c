inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Further along in the good music hallway";
  long_desc = 
   "You have wandered deeper into the corridors of good music.\n"+
   "You feel unsure as to what you will find, but know you feel\n"+
   "very evil and want to kill things here.\n"+
   "\n";
  dest_dir = ({"players/astaroth/gabriel", "south",
               "players/astaroth/bluedream", "east",
               "players/astaroth/gdmusic", "west"});
  }
}
