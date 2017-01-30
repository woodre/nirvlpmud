/*
 * p3_mathilda.c
 * Mathilda the thief from path3.c
 */

inherit "obj/monster";

void
reset(status arg)
{
  object torch, bag;

  ::reset(arg);
  if (arg)
    return;
  set_name("mathilda");
  set_level(2);
#if 0  /* Adjusted for Nirvana monster.guide -- Rumplemintz */
  set_ep(100);
  set_hp(7);
#else
  set_hp(30);
  set_wc(5);
  set_ac(3);
#endif
  set_al(150);
  set_short("Mathilda the small thief (good)");
  set_long("Mathilda is dressed in black clothes, and she carries a dagger\n"+
           "and a bag to carry things in. She is probably a thief.\n"+
           "But something terrible has happened to Mathilda, and she\n"+
           "is horribly hurt. She will probably die any minute now.\n");

  /* Setup the chats */
  set_chat_chance(20);
  load_chat("Mathilda groans.\n");
  load_chat("Mathilda groans loudly.\n");
  load_chat("Mathilda looks very bad.\n");
  load_chat("Mathilda coughs. She looks real bad now.\n");
  load_chat("Mathilda says: Oh, why didn't I buy that ticket...\n");
  load_chat("Mathilda says: As soon as I got in there, they saw that I had no ticket.\n");
  load_chat("Mathilda says: Whatever you do, don't forget to buy a ticket!\n");
  load_chat("Mathilda says: I think I'm going to die.\n");
  load_chat("Mathilda says: I should have bought a ticket at the gate... Arrrgh!\n");
  load_chat("Mathilda says: Don't you EVER drop your ticket while inside.\n");
  load_chat("Mathilda says: Don't make my mistake. Buy a ticket! Arrrgh!\n");
  load_chat("Mathilda says: The castle south of here... The ticket... Arrrgh...\n");
  load_chat("Mathilda says: The giants were bad, but the dragon was worse.\n");
  load_chat("Mathilda says: If you don't have a ticket, all of them will attack you!\n");

  /* Setup the attacking chats */
  set_a_chat_chance(20);
  load_a_chat("Mathilda bleeds a little.");

  /* Setup gear and stats */
  move_object(clone_object("/players/padrone/outside/npc/obj/math_dagger"),
              this_object());
  bag = clone_object("obj/bag");
  move_object(bag, this_object());
  torch = clone_object("/obj/torch");
  torch->set_name("torch");
  torch->set_fuel(2000);
  torch->set_weight(1);
  move_object(torch, bag);
  init_command("wield dagger");
  set_wc(5);
}
