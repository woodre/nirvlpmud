#include "/players/eurale/closed/ansi.h"
inherit "obj/treasure";
#define ETP environment(this_player())
#define TP this_player()

reset(arg) {
  if(arg) return;

set_id("tip");
set_alias("abishai claw");
set_short(GRY+"wing tip"+NORM);
set_long(
  "This charred, wing tip from a guardian yugoloth is a very\n"+
  "magical commodity when bartered.\n");

set_weight(1);
set_value(1300 + random(200));
}

query_no_save() { return 1; }

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int money;
if(!present("sedjak",ETP)) return 0;
if(str == "tip" || str == "wing tip") {
money = 4555 + random(1000);
write("You hand the yugoloth wing tip to Sedjak.  He smells the\n"+
      "burnt wing tip and says, 'Wish you'd brought me the whole\n"+
      "wing, but I'll take this anyhow!' and he hands you "+money+"\n"+
      "coins for it and puts it in his chest.\n");
TP->add_money(money);
destruct(this_object());
return 1; }
}
