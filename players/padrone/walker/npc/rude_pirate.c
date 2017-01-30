/*
 * rude_pirate.c
 * Rude pirate in shop
 */

inherit "obj/monster";

void
reset(status arg)
{
  object wep, cash;
  ::reset(arg);
  if (arg)
    return;
  set_name("rude pirate");
  set_alias("pirate");
  set_gender("male");
  set_short("A rude pirate");
  set_long("The rude pirate laughs and makes an obscene gesture.\n");
  set_level(3);
  set_hp(45);
  set_wc(7);
  set_ac(4);
  set_al(-100);
  set_aggressive(1);

  wep = clone_object("/players/padrone/walker/npc/obj/paxe");
  move_object(wep, this_object());
  init_command("wield axe");

  cash = clone_object("obj/money");
  cash->set_money(2 + random(40));
  move_object(cash, this_object());
}
