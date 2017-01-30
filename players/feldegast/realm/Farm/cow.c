#include "../def.h"

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Lucy the Cow");
  set_alt_name("lucy");
  set_alias("cow");
  set_short("Lucy the Cow");
  set_long(
"Lucy is a sedate looking cow with big blue eyes\n"+
"and dark black spots.\n"
);
  set_gender("female");
  set_race("bovine");
  set_level(6);
  set_wc(10);
  set_ac(5);
  set_hp(90);
  set_al(0);
  set_chat_chance(5);
  load_chat("Lucy comments: Moo.\n");
  load_chat("Lucy states: Moooooooo...\n");
  load_chat("Lucy mutters: Moooooo!\n");
  load_chat("Lucy rationalizes: Moooooo?\n");
  load_chat("Lucy inquires: Mooooooooooooo?\n");
  load_chat("Lucy soliloquies: Mooo moooooooooo moooooooooOOO!\n");
  set_dead_ob(this_object());
}
monster_died(ob) {
  move_object(clone_object(PATH+"Farm/rawmeat"),ob);
}
