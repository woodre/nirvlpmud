#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";
#define TP this_player()
#define TO this_object()

reset(arg) {
set_name("talon");
set_alias("margoyle talon");
set_short(GRY+"margoyle talon"+NORM);
set_long(
  "Hung on a piece of sinew that used to run through the margoyle's\n"+
  "arm is a gnarly talon.  It is said to have protective powers as\n"+
  "well as great barter value.\n");

set_ac(2);
set_type("amulet");
set_weight(1);
set_value(950);
set_no_clean(1);
}

query_no_save() { return 1; }

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int coins;
if(!present("sedjak",environment(TP))) return 0;
  coins = 4500 + random(700);
if(str == "talon" || str == "margoyle talon") {
  write("You hand the talon to Sedjak. He grins a yellow-toothed\n"+
  "grin and hands you "+coins+" coins before hiding it in his chest.\n");
  TP->add_money(coins);
  destruct(TO);
  return 1; }
}
