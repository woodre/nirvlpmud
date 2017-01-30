/*
File: shade.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 2/1/01
Description:
  A shade that resides in the graveyard in Caladon.  Wants revenge upon
the Baron.
*/
#include "defs.h"

inherit "/obj/monster.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("shade");
  set_short(BOLD+BLK+"Shade"+NORM);
  set_long(
"This is a strange transparent figure.  His features appear vaguely\n"+
"human and male, but their details are indistinct.  He appears to be\n"+
"quite distressed.  Perhaps you should 'talk' to him.\n"
  );
  set_race("spirit");
  set_level(15);
  set_hp(300); /* +50 */
  set_wc(16); /* -4 */
  set_ac(14); /* +2 */
  add_money(1000);
  set_al(50);
  set_chat_chance(6);
  load_chat("The shade moans sorrowfuly.\n");
  load_chat("The shade circles his grave fretfully.\n");
}

void init() {
  ::init();
  add_action("cmd_talk", "talk");
}

int cmd_talk(string str) {
  if(str!="to shade" && str!="to ghost") {
    notify_fail("Talk to who?\n");
    return 0;
  }
  write(
"The shade moans:\n"+
"  Woe unto me and woe unto the Barony of Caladon!  I was once the\n"+
"  loyal Castellan of Baron Hubert deBlood!  I thought his death was\n"+
"  an accident until I overheard his son Miguel conspiring to cheat\n"+
"  his half-brother of his inheritance.  Before I could tell anyone\n"+
"  Miguel had me murdered and framed his brother Jikhal for the crime!\n"+
"  I cannot rest until I hold Baron Miguel deBlood's head in my ghostly\n"+
"  hands!\n"
  );
  tell_room(environment(TP),"The shade moans incoherently at "+TPN+".\n",({ TP }));
  return 1;
}
