/*
 * dis_pirate.c
 * disgusting pirate at shop
 */

inherit "obj/monster";

void
reset(status arg)
{
  object wep, cash;
  ::reset(arg);
  if (arg)
    return;
  set_name("disgusting pirate");
  set_alias("pirate");
  set_short("A disgusting pirate");
  set_long("Yuk! What a disgusting pirate!\n");
  set_gender("male");
  set_level(2);
  set_hp(30);
  set_wc(6);
  set_ac(3);
  set_aggressive(1);

  wep = clone_object("/players/padrone/walker/npc/obj/pknife");
  move_object(wep, this_object());
  init_command("wield knife");

  cash = clone_object("obj/money");
  cash->set_money(2 + random(20));
  move_object(cash, this_object());
}
