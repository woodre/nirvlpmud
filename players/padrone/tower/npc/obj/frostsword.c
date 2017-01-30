/*
 * frostsword.c
 * Sword of frost on small thief in vault
 */

inherit "obj/weapon";

void
reset(status arg)
{
  weapon::reset(arg);
  if (arg)
    return;
  set_name("sword of frost");
  set_alias("sword");
  set_short("A sword of frost");
#if 0 /* Rumplemintz, too high */
  set_class(20);
#else
  set_class(18);
#endif
  set_weight(3);
  set_value(2000);
}
