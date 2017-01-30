/*
 * hu_pirate.c
 * hungry pirate in kitchen
 */

inherit "obj/monster";

void
reset(status arg)
{
  object wep, cash;
  ::reset(arg);
  if (arg)
    return;
  set_name("hungry pirate");
  set_alias("pirate");
  set_gender("male");
  set_level(2);
  set_hp(30);
  set_wc(6);
  set_ac(3);
  set_al(-100);
  set_short("A hungry pirate");
  set_long("This pirate looks hungry. He's looking for food in the kitchen.\n");
  set_aggressive(1);

  wep = clone_object("/players/padrone/walker/npc/obj/pknife");
  move_object(wep, this_object());
  init_command("wield knife");

  cash = clone_object("obj/money");
  cash->set_money(2 + random(10));
  move_object(cash, this_object());
}
