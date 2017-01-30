inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Black Room";
  long_desc = 
   "\n"+
   "\n";
  property = ({"NT", "NC", "PK"});
  dest_dir = ({"/players/cosmo/apt/pkarea/cube/1", "west",
               "/players/cosmo/apt/pkarea/cube/4", "south",
               "/players/cosmo/apt/pkarea/cube/6", "up"});
  }
}
