/*
 * lab_mon.c
 * half finished monster in lab.c
 */

inherit "obj/monster";

void
reset(status arg)
{
  monster::reset(arg);
  if (arg)
    return;
  set_name("half-finished monster");
  set_alias("monster");
  set_level(3);
#if 0 /* Adjusting to Nirvana monster.guide -- Rumplemintz */
  set_wc(4);
#else
  set_hp(45);
  set_wc(7);
  set_ac(4);
#endif
  set_short("A half-finished monster");
  set_long("This is a monster that the Wizard seems to still be working on.\n"+
           "It has no legs, and only one arm.\n"+
           "Parts of it are still stored in big glass jars on the table.\n");
  set_aggressive(1);

  /* Load combat message */
  set_a_chat_chance(50);
  load_a_chat("The half-finished monster says: Error! Brain not yet inserted.");
}
