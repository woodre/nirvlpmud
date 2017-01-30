inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Sub-hall";
  long_desc = 
   "You are in a short east-west corridor. Doors are located at either\n"+
   "end.\n";
  dest_dir = ({"players/bastion/isle/wiz/dining", "east",
               "players/bastion/isle/wiz/kitchen", "west"});
  }
}
