/*
 * w_knife.c
 * knife for the Wizard's apprentice
 */

inherit "obj/weapon";

void
reset(status arg)
{
  weapon::reset(arg);
  if (arg)
    return;
  set_name("long knife");
  set_alt_name("knife");
  set_short("A long knife");
  set_class(8);
  set_value(20);
  set_weight(1);
}
