inherit "room/room";

reset(arg)
{
  if (arg) return;
  set_light(1);
  short_desc = "A large courtyard\n";
  long_desc = "The southeast corner of the courtyard.\n";
  dest_dir = 
  ({
      "players/morgoth/CASTLE/courtyard6", "north",
      "players/morgoth/CASTLE/courtyard8", "west",
      "players/morgoth/CASTLE/fire_tower1", "southeast"
  });
}
