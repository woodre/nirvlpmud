inherit "room/room";
object guard, staff, armor;
int i;

reset(arg)
{
  if (arg) return;
  set_light(1);
  i = 0;
  if(!guard || !living(guard))
  {
    while(i < 2)
    {
    i += 1;
      guard = clone_object("players/morgoth/MONSTERS/guard");
      staff = clone_object("players/morgoth/WEAPONS/oak_staff");
      armor = clone_object("players/morgoth/ARMOR/leather_armor");
      move_object(staff, guard);
      move_object(armor, guard);
      call_other(guard, "init_command", "wear", armor);
      move_object(guard, this_object());
    }
  }
  short_desc = "main gate";
  long_desc = "Inside the main gate.\n"+
              "This wide path leads directly through the main gate\n"+
              "of Morgoth's fortress.  The 30 foot thick walls that\n"+
              "comprise the outer barrier of the fortress surround you.\n"+
          "Two guards stand before you.  Their function these days\n"+
              "is for the most part ceremonial.  Still, they are expert\n"+
         "fighters with the staffs they hold in the *at ease* position\n"+
          "at their sides.  The guards are wearing traditional leather armor.\n"+
           "A courtyard lies to the north.\n";
  dest_dir = 
  ({
     "players/morgoth/CASTLE/main_gate", "south"
  });
}

init()
{
  add_action("move_north", "north");
  ::init();
}

move_north()
{
  if(present("guard", this_object()))
  {
    write("The guard blocks your way !!\n");
    return 1;
  }
  call_other(this_player(), "move_player", "north#players/morgoth/CASTLE/courtyard8");
  return 1;
}
