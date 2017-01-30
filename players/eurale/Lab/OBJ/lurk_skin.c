#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";
#define ETP environment(this_player())
#define TP this_player()

reset(arg) {
  if(arg) return;

set_id("skin");
set_alias("lurker skin");
set_short(GRY+"textured lurker skin"+NORM);
set_long(
  "Gray and resembling stone, this textured skin came from the vicious lurker\n"+
  "and would bring a fancy price if bartered.\n");

set_ac(1);
set_type("chest");
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
if(str == "skin" || str == "lurker skin" || str == "textured skin") {
money = 3250 + random(500);
write(
  "Sedjak looks at the lurker skin and whispers, 'I ain't seen one of these\n"+
  "in quite some time' and hands you "+money+" coins for it.\n");
TP->add_money(money);
destruct(this_object());
return 1; }
}
