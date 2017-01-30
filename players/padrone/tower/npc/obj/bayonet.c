/*
 * bayonet.c
 * bayonet for the german terrorist
 */

inherit "obj/weapon";

void
reset(status arg)
{
  weapon::reset(arg);
  if (arg)
    return;
  set_name("bayonet");
  set_short("A bayonet");
  set_class(12);
  set_value(100);
  set_weight(1);
}
