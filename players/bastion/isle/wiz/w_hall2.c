inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "West Hallway";
  long_desc = 
   "The hallway ends at a set of double doors. Another door leads south,\n"+
   "while another, nearly across from it, leads north.\n";
  dest_dir = ({"players/bastion/isle/wiz/kitchen", "north",
               "players/bastion/isle/wiz/w_hall1", "east",
               "players/bastion/isle/wiz/parlour", "south",
               "players/bastion/isle/wiz/great_hall", "west"});
  }
}
