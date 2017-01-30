inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Main Stairway";
  long_desc = 
   "An impressive staircase is here, leading to a landing, and turning right\n"+
   "on its way upward. To the east and west open two archways, while a door\n"+
   "stands to the south.\n";
  dest_dir = ({"players/bastion/isle/wiz/stair2", "up",
               "players/bastion/isle/wiz/e_hall1", "east",
               "players/bastion/isle/wiz/foyer", "south",
               "players/bastion/isle/wiz/w_hall1", "west"});
  }
}
