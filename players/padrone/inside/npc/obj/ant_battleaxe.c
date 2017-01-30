/*
 * ant_battleaxe.c
 * Antonio's Battleaxe
 */

inherit "obj/weapon";

void
reset(status arg)
{
  weapon::reset(arg);
  if (arg)
    return;
  set_name("battle-axe");
  set_alt_name("battleaxe");
  set_alias("axe");
  set_class(12);
  set_value(250);
  set_weight(3);
  set_short("A battle-axe");
}
