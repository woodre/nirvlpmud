inherit "room/room";

reset(arg)
{
  if (arg) return;
  set_light(1);
  short_desc = "A large courtyard\n";
  long_desc = "The northeast corner of the courtyard.\n";
              
  dest_dir = 
  ({
      "players/morgoth/CASTLE/courtyard6", "south",
      "players/morgoth/CASTLE/courtyard2", "west",
      "players/morgoth/CASTLE/water_tower1", "northeast"
  });
}
