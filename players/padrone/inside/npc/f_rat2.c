/*
 * f_rat2.c
 * black rat in food cellar
 */

inherit "obj/monster";

void
reset(status arg)
{
  monster::reset(arg);
  if (arg)
    return;
  set_name("black rat");
  set_alias("rat");
  set_level(1);
#if 0 /* Adjusting for Nirvana monster.guide -- Rumplemintz */
  set_hp(40);
  set_wc(5);
#else
  set_hp(15);
  set_wc(5);
  set_ac(3);
#endif
  set_al(-12);
  set_short("A big, black rat");
  set_long("This rat looks really repulsing with its think, black, dirty hair\n"+
           "and its small, clawed feet. It stares at you and squeeks.\n");
  set_aggressive(1);
}
