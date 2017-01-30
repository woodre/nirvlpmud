/* 11/15/05 Earwax: moved if(arg) return to above item cloning */
#include "/players/feldegast/defines.h"
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(ARM_PATH+"feathercloak.c"),this_object());
  set_name("birdtalker");
  set_short(HIY+"Birdtalker"+NORM);
  set_long(
"     The Bird-talker is a young woman with a glazed expression\n"+
"on her face.  She wears a colorful cloak of feathers that covers\n"+
"her from shoulders to ankles.  The birds talk to her and tell her\n"+
"what they see.\n"
  );
  set_gender("female");
  set_race("human");
  set_level(4);
  set_wc(9);
  set_ac(4);
  set_hp(60);
  set_al(50);
  set_aggressive(0); 
  set_chat_chance(3);
  load_chat(
"\nThe Birdtalker says: The birds tell me:\n"+
  "                     Across the terrible jungle deep\n"+
  "                     Prince Ngana lies asleep\n"+
  "                     The birds tell me.\n"
);
  load_chat(
"\nThe Birdtalker says:\n"+
"\t\tThe birds tells me--\n"+
"\t\tA hero must cross the jungle deep\n"+
"\t\tFacing his greatest fears\n"+
"\t\tAnd when he reaches him must weep\n"+
"\t\tTwo lions tears.\n"+
"\t\tThe birds tell me!\n"
);
  set_a_chat_chance(5);
  load_a_chat("Birdtalker squawks!\n");
  load_a_chat("Birdtalker yells, 'Pirate!'\n");
}

