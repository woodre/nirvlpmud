/*
Disclaimer: This monster is not intended to bear any resemblance to
warrior princesses either alive or dead, or somewhere in between.
*/
#include "defs.h"

inherit "/obj/monster.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("xexia");
  set_alias("warrior");
  set_alt_name("brigand");
  set_short("Xexia, Warrior Brigandess");
  set_long(
"Xexia is a beautiful dark-eyed warrior-woman with long black hair\n"+
"tied back in a pony-tail.  She wears a tight-fitting suit of leather\n"+
"armor that shows off her legs.  Xexia seems simultaneously strong and\n"+
"competent and yet feminine and vulnerable.\n"
  );
  set_gender("female");
  set_race("human");
  set_level(16);
  set_hp(400);
  set_al(-350);
  set_chat_chance(4);
  load_chat("Xexia tosses her long black hair.\n");
  load_chat("Xexia says: You should leave.  NOW.\n");
  set_a_chat_chance(35);
  load_a_chat("Xexia screams an ululating battle-cry!\n");
  load_a_chat("Xexia jumps up into the air and kicks you.\n");
  load_a_chat("Xexia wraps her legs around your neck and chokes you.\n");
  move_object(clone_object(ARM_PATH+"leather.c"),this_object()); /* 300 coins */
  move_object(clone_object(WEP_PATH+"sword.c"),this_object()); /* 600 coins */
  init_command("wear leather");
  init_command("wield sword");
  set_wc(22);
  set_ac(13);
}

