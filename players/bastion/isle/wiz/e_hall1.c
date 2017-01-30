inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "East Hallway";
  long_desc = 
   "Double doors lead north and a small door leads south. The hall \n"+
   "continues to the east.\n";
  dest_dir = ({"players/bastion/isle/wiz/dining", "north",
               "players/bastion/isle/wiz/e_hall2", "east",
               "players/bastion/isle/wiz/guards", "south",
               "players/bastion/isle/wiz/stair1", "west"});
  }
}
