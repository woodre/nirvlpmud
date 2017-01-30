/*
 * np_butterfly.c
 * nice_place butterfly
 */

inherit "obj/monster";

void
reset(status arg)
{
  ::reset(arg);
  if (arg)
    return;
  set_name("butterfly");
  set_level(1);
#if 0  /* Adjusted for Nirvana monster.guide -- Rumplemintz */
  set_ep(60);
  set_hp(1);
  set_wc(1);
  set_ac(10);
#else
  set_hp(15);
  set_wc(5);
  set_ac(3);
#endif
  set_al(20);
  set_short("A butterfly");
  set_long("A beautiful, golden butterfly, happily\n"+
           "fluttering around among the bushes.\n");
}
