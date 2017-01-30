/*
 * bridge_pking.c
 * Pirate King on the bridge
 */

inherit "obj/monster";

void
reset(status arg)
{
  object key, wep, arm, helm, bag, cash;

  ::reset(arg);
  if (arg)
    return;
  set_name("pirate king");
  set_alias("king");
  set_gender("male");
  set_level(12);
#if 0 /* Adjusting for Nirvana monster.guide - Rumplemintz */
  set_hp(200);
#else
  set_hp(180);
  set_wc(16);
  set_ac(9);
#endif
  set_al(-200);
  set_short("The pirate king");
  set_long("This is the pirate king. He is big and very very ugly.\n");
  set_aggressive(1);

  wep = clone_object("obj/weapon");
  wep->set_name("cutlass");
  wep->set_class(10);
  wep->set_value(50);
  wep->set_weight(3);
  wep->set_short("A cutlass");
  wep->set_long("This is a cutlass. It has probably belonged to a pirate.\n");
  move_object(wep, this_object());
  init_command("wield cutlass");

  arm = clone_object("obj/armor");
  arm->set_name("chainmail");
  arm->set_alias("armor");
  arm->set_type("armor");
  arm->set_ac(3);
  arm->set_value(500);
  arm->set_weight(5);
  arm->set_short("A suit of chainmail");
  move_object(arm, this_object());
  init_command("wear chainmail");

  helm = clone_object("obj/armor");
  helm->set_name("metal helmet");
  helm->set_ac(1);
  helm->set_weight(3);
  helm->set_value(75);
  helm->set_alias("helmet");
  helm->set_type("helmet");
  helm->set_short("A metal helmet");
  helm->set_long("A metal helmet\n");
  move_object(helm, this_object());
  init_command("wear helmet");

  bag = clone_object("obj/bag");
  move_object(bag, this_object());

  cash = clone_object("obj/money");
  cash->set_money(100 + random(300));
  move_object(cash, bag);

  key = clone_object("obj/key");
  key->set_type("bullet-proof");
  key->set_code("walkervault");
  move_object(key, bag);
}
