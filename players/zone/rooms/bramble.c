inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "A bramble covered hill";
  long_desc = 
   "This is a steep hill covered with blackberry brambles.  If they were in \n"+
   "season, you could have a tastey snack, but they are not.  To the west\n"+
   "is a cave set into the hill.\n";
  dest_dir = ({"players/zone/rooms/europe.c", "south",
               "players/zone/rooms/bear.c", "west"});
  }
}
