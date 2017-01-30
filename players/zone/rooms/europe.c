inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "An old Roman cobblestone road travelling through a rolling countryside.";
  long_desc = 
   "Here is a crossroads.  Two Roman roads intersect at this point.  To\n"+
   "the east there rises smoak from a dark forest.  To the north is a large\n"+
   "bramble covered hill.  To the west is another forest.\n";
  dest_dir = ({"players/zone/rooms/bramble.c", "north",
               "players/zone/rooms/circle.c", "south",
               "players/zone/rooms/europe.c", "west",
               "players/zone/rooms/darkwoodforest.c", "east"});
  }
}
