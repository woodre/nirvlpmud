inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Walkway";
  long_desc = 
   "Walkway leading northwest and west.\n";
  dest_dir = ({"players/zone/rooms/town5.c", "northwest",
               "players/zone/rooms/town6.c", "west"});
  }
}
