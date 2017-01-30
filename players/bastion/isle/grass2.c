inherit "room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Tall Grass";
  long_desc = 
   "Wild grass sways from the sandy earth. The tracks of ground-nesting birds\n"+
   "can be seen winding through the swaying blades. You have trouble seeing\n"+
   "over the wild greenery, but it appears you could forage in any direction.\n";
  no_exits=1;
  items = ({"tracks",
            "Who do you think you are? A ranger?"});
  dest_dir = ({"players/bastion/isle/sandy2", "north",
               "players/bastion/isle/hut", "east",
               "players/bastion/isle/grass4", "south",
               "players/bastion/isle/grass1", "west"});
  }
}
