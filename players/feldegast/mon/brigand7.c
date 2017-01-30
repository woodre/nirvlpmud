#include "defs.h"

inherit "/obj/monster.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("tricky");
  set_alias("slicky");
  set_alt_name("brigand");
  set_short("Tricky Slicky");
  set_long(
"Tricky is a thin man in his forties with a salt and pepper\n"+
"beard and a receding hairline.  His body is covered in small\n"+
"thin scars.  He has a fondness for knives and daggers, which\n"+
"he wears about his body.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(16);
  set_hp(400);
  set_al(-350);
  set_chat_chance(4);
  load_chat("Tricky says: Tricky wants to know what you're doing here.\n");
  load_chat("Tricky smiles as he slowly cuts his arm with a knife.\n");
  load_chat("Tricky says: Tricky wonders who let YOU in?\n");
  set_a_chat_chance(35);
  load_a_chat("Tricky says: Tricky says DIE!\n");
  load_a_chat("Tricky says: Tricky thinks you're good.\n");
  load_a_chat("Tricky flicks his dagger at you.\n");
  move_object(clone_object(WEP_PATH+"knife.c"),this_object()); /* 150 coins */
  move_object(clone_object(WEP_PATH+"dagger.c"),this_object()); /* 200 coins */
  move_object(clone_object(WEP_PATH+"knife.c"),this_object()); /* 150 coins */
  move_object(clone_object(WEP_PATH+"dagger.c"),this_object()); /* 200 coins */
  init_command("wield dagger");
  add_money(random(300));
  set_wc(22);
  set_ac(13);
}

