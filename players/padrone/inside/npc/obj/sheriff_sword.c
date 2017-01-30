/*
 * sheriff_sword.c
 * Sword that the Sheriff uses
 */

inherit "obj/weapon";

void
reset(status arg)
{
  weapon::reset(arg);
  if (arg)
    return;
  set_name("short sword");
  set_alt_name("sword");
  set_short("A short sword");
  set_class(15);
  set_value(700);
  set_weight(2);
}
