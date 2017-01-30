/* Drew Carey */

#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "/obj/monster.c";

reset(arg)
{
  ::reset(arg);
  if (!arg)
  {
    /* Drew's glasses are helmet armor worth 500 coins. */
    move_object(clone_object("/players/aingeal/casino/armor/glasses.c"),
    this_object());
  }
  set_name("drew");
  set_alias("carey");
  set_alt_name("entertainer");
  set_short("Drew Carey");
  set_race("human");
  set_long("Drew is a funny-looking plump man with a ready smile\n\
and a receding hairline.  Oversized black-rimmed glasses\n\
overwhelm his face.  Dressed in a conservative suit that \n\
completes his comically nerdy persona, he ambles across the\n\
stage, ready to MC the latest game of 'Whose Line Is It Anyway'.\n");
  set_level(16);
  set_ac(12 + random(2));
  set_wc(20 + random(3));
  set_hp(250 + random(75));
  set_al(-1);
  set_aggressive(0);
  add_money(random(101) + 900);
  set_chat_chance(20);
  set_a_chat_chance(30);
  set_chance(10);
  set_spell_mess1("\n\tDrew Carey " + GRN + "FLATTENS " + NORM +
    "his attacker \n\tas he tackles his opponent with his substantial \
weight!\n");
  set_spell_mess2("\n\tDrew Carey " + GRN + "FLATTENS " + NORM +
    "you \n\tas he tackles you with his substantial weight!\n");
  set_spell_dam(15);
  /* Regular chats */
  load_chat("Drew quips, 'So, you hate your job?  Join our support group-\n\
it's called EVERYBODY!  They meet at the bar...'\n");
  load_chat("Drew laughs, 'I'm sorry if my friends make a bad impression,\n\
but it's an accurate one.'\n");
  load_chat("Drew introduces, 'And now....it's time to play 'Greatest Hits!'\n");
  load_chat("Drew laughs,'I don't want strangers to have sex in my bed...\n\
unless I'm one of them.'\n");
  load_chat("Drew directs, 'And now, it's time to play Scenes From a Hat!\n");
  load_chat("Drew jokes, 'I never hit a deer -- unless I intend to eat it.'\n");
  load_chat("Drew awards 10,000 points to Ryan Stiles - just because.\n");
  /* Combat chats */
  load_a_chat("Drew charges at his attacker like a round, flabby linebacker!\n");
  load_a_chat("Drew cringes in fear!\n");
  load_a_chat("Drew screams in anger, emitting a high-pitched feminine squeal!\n");
  load_a_chat("Drew backhands you across the face with one meaty hand!\n");
  set_dead_ob(this_object());
}

/* Drew will summon the other 'Whose Line Is It Anyway' players when he dies.*/
monster_died(ob)
{
  write("\n\tDrew shouts, 'The next game will be played by \n\
\t\t'Ryan, Colin, and Wayne!'\n\n");
  tell_room(environment(),
    "\n\t"+BLU+"Ryan Stiles, Colin Mochrie, and Wayne Brady\n"+
    "\n\tSPRING from the shadows at the back of the stage!"+NORM+"\n");
  move_object(clone_object("/players/aingeal/casino/NPC/stiles.c"));
  move_object(clone_object("/players/aingeal/casino/NPC/mochrie.c"));
  move_object(clone_object("/players/aingeal/casino/NPC/wbrady.c"));
}
