inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "West Hallway";
  long_desc = 
   "You notice a spiral staircase going leading down through an arch to\n"+
   "the north, and a small door to the south. The hall continues west.\n";
  dest_dir = ({"players/bastion/isle/wiz/spiral1", "north",
               "players/bastion/isle/wiz/stair1", "east",
               "players/bastion/isle/wiz/clst", "south",
               "players/bastion/isle/wiz/w_hall2", "west"});
  }
}
