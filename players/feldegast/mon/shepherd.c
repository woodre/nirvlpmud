#include "defs.h"
inherit "/obj/monster.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_short("Shepherd");
  set_name("shepherd");
  set_long(
"This is a humble shepherd, carrying a crook and wearing simple cotton\n"+
"clothing.\n");
  set_level(8);
  set_wc(12);
  set_ac(7);
  set_hp(120);
  add_money(random(200));
  load_chat("The shepherd spits.\n");
  load_chat("The shepherd tends to his flock.\n");
  load_chat("The shepherd says: Eh? Wotsa dune boot?\n");
  move_object(clone_object(WEP_PATH+"crook.c"),this_object());
}
