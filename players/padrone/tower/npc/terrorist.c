/*
 * terrorist.c
 * German terrorist from tower3
 */

inherit "obj/monster";

void
reset(status arg)
{
  monster::reset(arg);
  if (arg)
    return;
  set_name("german terrorist");
  set_alias("terrorist");
  set_level(6);
#if 0 /* Adjusting for Nirvana monster.guide - Rumplemintz */
  set_male();
#else
  set_hp(90);
  set_wc(10);
  set_ac(5);
#endif
  set_al(-100);
  set_short("A german terrorist");
  set_long("This is a terrorist, wearing black clothes and a green army jacket.\n"+
           "He has long, unwashed hair, dark sunglasses, and an angry look.\n"+
           "He must have sneaked past the security!\n"+
           "Maybe he has come to kill the wizard or blow up the castle?\n");
  set_aggressive(1);

  /* Load attacking chats */
  set_a_chat_chance(20);
  load_a_chat("The terrorist yells: Verdammte bourgeois fascist lackey! R-A-F! R-A-F!");

  /* Grab a weapon */
  move_object(clone_object("/players/padrone/tower/npc/obj/bayonet"),
              this_object());
  init_command("wield bayonet");
  set_wc(10);
}
