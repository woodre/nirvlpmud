inherit        "room/room";
 
reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "generic dead end";
  long_desc = 
   "This is a temporary dead end waiting for me to replace it with\n"+
   "a real room.  Just go back the way you came.\n";
  dest_dir = ({"players/astaroth/evmusic", "south"});
  }
}
