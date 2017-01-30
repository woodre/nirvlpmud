/*
 * bed_pirate.c
 * Pirate in bedroom
 */

inherit "obj/monster";

object weapon, shield, cash;

void
reset(status arg)
{
  ::reset(arg);
  if (arg)
    return;
  set_name("lazy pirate");
  set_alias("pirate");
  set_gender("male");
  set_level(3);
#if 0 /* Adjusting for Nirvana monster.guide -- Rumplemintz */
  set_hp(150);
#else
  set_hp(45);
  set_wc(6);
  set_ac(3);
#endif
  set_al(-100);
  set_short("A lazy pirate");
  set_long("This pirate looks very lazy.\n"+
           "He has sneaked away here to take a nap in the nice bed,\n"+
           "while his comrades are busy working at demolishing the castle.\n");
  set_aggressive(1);

  /* Gear */
  weapon = clone_object("obj/weapon");
  weapon->set_name("short sword");
  weapon->set_alt_name("sword");
  weapon->set_class(15);
  weapon->set_value(700);
  weapon->set_weight(2);
  weapon->set_short("A short sword");
  move_object(weapon, this_object());
  init_command("wield sword");

  shield = clone_object("obj/armor");
  shield->set_name("shield");
  shield->set_alias("small shield");
  shield->set_type("shield");
  shield->set_ac(1);
  shield->set_value(70);
  shield->set_weight(4);
  shield->set_short("A small metal shield");
  move_object(shield, this_object());
  this_object()->add_weight(4);
  init_command("wear shield");

  cash = clone_object("obj/money");
  cash->set_money(10 + random(100));
  move_object(cash, this_object());
}
