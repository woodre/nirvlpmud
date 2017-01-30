inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "The Haunted Forest";
  long_desc = 
   "You are in the Portal rooms.  Shimmering mirrors line the walls.\n"+
   "The working portals lead to the main shop, the post office, and the church.\n";
   dest_dir = ({"room/church", "church",
               "room/post", "post",
               "room/shop", "shop",
               "/players/fred/mages/rooms/practice", "down"});
  }
}
