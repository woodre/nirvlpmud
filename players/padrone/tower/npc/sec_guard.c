/* 
 * sec_guard.c
 * guard at tower2
 */

inherit "obj/monster";

object the_weapon, the_money;

void
reset(status arg)
{
  monster::reset(arg);
  if (arg)
    return;
  set_name("security guard");
  set_alias("guard");
  set_level(4);
#if 0 /* Adjusting for Nirvana monster.guide -- Rumplemintz */
  set_hp(100);
  set_wc(5);
#else
  set_hp(60);
  set_wc(8);
  set_ac(4);
#endif
  set_al(-10);
  set_short("A security guard");
  set_long("This is a security guard in a dark suit, tie and sunglasses.\n"+
           "He is responsible for the security here.\n");
  set_aggressive(1);

  /* Setup spells */
  set_chance(50);
  set_spell_dam(0);
  set_spell_mess1("The guard yells: This is a private area! Get out, terrorist!");
  set_spell_mess2("The guard yells at you: This is a private area! Get out, terrorist!");

  /* Gear / money */
  the_weapon = clone_object("/players/padrone/obj/m16");
  the_weapon->set_monsters_reload_at_reset(1);
  move_object(the_weapon, this_object());
  init_command("wield m16");
  the_money = clone_object("obj/money");
  the_money->set_money(random(50));
  move_object(the_money, this_object());
}
