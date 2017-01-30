/*
 * guard in north_shore.c
 */

inherit "obj/monster";

void
reset(status arg)
{
  ::reset(arg);
  if (arg)
    return;
  set_name("guard");
  set_alias("drunk guard");
  set_short("A somewhat hurt and very drunk guard");
  set_long("This man seems to be a castle guard from a castle somewhere.\n"+
           "He has obviously been in a fight, and now he is trying to forget\n"+
           "his problems with the help of alcohol. He is roaring drunk.\n");
  set_level(2);
#if 0  /* Adjusted for Nirvana monster.guide -- Rumplemintz */
  set_hp(20);
#endif
  set_al(15);

  /* Setup chats */
  set_chat_chance(20);
  load_chat("The guard says: The bashtardsh shneaked up on ush.\n");
  load_chat("The guard says: They attacked us right in the middle of the plainsh.\n");
  load_chat("The guard says: Bloody MILLION of thoshe piratsh!\n");
  load_chat("The guard says: They jusht took the castle...\n");
  load_chat("The guard says: I wash lucky to get away alive.\n");
  load_chat("The guard says: Oh BOY will the Wish be pished when he hearsh about thish!\n");
  load_chat("The guard says: Who knowsh where the caschtle isch now?\n");
  load_chat("The guard says: They could have taken it anywhere by now! Yesh!\n");
  load_chat("The guard says: We were juscht walking around out in the plainsch up north.\n");
  load_chat("The guard says: Real nishe cashtle. Too bad the piratsh shtole it.\n");
  load_chat("The guard says: They are not really that tough, those piratsh...\n");
  load_chat("The guard says: A few guysh like you could handle this, you know.\n");
  load_chat("The guard says: That cashtle could be really usheful, you know.\n");
  load_chat("The guard says: I think they climbed up the rope ladder...\n");
  load_chat("The guard says: We were up north, in the plainsh.\n");
  load_chat("The guard seems to fall, but takes a step and recovers.\n");
  load_chat("The guard hiccups.\n");
  load_chat("The guard looks drunk.\n");
  load_chat("The guard burps.\n");

  /* Get the gear and setup stats */
  move_object(clone_object("/players/padrone/outside/npc/obj/guard_axe"),
              this_object());
  move_object(clone_object("/players/padrone/outside/npc/obj/guard_helm"),
              this_object());
  init_command("wear helmet");
  init_command("wield axe");

  set_hp(15);
  set_wc(5);
  set_ac(3);
}
