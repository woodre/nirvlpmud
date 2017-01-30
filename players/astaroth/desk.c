inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "a room";
  long_desc = 
   "This is jsut a test room with a test desk sitting around.\n"+
   "Just try it and see if the desk can be seen.\n";
  property = ({"NT", ""});
  items = ({"desk",
            "You see a small pamplet there, you can take it.\n"});
  dest_dir = ({"players/astaroth/entrance", "north"});
  }
}
