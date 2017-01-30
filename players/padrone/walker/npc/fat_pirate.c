/*
 * fat_pirate.c
 * Fat pirate in castle_yard
 */

inherit "obj/monster";

void
reset(status arg)
{
  object wep, helm, cash;
  ::reset(arg);
  if (arg)
    return;
  set_name("fat pirate");
  set_alias("pirate");
  set_gender("male");
  set_level(3);
  set_hp(45);
  set_wc(7);
  set_ac(4);
  set_al(-100);
  set_short("A fat pirate");
  set_long("This is a short and fat pirate.\n");
  set_aggressive(1);

  wep = clone_object("/players/padrone/walker/npc/obj/pknife");
  move_object(wep, this_object());
  init_command("wield knife");

  helm = clone_object("/players/padrone/walker/npc/obj/phelm");
  move_object(helm, this_object());
  init_command("wear helmet");

  cash = clone_object("obj/money");
  cash->set_money(2 + random(10));
  move_object(cash, this_object());
}
