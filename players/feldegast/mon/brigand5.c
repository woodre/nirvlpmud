#include "defs.h"

inherit "/obj/monster.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("septic");
  set_alias("snivelface");
  set_alt_name("brigand");
  set_short("Septic Snivelface");
  set_long(
    "Septic is an unusually civilized appearing goblin.  Which is to\n"+
    "say he only drools upon friends and at least one article of his\n"+
    "clothing (his armor) is put on correctly.  Septic is stupid, like\n"+
    "all goblins, but he has managed to build up some muscles and he has\n"+
    "become quite adept at clubbing helpless traders.\n"
  );
  set_gender("male");
  set_race("goblin");
  set_level(15);
  set_hp(225);
  set_al(-250);
  set_chat_chance(4);
  load_chat("Septic carefully picks his nose.\n");
  load_chat("Septic drools.\n");
  load_chat("Septic chews on his club.\n");
  load_chat("Septic pontificates: Duuuuuuuh...\n");
  set_a_chat_chance(25);
  load_a_chat("Septic WHACKS you with his club.\n");
  load_a_chat("Septic howls like a maniac!\n");
  load_a_chat("Septic gets down and starts gnawing on your shoes.\n");
  load_a_chat("Septic barks at you like a dog.\n");
  move_object(clone_object(ARM_PATH+"leather.c"),this_object()); /* 300 coins */
  move_object(clone_object(WEP_PATH+"club.c"),this_object()); /* 300 coins */
  init_command("wear leather");
  init_command("wield club");
  add_money(250+random(100));
  set_wc(20);
  set_ac(12);
}

