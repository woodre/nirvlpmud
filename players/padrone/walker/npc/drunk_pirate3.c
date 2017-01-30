/*
 * drunk_pirate3.c
 * Very drunk pirate
 */

inherit "obj/monster";

void
reset(status arg)
{
  object wep, cash;
  ::reset(arg);
  if (arg)
    return;
  set_name("very drunk pirate");
  set_alias("pirate");
  set_short("A very drunk pirate");
  set_long("She is very drunk.\n");
  set_gender("female");
  set_level(5);
  set_hp(75);
  set_wc(9);
  set_ac(5);
  set_al(-100);

  wep = clone_object("obj/weapon");
  wep->set_name("curved knife");
  wep->set_alt_name("knife");
  wep->set_short("A curved knife");
  wep->set_class(7);
  wep->set_value(15);
  wep->set_weight(1);
  move_object(wep, this_object());
  init_command("wield knife");

  cash = clone_object("obj/money");
  cash->set_money(2 + random(10));
  move_object(cash, this_object());

  set_chat_chance(5);
  load_chat("The very drunk pirate sings: And a chest of rum! Yeah!\n");
}
