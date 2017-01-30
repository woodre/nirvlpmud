inherit "room/room";
object smyth, ladle;

reset(arg)
{
  if (arg) return;
  smyth = clone_object("players/morgoth/MONSTERS/meads_smyth");
  ladle = clone_object("players/morgoth/WEAPONS/ladle");
  set_light(1);
  short_desc = "A banquet hall\n";
  long_desc = "This used to be the banquet hall.\n"+
              "The knights would gather here for all of their meals.\n"+
              "This hall has since been converted into a gallery.\n"+
              "Adorning the walls are various coats of armor and weapons\n"+
              "of yore.  The colorfull designs are reminiscent of a time \n"+
              "of glory and honor.\n";
  dest_dir = 
  ({
    "players/morgoth/CASTLE/courtyard6", "west"
  });
  move_object(ladle, smyth);
  call_other(smyth, "init_command", "wield", ladle);
  move_object(smyth, this_object());
}
