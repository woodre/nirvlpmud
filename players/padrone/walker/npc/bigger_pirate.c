/*
 * bigger_pirate.c
 * bigger pirate in guard_room
 */

inherit "obj/monster";

void
reset(status arg)
{
  object wep, cash;
  ::reset(arg);
  if (arg)
    return;
  set_name("bigger pirate");
  set_alias("pirate");
  set_short("A bigger pirate");
  set_long("This pirate is bigger than his companion.\n");
  set_gender("male");
  set_level(9);
  set_hp(135);
  set_wc(13);
  set_ac(7);
  set_al(-130);
  set_aggressive(1);

  wep = clone_object("/players/padrone/walker/npc/obj/paxe");
  move_object(wep, this_object());
  init_command("wield axe");

  cash = clone_object("obj/money");
  cash->set_money(20 + random(200));
  move_object(cash, this_object());
}
