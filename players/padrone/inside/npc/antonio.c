/* 
 * antonio.c
 * Antonio - from Anotnio's bodyguard shop
 */

inherit "obj/monster";

void
reset(status arg)
{
  monster::reset(arg);
  if (arg)
    return;
  set_name("antonio");
  set_alias("director");
  set_level(18);
#if 0  /* Adjusting for Nirvana monster.guide -- Rumplemintz */
  set_male();
  set_hp(300);
#else
  set_wc(26);
  set_ac(15);
  set_hp(400);

  /* Setup spells */
  set_chance(20);
  set_spell_dam(10);
  set_spell_mess1("Antonio flicks his razor at his attacker.");
  set_spell_mess2("Antonio flings his razors at you.");
#endif
  set_al(-100);
  set_short("Antonio");
  set_long("This is Antonio, the old mafioso.\n"+
           "After a life of \"adventure\" he has settled down and started\n"+
           "the Personal Protection Service, where rich people can hire\n" +
           "bodyguards as a protection against the dangers in the world...\n");

  /* Setup gear and stats after wield */
  move_object(clone_object("/players/padrone/inside/npc/obj/ant_razor"),
              this_object());
  move_object(clone_object("/players/padrone/inside/npc/obj/ant_razor"),
              this_object());
  move_object(clone_object("/players/padrone/inside/npc/obj/ant_battleaxe"),
              this_object());
  init_command("wield battleaxe");
  move_object(clone_object("/players/padrone/inside/npc/obj/ant_mail"),
              this_object());
  init_command("wear chainmail");
  move_object(clone_object("/players/padrone/inside/npc/obj/ant_shield"),
              this_object());
  init_command("wear shield");
  set_wc(26);
  set_ac(15);
}
