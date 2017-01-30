/* Roy */

#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */

inherit "/obj/monster.c";

reset(arg)
{
  ::reset(arg);
  if (!arg)
  {
  /* Roy's whip disappears as an illusion when dropped at his death. */
    move_object(clone_object("/players/aingeal/casino/weapons/whip2.c"),
                this_object());
  }
  set_name("roy");
  set_alias("roy");
  set_alt_name("entertainer");
  set_short("Roy");
  set_race("human");
  set_long("Roy flashes a charming smile at the audience, his\n\
short dark hair and handsome figure catching the eye\n\
of many a lady in the crowd.  Dressed in tight-fitting\n\
black pants and a white tuxedo shirt open at the chest,\n\
he glides across the stage, ready to assist Siegfried \n\
with another breathtaking feat.\n");
  set_level(13);
  set_ac(9 + random(2));
  set_wc(15 + random(3));
  set_hp(195);
  set_al(-100);
  set_aggressive(0);
  add_money(random(50) + 550);
  set_chat_chance(20);
  set_a_chat_chance(30);
  /* Regular chats */
  load_chat("Roy muses, 'We followed our dreams, for dreams were all\n\
we had.  In the process, our lives became magical.'\n");
  load_chat("Roy steps back from the scene of the latest feat\n\
of magic with a theatrical flourish of his arm.\n");
  load_chat("Roy pauses to nuzzle the ruff of an enormous Magical\n\
White Lion.  The lion yawns, showing an impressive\n\
array of huge, white fangs, then pads silently out\n\
of view backstage.\n");
  load_chat("Roy softly advises, 'Look for the magic that is around\n\
you....in nature, flowers, and all the animals that\n\
share this planet with us.'\n");
  /* Combat chats */
  load_a_chat("Roy cracks his whip with a startling "+BLU+"SNAP!"+NORM+"\n");
  load_a_chat("Roy curses at you in German!\n");
  load_a_chat("Roy rolls up his sleeves menacingly, showing well-muscled\n\
arms with a patchwork of old scars as he growls in challenge!\n");
  load_a_chat("Roy shouts to Siegfried, 'Get back! I'll take care of this!'\n");
  set_dead_ob(this_object());
}

/* Roy's corpse will disappear as illusion upon his death.*/
monster_died()
{
  object corpse;
  corpse=present("corpse",environment());
  say("\n\t"+YEL+"Roy laughs maliciously as he\n\t\tsuddenly DISAPPEARS\n\
from view!'"+NORM+"\n\n");
  destruct(corpse);
  return 1;
}
