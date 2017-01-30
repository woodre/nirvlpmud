inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Green Room";
  long_desc = 
   "\n"+
   "\n";
  property = ({"NT", "NC", "PK"});
  dest_dir = ({"/players/cosmo/apt/pkarea/cube/6", "east",
               "/players/cosmo/apt/pkarea/cube/7", "south",
               "/players/cosmo/apt/pkarea/cube/1", "down"});
  }
}
