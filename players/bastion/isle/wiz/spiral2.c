inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Spiral Stair";
  long_desc = 
   "A winding staircase leads up and down here. A hallway lies south.\n";
  items = ({"staircase",
            "The staircase is wrought of some type of metal. It has a peculiar\npatina that reflects all the colors of the rainbow",
            "stairs",
            "The staircase is wrought of some type of metal. It has a peculiar\npatina that reflects all the colors of the rainbow"});
  dest_dir = ({"players/bastion/isle/wiz/spiral1", "up",
               "players/bastion/isle/wiz/spiral3", "down",
               "players/bastion/isle/wiz/base_hall1", "south"});
  }
}
