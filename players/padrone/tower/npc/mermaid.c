/*
 * mermaid.c
 * mermaid in poolroom
 */

inherit "obj/monster";

status wait;
object murderer, guard;

void
reset(status arg)
{
  monster::reset(arg);
  if (arg)
    return;
  set_name("mermaid");
  set_alias("Mermaid");
  set_gender("female");
  set_level(1);
#if 0 /* Adjusting for Nirvana monster.guide -- Rumplemintz */
  set_hp(40);
  set_wc(1);
#else
  set_hp(15);
  set_wc(5);
  set_ac(3);
#endif
  set_al(600);
  set_short("A cute little mermaid");
  set_long("The mermaid is a small, beautiful creature,\n"+
           "happily splashing around in the pool.\n"+
           "She looks at you innocently with her large green eyes,\n"+
           "and being a hardened warrior you estimate that it would\n"+
           "probably be very easy to kill her. But you also understand\n"+
           "that it could be a very, very bad move indeed to kill this\n"+
           "little mermaid, who must be a very close friend of the Wizard's...\n");

  /* Spell setup */
  set_chance(20);
  set_spell_dam(1);
  set_spell_mess1("The mermaid splashes some water at her attacker.");
  set_spell_mess2("The mermaid splashes some water at you.");

  /* Load chats */
  set_chat_chance(10);
  load_chat("The mermaid smiles happily.\n");
  load_chat("The mermaid splashes happily.\n");

  /* Load attacking chats */
  set_a_chat_chance(50);
  load_a_chat("The mermaid begs: Please don't kill me!\n");
  load_a_chat("The mermaid asks you: Why do you do this?\n");
  load_a_chat("The mermaid screams for help.\n");
  load_a_chat("The mermaid screams for help.\n");
  load_a_chat("The mermaid bleeds on you.\n");
}
