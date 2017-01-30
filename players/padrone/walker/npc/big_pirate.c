/* 
 * big_pirate.c
 * big pirate in guard_room.c
 */

inherit "obj/monster";

void
reset(status arg)
{
  object wep, helm, cash;
  ::reset(arg);
  if (arg)
    return;
  set_name("big pirate");
  set_alias("pirate");
  set_gender("male");
  set_short("A big pirate");
  set_long("This pirate is big, but not as big as his friend.\n");
  set_level(7);
  set_hp(105);
  set_wc(11);
  set_ac(6);
  set_al(-120);

  wep = clone_object("/players/padrone/walker/npc/obj/pknife");
  move_object(wep, this_object());
  init_command("wield knife");

  helm = clone_object("/players/padrone/walker/npc/obj/phelm");
  move_object(helm, this_object());
  init_command("wear helmet");

  cash = clone_object("obj/money");
  cash->set_money(10 + random(100));
  move_object(cash, this_object());
}
