inherit "room/room";

reset(arg)
{
  if (arg) return;
  set_light(1);
  short_desc = "The Tower of Wind\n";
  long_desc = "The base of the Tower of Wind.\n"+
              "A long spiral stone staircase winds\n"+
              "upwards...\n";
  dest_dir = 
  ({
      "players/morgoth/CASTLE/wind_tower2", "up",
      "players/morgoth/CASTLE/courtyard1", "southeast"
  });
}
