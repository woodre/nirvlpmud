#include "def.h"

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(PATH+"Obj/key.c"),this_object());
  set_name("walenski");
  set_alt_name("detective");
  set_alias("wal");
  set_short("Detective Walenski");
  set_long(
"Detective Walenski is a man in his late thirties with\n"+
"a receding hairline and an unshaven mug.  His haunted\n"+
"red eyes reflect the panic caused by a horrible secret\n"+
"revealed.\n"
);
  set_gender("male");
  set_race("human");
  set_level(10);
  set_wc(15);
  set_ac(7);
  set_hp(155);
  add_money(300+random(100));
  set_al(350);
  set_chat_chance(5);
  load_chat("Detective Walenski says: We are living in an illusion!\n");
  load_chat("Detective Walenski scribbles a red spiral on the wall.\n");
  load_chat("Detective Walenski says: They'll come for me too soon.\n");
  load_chat("Detective Walenski says: I know how to escape this place.\n");
  set_a_chat_chance(6);
  load_a_chat("Detective Walenski says: Yes...This is one way to escape them.\n");
  load_a_chat("Detective Walenski says: Do you think any of this matters?\n");
}
