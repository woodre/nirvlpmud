/*
 * bridge_pirate2
 * ugly pirate on bridge
 */

inherit "obj/monster";

void
reset(status arg)
{
  object cash, knife, helmet;

  ::reset(arg);
  if (arg)
    return;
  set_name("ugly pirate");
  set_alias("pirate");
  set_gender("male");
  set_level(2);
  set_hp(30);
  set_wc(6);
  set_ac(3);
  set_al(-100);
  set_short("An ugly pirate");
  set_long("This is a small and ugly pirate.\n");
  set_aggressive(1);

  knife = clone_object("/players/padrone/walker/npc/obj/pknife");
  move_object(knife, this_object());
  init_command("wield knife");

  helmet = clone_object("/players/padrone/walker/npc/obj/phelm");
  move_object(helmet, this_object());
  init_command("wear helmet");

  cash = clone_object("obj/money");
  cash->set_money(50 + random(100));
  move_object(cash, this_object());
}
