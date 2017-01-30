/*
 * drunk_pirate5.c
 * Completely drunk pirate
 */

inherit "obj/monster";

void
reset(status arg)
{
  object wep, cash;
  ::reset(arg);
  if (arg)
    return;
  set_name("completely drunk pirate");
  set_alias("pirate");
  set_gender("male");
  set_short("A completely drunk pirate");
  set_long("He is completely drunk.\n");
  set_level(7);
  set_hp(105);
  set_wc(11);
  set_ac(6);
  set_al(-100);

  wep = clone_object("obj/weapon");
  wep->set_name("cutlass");
  wep->set_class(10);
  wep->set_value(50);
  wep->set_weight(3);
  wep->set_short("A cutlass");
  move_object(wep, this_object());
  init_command("wield cutlass");

  cash = clone_object("obj/money");
  cash->set_money(100 + random(100));
  move_object(cash, this_object());

  set_chat_chance(5);
  load_chat("The completely drunk pirate tries to sing but falls down and pukes.\n");
}
