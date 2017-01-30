inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Orange Room";
  long_desc = 
   "\n"+
   "\n";
  property = ({"NT", "NC", "PK"});
  dest_dir = ({"/players/cosmo/apt/pkarea/cube/5", "north",
               "/players/cosmo/apt/pkarea/cube/8", "east",
               "/players/cosmo/apt/pkarea/cube/3", "down"});
  }
}
