/*
 * bridge_pirate1.c
 * very ugly pirate on bridge
 */

inherit "obj/monster";

void
reset(status arg)
{
  object cash, sword, helmet;

  ::reset(arg);
  if (arg)
    return;
  set_name("very ugly pirate");
  set_alias("pirate");
  set_gender("male");
  set_level(4);
  set_hp(60);
  set_ac(4);
  set_wc(7);
  set_al(-100);
  set_short("A very ugly pirate");
  set_long("This is a medium-sized and very ugly pirate.\n");
  set_aggressive(1);

  sword = clone_object("/players/padrone/walker/npc/obj/pknife");
  move_object(sword, this_object());
  init_command("wield knife");

  helmet = clone_object("/players/padrone/walker/npc/obj/phelm");
  move_object(helmet, this_object());
  init_command("wear helmet");

  cash = clone_object("obj/money");
  cash->set_money(1 + random(50));
  move_object(cash, this_object());
}
