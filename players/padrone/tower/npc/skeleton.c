/*
 * skeleton.c
 * skeleton in the closed (wardrobe.c)
 */

inherit "obj/monster";

void
reset(status arg)
{
  monster::reset(arg);
  if (arg)
    return;
  set_name("skeleton");
  set_level(8);
#if 0 /* Adjusting to Nirvana monster.guide - Rumplemintz */
  set_hp(70);
  set_wc(7);
#else
  set_hp(120);
  set_wc(12);
  set_ac(7);
#endif
  set_al(-200);
  set_short("A skeleton");
  set_aggressive(1);
}
