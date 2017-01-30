inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "A forest path";
  long_desc = 
   "A long overgrown forest path.  It lookes unused and the encroachment from\n"+
   "the native foliage is slowely recapturing the land.\n";
  dest_dir = ({"players/zone/rooms/path2.c", "north",
              "room/south/sforst48", "south"}); /* Changed to correspond to entrance. -Feldegast 10-14-00 */
  }
}
