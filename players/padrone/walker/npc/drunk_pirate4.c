/*
 * drunk_pirate4.c
 * Very drunk pirate indeed
 */

inherit "obj/monster";

void
reset(status arg)
{
  object wep, helm, cash;
  ::reset(arg);
  if (arg)
    return;
  set_name("very drunk pirate indded");
  set_alias("pirate");
  set_short("A very drunk pirate indeed");
  set_long("He is very drunk indeed.\n");
  set_gender("male");
  set_level(6);
  set_hp(90);
  set_wc(10);
  set_ac(5);
  set_al(-100);

  wep = clone_object("/players/padrone/walker/npc/obj/pknife");
  move_object(wep, this_object());
  init_command("wield knife");

  helm = clone_object("/players/padrone/walker/npc/obj/phelm");
  move_object(helm, this_object());
  init_command("wear helmet");

  cash = clone_object("obj/money");
  cash->set_money(2 + random(10));
  move_object(cash, this_object());

  set_chat_chance(5);
  load_chat("The very drunk pirate indeed sings: Andsch a rum of bottle chest! La-la-la!\n");
}
