/*
 * e_badger.c
 * badger for e.c room
 */

inherit "obj/monster";

void
reset(status arg)
{
  ::reset(arg);
  if (arg)
    return;
  set_name("badger");
  set_level(2);
#if 0  /* Adjusting for Nirvana monster.guide -- Rumplemintz */
  set_female();
  set_ac(3);
  set_wc(10);
#else
  set_hp(30);
  set_wc(6);
  set_ac(3);
#endif
  set_al(10);
  set_short("A badger");
  set_long("This is a badger. She seems to be inding her own business,\n"+
           "but if she is attacked she will probably defend herself\n"+
           "with some determination.\n");

  /* Spell setup */
  set_chance(19);
  set_spell_dam(10);
  set_spell_mess1("The badger bites her opponent.");
  set_spell_mess2("The badger bites you. And she bites hard!");
}
