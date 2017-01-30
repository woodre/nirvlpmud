#include "defs.h"

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(ARM_PATH+"padded.c"),this_object()); /* 100 */
  move_object(clone_object(WEP_PATH+"mace.c"),this_object()); /* 450 */
  init_command("wear armor");
  init_command("wield mace");
  add_money(200+random(200));
  set_name("squire");
  set_short("Squire");
  set_long(
"This is a stout squire in his early twenties.  He is garbed in the\n"+
"white and red colors of his knight's order.  He is also well-armed\n"+
"and trained in the use of his weapons.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(15);
  set_wc(18+random(3));
  set_ac(11+random(3));
  set_hp(200+random(50));
  set_al(400+random(400));
  set_chat_chance(4);
  load_chat("Squire says: This castle is haunted, I'm sure of it.\n");
  load_chat("Squire says: Oh, my aching back.\n");
  load_chat("Squire says: This land is too hot and dry.\n");
  load_chat("Squire says: What're the odds we'll actually find the stone anyway?\n");
  load_chat("Squire complains: Move this, move that, cook this, kill that.\n");
}
