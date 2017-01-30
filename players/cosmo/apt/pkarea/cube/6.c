inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Yellow Room";
  long_desc = 
   "\n"+
   "\n";
  property = ({"NT", "NC", "PK"});
  dest_dir = ({"/players/cosmo/apt/pkarea/cube/5", "west",
               "/players/cosmo/apt/pkarea/cube/8", "south",
               "/players/cosmo/apt/pkarea/cube/2", "down"});
  }
}
