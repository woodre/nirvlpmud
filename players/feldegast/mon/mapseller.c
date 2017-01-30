/*
A mapseller for the city of Sudakan in the Jal-Hab desert.
*/
#include "defs.h"

inherit MONSTER;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("kid");
  set_alt_name("merchant");
  set_short("A young merchant");
  set_long(
"This young merchant makes his living selling maps to travellers as\n"+
"they enter the gates of Sudakan.  Although he appears just over\n"+
"fourteen years old, he is neatly dressed in loose cotton robes and\n"+
"wears a cap on his head.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(8);
  set_wc(12);
  set_ac(7);
  set_hp(120);
  set_al(550);
  add_money(350);
  set_chat_chance(4);
  load_chat("The young merchant says: Maps!  Maps for sale!\n");
  load_chat("The young merchant says: Would you like a map?  Just 50 coins!\n");
  set_a_chat_chance(5);
  load_a_chat("The young merchant screams for help!\n");
  load_a_chat("The young merchant kicks you in the shin.\n");
  load_a_chat("The young merchant runs through the crowd.\n");
}

void init() {
  ::init();
  add_action("cmd_buy","buy");
}

int cmd_buy(string str) {
  if(!str || str!="map") {
    notify_fail("Buy what?\n");
    return 0;
  }
  if((int)TP->query_money() < 50) {
    write("The young merchant says: I do not GIVE my maps away.\n");
    return 1;
  }
  if(!((int)TP->add_weight(1))) {
    write("The young merchant says: You are too burdened.\n");
    return 1;
  }
  move_object(clone_object(OBJ_PATH+"map-sudak.c"),TP);
  write("The young merchant takes your coins and hands you a scroll.\n");
  TP->remote_say(TPN+" purchases a map from the young merchant.\n");
  return 1;
}
