#include "defs.h"

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("confusius");
  set_alt_name("monk");
  set_short(BOLD+BLK+"A mysterious looking monk"+NORM);
  set_long(
    "This is an old looking monk with a long, snowy white beard who\n"+
    "appears both wise and mysterious.  He has walked for many a moon\n"+
    "in this desert.  You suspect that if you sit and listen to him he\n"+
    "will teach you his wisdom.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(12);
  set_wc(16);
  set_ac(9);
  set_hp(180);
  set_al(350);
  set_chat_chance(7);
  load_chat("Confusius says: \"Man who run in front of car get tired.\"\n");
  load_chat("Confusius says: \"Man who run behind car get exhausted.\"\n");
  load_chat("Confusius says: \"Man with hand in pocket feel cocky all day.\"\n");
  load_chat("Confusius says: \"Passionate kiss like spiders web - soon lead to undoing of fly..\"\n");
  load_chat("Confusius says: \"Virginity like bubble. One prick - all gone!\"\n");
  load_chat("Confusius says: \"Foolish man give wife grand piano.  Wise man give wife upright organ.\"\n");
  load_chat("Confusius says: \"Man who walk thru airport turnstile sideways going to Bangkok.\"\n");
  load_chat("Confusius says: \"Man with one chopstick go hungry.\"\n");
  load_chat("Confusius says: \"Man who scratches ass should not bite fingernails.\"\n");
  load_chat("Confusius says: \"Man who eat many prunes get good run for money.\"\n");
  load_chat("Confusius says: \"Baseball is wrong. Man with four balls cannot walk!\"\n");
  load_chat("Confusius says: \"Panties not best thing on earth, but next to it.\"\n");
  load_chat("Confusius says: \"War doesn't determine who's right. War determines who's left.\"\n");
  load_chat("Confusius says: \"Wife who put husband in doghouse soon find him in cat house.\"\n");
  load_chat("Confusius says: \"Man who sleep in cathouse by day, sleep in doghouse by night.\"\n");
  load_chat("Confusius says: \"Man who fight with wife all day, get no piece at night!\"\n");
  load_chat("Confusius says: \"Man who tell one too many light bulb jokes soon burn out!\"\n");
  load_chat("Confusius says: \"It takes many nails to build crib, but one screw to fill it.\"\n");
  load_chat("Confusius says: \"Man who drive like hell, bound to get there!\"\n");
  load_chat("Confusius says: \"Man who sit on tack get point!\"\n");
  load_chat("Confusius says: \"Man who stand on toilet is high on pot!\"\n");
  load_chat("Confusius says: \"Man who lives in glass house should change in basement.\"\n");
  load_chat("Confusius says: \"He who fishes in other man's well often catches crabs.\"\n");
  load_chat("Confusius says: \"Man who farts in church sits in own pew.\"\n");
}
