#include "defs.h"

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("gambler");
  set_alt_name("gambler");
  set_short("A Gambler");
  set_long(
"This gambler looks like he's been losing consistently all night.\n"+
"He has a five o'clock shadow, rings around his eyes, and appears\n"+
"to be slightly intoxicated.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(12);
  set_wc(16);
  set_ac(9);
  set_hp(180);
  set_al(-150+random(300));
  set_chat_chance(10);
  load_chat("The gambler throws the dice...AND WINS!!!\n");
  load_chat("The gambler throws the dice...AND LOSES!!!\n");
  set_a_chat_chance(6);
  load_a_chat("Gambler says: I haven't got any money left!!!\n");
  move_object(clone_object("/obj/dice.c"),this_object());
  add_money(random(600));
}
