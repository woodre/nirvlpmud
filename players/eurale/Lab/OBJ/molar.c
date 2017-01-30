#include "/players/eurale/closed/ansi.h"
inherit "obj/treasure";
#define ETP environment(this_player())
#define TP this_player()

reset(arg) {
  if(arg) return;

set_id("tooth");
set_alias("molar");
set_short(BOLD+"broken molar"+NORM);
set_long(
  "A stained, worn down piece of old tooth.  It has broken roots\n"+
  "and a crack running down it like it was extracted violently.\n");

set_weight(1);
set_value(1300 + random(100));
}

query_no_save() { return 1; }

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int money;
if(!present("sedjak",ETP)) return 0;
if(str == "molar" || str == "broken molar" || str == "tooth") {
money = 3500 + random(800);
write("Sedjak rolls the tooth around with his fingers and then he\n"+
      "taps it on the top of his trunk.  He turns around, pockets\n"+
      "the broken tooth, and hands you "+money+" coins for it.\n");
TP->add_money(money);
destruct(this_object());
return 1; }
}
