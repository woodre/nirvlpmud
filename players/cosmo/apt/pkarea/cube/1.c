inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "White Room";
  long_desc = 
   "\n"+
   "\n";
  property = ({"NT", "NC", "PK"});
  dest_dir = ({"players/cosmo/apt/pkarea/cube/2.c", "east",
               "players/cosmo/apt/pkarea/cube/3.c", "south",
               "players/cosmo/apt/pkarea/cube/5.c", "up"});
  }
}
