inherit "room/room";
object rat, key;

reset(arg)
{
  if (arg) return;
  set_light(1);
  rat = clone_object("players/morgoth/MONSTERS/rat");
  key = clone_object("players/morgoth/OBJ/iron_key");
  move_object(key, rat);
  move_object(rat, this_object());
  short_desc = "A large courtyard\n";
  long_desc = "A large grass courtyard.\n";
              
              
  dest_dir = 
  ({
      "players/morgoth/CASTLE/courtyard5", "south",
      "players/morgoth/CASTLE/courtyard3", "east",
      "players/morgoth/CASTLE/courtyard1", "west"
  });
}
