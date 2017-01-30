/*
 * paxe.c
 * Standard pirate axe
 */

inherit "obj/weapon";

void
reset(status arg)
{
  weapon::reset(arg);
  if (arg)
    return;
  set_name("hand axe");
  set_alt_name("axe");
  set_short("A hand axe");
  set_class(9);
  set_value(25);
  set_weight(2);
}
