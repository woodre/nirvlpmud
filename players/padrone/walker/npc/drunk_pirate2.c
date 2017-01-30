/*
 * drunk_pirate2.c
 * More drunk pirate
 */

inherit "obj/monster";

void
reset(status arg)
{
  object wep, cash;
  ::reset(arg);
  if (arg)
    return;
  set_name("more drunk pirate");
  set_alias("pirate");
  set_gender("male");
  set_short("A more drunk pirate");
  set_long("He is more drunk.\n");
  set_level(4);
  set_hp(60);
  set_wc(8);
  set_ac(4);
  set_al(-100);

  wep = clone_object("/players/padrone/walker/npc/obj/paxe");
  move_object(wep, this_object());
  init_command("wield axe");

  cash = clone_object("obj/money");
  cash->set_money(2 + random(10));
  move_object(cash, this_object());

  set_chat_chance(5);
  load_chat("The more drunk pirate sings: And a bott-(hick)-bottle of rum!\n");
}
