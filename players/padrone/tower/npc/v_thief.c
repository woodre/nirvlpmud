/*
 * v_thief.c
 * Big thief in vault.c
 */

inherit "obj/monster";

object letter;

void
reset(status arg)
{
  monster::reset(arg);
  if (arg)
    return;
  set_name("big thief");
  set_gender("male");
  set_alias("thief");
  set_level(16);
#if 0 /* Adjusting for Nirvana monster.guide -- Rumplemintz */
  set_hp(200);
  set_ac(10);
#else
  set_hp(300);
  set_ac(13);
  set_wc(22);
#endif
  set_al(-50);
  set_short("A big thief");
  set_long("This is an experienced and dangerous criminal.\n"+
           "He has managed to sneak into the vault, despite the Rambos!\n");
  set_aggressive(1);

  /* Spell setup */
  set_chance(20);
  set_spell_dam(30);
  set_spell_mess1("The theif throws a knife with astonishing accuracy.");
  set_spell_mess2("The thief throws a knife with astonishing accuracy at you.");

  /* Gear */
  letter = clone_object("/players/padrone/obj/thing");
  letter->set_name("letter");
  letter->set_alias("official letter");
  letter->set_short("An official letter from Padrone");
  letter->set_long("It is written on a sheet of high-quality paper\n"+
                   "with the official Castle of Padrone letterhead.\n"+
                   "Maybe you should try to read it?\n");
  letter->set_read_file("/players/padrone/tower/vault_letter.txt");
  letter->set_can_get(1);
  letter->set_weight(1);
  letter->set_value(10);
  move_object(letter, this_object());
  move_object(clone_object("/players/padrone/tower/npc/obj/firesword"),
              this_object());
  init_command("wield sword");
}
