/*
 * f_rat.c
 * brown rat in food cellar
 */

inherit "obj/monster";

void
reset(status arg)
{
  monster::reset(arg);
  if (arg)
    return;
  set_name("brown rat");
  set_alias("rat");
  set_level(1);
#if 0 /* Adjusting to Nirvana monster.guide -- Rumplemintz */
  set_hp(40);
  set_wc(5);
#else
  set_hp(15);
  set_wc(5);
  set_ac(3);
#endif
  set_al(-10);
  set_short("A big, brown rat");
  set_long("This is an ugly, dirty, smelling rat with a long, naked tail.\n"+
           "It stares at you with angry red eyes and looks very aggressive.\n");
  set_aggressive(1);
}
