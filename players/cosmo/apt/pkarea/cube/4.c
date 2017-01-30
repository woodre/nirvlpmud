inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Blue Room";
  long_desc = 
   "\n"+
   "\n";
  property = ({"NT", "NC", "PK"});
  dest_dir = ({"/players/cosmo/apt/pkarea/cube/3", "west",
               "/players/cosmo/apt/pkarea/cube/2", "north",
               "/players/cosmo/apt/pkarea/cube/8", "up"});
  }
}
