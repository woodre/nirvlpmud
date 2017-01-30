/*
 * Test Weapon - for testing LD stuff - do not use
 */

inherit "/obj/weapon";

void
reset(status arg)
{
  if (arg)
    return;
  set_name("sword");
  set_short("Test Sword");
  set_long("Rumplemintz's test weapon.  It happens to be a sword.\n");
  set_class(20);
  set_value(100);
  set_weight(0);
  set_alias("weapon");
}
