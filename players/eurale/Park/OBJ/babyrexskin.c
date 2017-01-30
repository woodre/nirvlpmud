/*  Changed to barterable item 8/17/02 - Eurale  */

#include "/open/ansi.h"
inherit "obj/treasure";
#define ETP environment(this_player())
#define TP this_player()
reset(arg) {
  if(arg) return;

set_id("skin");
set_alias("triceratops skin");
set_short(GRN+"triceratops skin"+NORM);
set_long(
  "This thick, leathery skin comes from one of the fiercest fighters known\n"+
  "and can be bartered for great sums.\n");

set_weight(2);
set_value(875);
set_save_flag();
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int val;
if(!str) { write("What?\n"); return 1; }
if(present("sedjak",ETP)) {
  val = 3400 + random(200);
  write("Sedjak takes the beautiful skin and gives you "+val+" coins.\n");
  TP->add_money(val);
  destruct(this_object());
  return 1; }
return 1;
}
