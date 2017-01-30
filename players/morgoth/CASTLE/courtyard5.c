inherit "room/room";
object knight, armor, blade;

reset(arg)
{
  if (arg) return;
  set_light(1);
  short_desc = "The center of the courtyard.\n";
  long_desc = "The center of the courtyard.\n";
              
  dest_dir = 
  ({
     "players/morgoth/CASTLE/courtyard2", "north",
     "players/morgoth/CASTLE/courtyard8", "south",
     "players/morgoth/CASTLE/courtyard6", "east",
     "players/morgoth/CASTLE/courtyard4", "west"
  });
  knight = clone_object("players/morgoth/MONSTERS/dark_knight");
  armor = clone_object("players/morgoth/ARMOR/dark_armor");
  blade = clone_object("players/morgoth/WEAPONS/dark_blade");
  move_object(armor, knight);
  move_object(blade, knight);
  move_object(knight, this_object());
  call_other(knight, "init_command", "wear", armor);
}
