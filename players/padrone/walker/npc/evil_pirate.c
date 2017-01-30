/*
 * evil_pirate.c
 * Evil pirate from main_hall
 */

inherit "obj/monster";

void
reset(status arg)
{
  object wep, cash;
  ::reset(arg);
  if (arg)
    return;
  set_name("evil pirate");
  set_alias("pirate");
  set_gender("male");
  set_level(3);
  set_hp(45);
  set_wc(7);
  set_ac(4);
  set_al(-200);
  set_short("An evil pirate");
  set_long("This is an evil-looking pirate.\n");
  set_aggressive(1);

  wep = clone_object("obj/weapon");
  wep->set_name("rusty cutlass");
  wep->set_alt_name("cutlass");
  wep->set_class(7);
  wep->set_value(10);
  wep->set_weight(3);
  wep->set_short("A rusty cutlass");
  wep->set_long("This used to be a fine weapon, but the pirate who owned it let it rust.\n");
  move_object(wep, this_object());
  init_command("wield cutlass");

  cash = clone_object("obj/money");
  cash->set_money(20 + random(30));
  move_object(cash, this_object());
}
