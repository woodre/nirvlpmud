#include "/players/eurale/closed/ansi.h"
inherit "obj/treasure";
#define ETP environment(this_player())
#define TP this_player()

reset(arg) {
  if(arg) return;

set_id("pincer");
set_alias("scorpion pincer");
set_short(HIG+"scorpion pincer"+NORM);
set_long(
  "The green pincer from a giant scorpion.  This item often\n"+
  "brings a good value when bartered.\n");

set_weight(1);
set_value(1250 + random(200));
}

query_no_save() { return 1; }

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int money;
if(!present("sedjak",ETP)) return 0;
if(str == "pincer" || str == "scorpion pincer") {
money = 3511 + random(1000);
write("Sedjak look at the pincer and whispers, 'I've not seen one\n"+
      "of these in a long time.  You must have stolen it from one\n"+
      "of the better adventurers.  So be it, I'll take it!' and he\n"+
      "discretely slides "+money+" coins to you.\n");
TP->add_money(money);
destruct(this_object());
return 1; }
}
