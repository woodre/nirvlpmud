/*
 * gr_pirate.c
 * Greedy pirate from loft
 */

inherit "obj/monster";


void
reset(status arg)
{
  object wep, cash;
  ::reset(arg);
  if (arg)
    return;
  set_name("greedy pirate");
  set_alias("pirate");
  set_gender("male");
  set_level(5);
#if 0 /* Adjusting for Nirvana monster.guide -- Rumplemintz */
  set_hp(150);
#else
  set_hp(75);
  set_wc(9);
  set_ac(5);
#endif
  set_al(-100);
  set_short("A greedy pirate");
  set_long("This pirate looks very greedy.\n"+
           "He has stolen some money, and now he has sneaked away up here\n"+
           "so he won't have to share it with his comrades.\n");
  set_aggressive(1);

  wep = clone_object("obj/weapon");
  wep->set_name("short sword");
  wep->set_class(15);
  wep->set_value(700);
  wep->set_weight(2);
  wep->set_alg_name("sword");
  wep->set_short("A short sword");
  move_object(wep, this_object());
  init_command("wield sword");

  cash = clone_object("obj/money");
  cash->set_money(100 + random(200));
  move_object(cash, this_object());
}
