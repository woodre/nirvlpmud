/*
 * t3_witness.c
 * jehova witness from tower3.c
 */

inherit "obj/monster";

void
reset(status arg)
{
  if (arg)
    return;
  monster::reset(arg);
  set_name("witness");
  set_alias("witness of jehova");
  set_level(3);
#if 0  /* Adjusting for Nirvana monster.guide - Rumplemintz */
  set_male();
#else
  set_wc(7);
  set_ac(4);
  set_hp(45);
#endif
  set_al(100);
  set_short("One of Jehova's Witnesses");
  set_long("This person is a Witness of Jehova.\n"+
           "He is not actually ugly, and he shows no obvious signs of insanity,\n"+
           "but he has the unmistakeable look of a disciple of Jehova.\n"+
           "If he cam knocking on your door, you wouldn't let him in.\n");

  /* Spell setup */
  set_chance(20);
  set_spell_dam(10);
  set_spell_mess1("Witness tries to exorcise a demon from his attacker.");
  set_spell_mess2("Witness tries to exorcise a demon from you. Ouch! That hurt!");

  /* Chat setup */
  set_chat_chance(50);
  load_chat("Witness says: Armageddon is close!\n");
  load_chat("Witness says: Do you really believe that the world was created by accident?\n");
  load_chat("Witness says: 6000 years ago, the world was created. Yes, created!\n");
  load_chat("Witness says: The Milennium is close!\n");
  load_chat("Witness says: Man was created by a higher intelligence. Isn't that obvious?\n");
  load_chat("Witness says: An explosion in a library will not create the Bible!\n");
  load_chat("Witness says: Let me give you this book!\n");
  load_chat("Witness says: Hallelujah!\n");
  load_chat("Witness says: Amen.\n");
  load_chat("Witness says: Oh yes, the devil is real. How could he else have fooled\n" +
            "              so many people to think that he doesn't exist?\n");
  load_chat("Witness says: Evil spirits sometimes pose as dead people to fool the living.\n");
  load_chat("Witness says: No, we don't use the cross as our symbol.\n");
  load_chat("Witness says: 144000, that's right.\n");

  /* Attacking chat setup */
  set_a_chat_chance(50);
  load_a_chat("Witness says: You are possessed! I exorcise you! Begone, foul spirit!\n");
  load_a_chat("Witness says: Jehova, I am ready!\n");
  load_a_chat("Witness says: Jehova! Help!\n");
  load_a_chat("Witness says: Go away! Can't you see I'm a Witness of Jehova?\n");
}
