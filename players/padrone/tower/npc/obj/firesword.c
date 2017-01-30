/* 
 * firesword.c
 * Sword of fire for big thief in vault
 */

inherit "obj/weapon";

void
reset(status arg)
{
  weapon::reset(arg);
  if (arg)
    return;
  set_name("sword");
  set_alias("sword of fire");
  set_short("A sword of fire");
#if 0 /* Changing this, too high - Rumplemintz */
  set_class(20);
#else
  set_class(18);
#endif
  set_weight(3);
  set_value(2000);
}
