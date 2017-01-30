inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Spiral Stair";
  long_desc = 
   "A winding staircase leads up here. An archway opens south.\n";
  dest_dir = ({"players/bastion/isle/wiz/spiral2", "up",
               "players/bastion/isle/wiz/prison_hall", "south"});
  }
}
