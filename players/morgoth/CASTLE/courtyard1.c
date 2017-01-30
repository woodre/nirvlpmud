inherit "room/room";

reset(arg)
{
  if (arg) return;
  set_light(1);
  short_desc = "A large courtyard\n";
  long_desc = "The northwest corner of the courtyard.\n";
  dest_dir = 
  ({
      "players/morgoth/CASTLE/courtyard4", "south",
      "players/morgoth/CASTLE/courtyard2", "east",
      "players/morgoth/CASTLE/wind_tower1", "northwest"
  });
}
