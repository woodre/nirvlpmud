#include "/players/eurale/closed/ansi.h"
inherit "obj/treasure";
#define ETP environment(this_player())
#define TP this_player()

reset(arg) {
  if(arg) return;

set_id("claw");
set_alias("abishai claw");
set_short(BOLD+"abishai claw"+NORM);
set_long(
  "This piece of abishai claw would most certainly bring a goodly\n"+
  "number of coins if it were bartered to the right person.\n");

set_weight(1);
set_value(200 + random(200));
}

query_no_save() { return 1; }

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int money;
if(!present("sedjak",ETP)) return 0;
if(str == "claw" || str == "abishai claw") {
money = 4765 + random(400);
write("Sedjak takes the piece of abishai claw and smiles.  He looks\n"+
      "you in the eye and says, 'Nice... very nice' and he hands you\n"+
      money+" coins for it.\n");
TP->add_money(money);
destruct(this_object());
return 1; }
}
