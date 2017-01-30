#include "/players/eurale/closed/ansi.h"
inherit "obj/treasure";
#define ETP environment(this_player())
#define TP this_player()

reset(arg) {
  if(arg) return;

set_id("scale");
set_alias("troglodyte scale");
set_short(GRY+"troglodyte scale"+NORM);
set_long(
  "This leathery scale can only have come from the fearsome\n"+
  "troglodyte.  It is dried and wrinkled but could be bartered\n"+
  "for a handsome price to make some magical potion.\n");

set_weight(1);
set_value(1000 + random(100));
}

query_no_save() { return 1; }

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int money;
if(!present("sedjak",ETP)) return 0;
if(str == "scale" || str == "troglodyte scale") {
money = 2500 + random(800);
write("You show Sedjak the troglodyte scale. He wrings his hands\n"+
      "and looks around.  The two of you haggle over the value\n"+
      "and settle on "+money+" coins which he gladly hands over to\n"+
      "you.\n");
TP->add_money(money);
destruct(this_object());
return 1; }
}
