#include "defs.h"
inherit "/obj/monster.c";
inherit WAXFUNS;

status flag_hoser;      /* has he called his buddy yet */
object hoser;           /* his buddy */

void reset(status arg) {

  ::reset(arg);

  if (arg) {
    flag_hoser = 0;
    return;
  }

  set_name("Repoman");
  set_short("Repoman");
  set_alt_name("repoman"); set_alias("monster");
  set_race("human");
  set_gender("male");
  set_long(line_wrap("This is Repoman.  He owns a vehicle repossession Company, \
and thinks he's a badass.  Earwax once threw him off the porch, so now \
Repoman only comes around if Earwax isn't here, or if his buddy is \
with him.\n"));
  set_level(23);
  set_al(-500);
  set_ac(15+random(5));
  set_wc(25+random(10));
  set_hp(750+random(100));
  set_aggressive(0);
  set_chat_chance(7);
  load_chat("Repoman says: I'm gonna kick Earwax's ass when I see him.\n");
  load_chat("Repoman says: Where the hell is he at, I have three repos to do.\n");
  load_chat("Repoman says: You don't want to mess with me, I'm hardcore.\n");
  load_chat("Repoman turns around, and you hear him inhale sharply.\n");
  set_a_chat_chance(7);
  load_a_chat("Repoman says: I'm gonna fuck you up worse than Earwax!\n");
  load_a_chat("Repoman tells you: I'm gonna fuck your eye sockets.\n");
  load_a_chat("Repoman says: I don't have time for this shit.\n");
  load_a_chat("Repoman says: Leave before this gets ugly.\n");
  add_money(3500+random(1000));
  set_chance(20);
  set_spell_dam(random(50));
  set_spell_mess1(HIR+"Repoman jabs you in the eye!\n"+NORM);
  set_spell_mess1(HIR+"Repoman bites you viciously.\n"+NORM);
}

int block_enter() {
  write(line_wrap("Repoman places his hand on your chest, shakes his finger \
in your face, and tells you, 'Nobody goes in there until I find Earwax.'\n"));
  say(line_wrap("Repoman places his hand on "+this_player()->query_name()+"'s chest, wags his finger \
in their face, and whispers something in their ear.\n"), this_player());
  return 1;
}

void init() {
  ::init();

  add_action("block_enter","enter");
}
