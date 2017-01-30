/*
 * drunk_pirate1.c
 * moderately drunk pirate
 */

inherit "obj/monster";

void
reset(status arg)
{
  object wep, helm, cash;
  ::reset(arg);
  if (arg)
    return;
  set_name("moderately drunk pirate");
  set_alias("pirate");
  set_gender("female");
  set_short("A moderately drunk pirate");
  set_long("She is moderately drunk.\n");
  set_level(4);
  set_wc(8);
  set_hp(60);
  set_ac(4);
  set_al(-100);

  wep = clone_object("/players/padrone/walker/npc/obj/pknife");
  move_object(wep, this_object());
  init_command("wield knife");

  helm = clone_object("/players/padrone/walker/npc/obj/phelm");
  move_object(helm, this_object());
  init_command("wear helm");

  cash = clone_object("obj/money");
  cash->set_money(2 + random(10));
  move_object(cash, this_object());

  /* load chat */
  set_chat_chance(5);
  load_chat("The moderately drunk pirate sings: And a bottle of rum!\n");
}
