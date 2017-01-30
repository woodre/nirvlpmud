#include "defs.h"

inherit TEACHER;

void reset(int arg) {
  ::reset(arg);
  if(arg)return;
  set_name("kaiser");
  set_alias("todal");
  set_short("Kaiser Todal");
  set_long(
"Kaiser Todal does not fit the usual conception of a sorcerer.  He is\n"+
"tall and muscular, his skin bronzed and healthy.  He wears a leather\n"+
"vest and pants.  Master Todal is a master of summoning magic, which\n"+
"you may 'ask' him about.\n"
  );
  set_level(30);
  set_hp(500);
  set_wc(50);
  set_ac(30);
  set_chat_chance(4);
  load_chat("Master Todal stares thoughtfully at the summoning circle.\n");
  load_chat("Master Todal rubs out a rune in the summoning circle.\n");
  load_chat("Master Todal inscribes a rune in the summoning circle with a\npiece of chalk.\n");
  add_spell("inscribe circle","inscribe_circle",500,5);
  add_spell("summon torach","summon_torach",250000,6);
  add_spell("tangle vine","tangle_vine",350000,6);
  add_spell("summon golem","summon_golem",500000,7);
}
