#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";
#define ETP environment(this_player())
#define TP this_player()

reset(arg) {
  if(arg) return;

set_id("shell");
set_alias("bulette shell");
set_short(GRN+"bulette shell"+NORM);
set_long(
  "A continuous, flexible scale shell with a spiney backbone. [barterable]\n");

set_ac(3);
set_type("armor");
set_weight(3);
set_value(900 + random(200));
set_no_clean(1);
}

query_no_save() { return 1; }

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int money;
if(!present("sedjak",ETP)) return 0;
if(str == "shell" || str == "bulette shell" || str == "scale") {
money = 1750 + random(500);
write(
  "Sedjak looks at the bulette shell and whispers, 'I ain't seen one of these\n"+
  "in quite some time' and hands you "+money+" coins for it.\n");
TP->add_money(money);
destruct(this_object());
return 1; }
}
