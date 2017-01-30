inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Red Room";
  long_desc = 
   "\n"+
   "\n";
  property = ({"NT", "NC", "PK"});
  dest_dir = ({"/players/cosmo/apt/pkarea/cube/4", "east",
               "/players/cosmo/apt/pkarea/cube/1", "north",
               "/players/cosmo/apt/pkarea/cube/7", "up"});
  }
}
