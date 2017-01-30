inherit "room/room";

reset(arg)
{
  if (arg) return;
  set_light(1);
  short_desc = "A courtyard";
  long_desc = "A large courtyard.  The towers in each corner of the\n"+
               "fortress are visible from here.  The knights use this\n"+
               "courtyard to practice and to gather before riding out\n"+
               "to do Morgoth's bidding.\n";
  dest_dir = 
  ({
      "players/morgoth/CASTLE/main_gate2", "south",
    "players/morgoth/CASTLE/courtyard5", "north",
    "players/morgoth/CASTLE/courtyard9", "east",
    "players/morgoth/CASTLE/courtyard7", "west"
  });
}
