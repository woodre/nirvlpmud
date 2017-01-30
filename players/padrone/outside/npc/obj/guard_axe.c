/*
 * guard_axe.c
 * Axe for drunken guard
 */

inherit "obj/weapon";

void
reset(status arg)
{
  ::reset(arg);
  if (arg)
    return;
  set_name("hand axe");
  set_alt_name("axe");
  set_class(9);
  set_value(25);
  set_weight(2);
  set_short("A hand axe");
}
