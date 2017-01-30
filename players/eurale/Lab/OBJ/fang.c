#include "/players/eurale/closed/ansi.h"
inherit "obj/treasure";
#define ETP environment(this_player())
#define TP this_player()

reset(arg) {
  if(arg) return;

set_id("fang");
set_alias("smilodon fang");
set_short(HIW+"smilodon fang"+NORM);
set_long(
  "This blackened fang was once in the mouth of a fearsome Smilodon.\n"+
  "It is worn smooth from constant chewing on hard objects like the\n"+
  "bones of adventurers.\n");

set_weight(1);
set_value(1850 + random(200));
}

query_no_save() { return 1; }

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int money;
if(str == "fang" || str == "smilodon fang") {
if(present("sedjak",ETP)) {
  write("Sedjak leans close to you and whispers, 'Thanks but no thanks.\n"+
        "I hear it's bad luck to possess any of those fangs but I'm\n"+
        "sure Madame Rue in the glade would put it to good use.'\n");
  return 1; }
if(present("madame rue",ETP)) {
money = 4111 + random(1567);
  write("Rue chuckles and sneers, 'Did that sniveling coward, Sedjak,\n"+
        "send you here with that?  He's too full of superstition for\n"+
        "his own good.  I'll surely put that to good use...' and she\n"+
        "takes "+money+" coins out from under her shawl and gives it\n"+
        "to you.\n");
  TP->add_money(money);
  destruct(this_object());
  return 1; }
}
}
