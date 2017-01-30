/*
 * ant_shield.c
 * Antonio's shield
 */

inherit "obj/armor";

void
reset(status arg)
{
  armor::reset(arg);
  if (arg)
    return;
  set_name("shield");
  set_alias("small shield");
  set_type("shield");
  set_ac(1);
  set_value(70);
  set_weight(4);
  set_short("A small metal shield");
}
