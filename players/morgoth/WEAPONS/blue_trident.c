inherit "obj/weapon";

reset(arg)
{
  if (arg) return;
  ::reset(arg);
  set_name("blue trident");
  set_alias("trident");
  set_short("The Blue Trident");
  set_long("The Water Trident is 8 feet long and has three razor\n"+
           "sharp points.  The trident's energy rushes through you in waves.  Legend has it that\n"+
           "the trident has the power of a thousand tidal waves.\n");
  set_weight(3);
  set_class(10);
  set_value(250);
  set_hit_func(this_object());
}

weapon_hit(attacker)
{
  write("The Water Trident strikes with the power of a thousand tidal waves !\n");
  return 5;
}
