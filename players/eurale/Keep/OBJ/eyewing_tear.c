#define TP this_player()
#define TO this_object()
#define ETP environment(this_player())
#include "/players/eurale/closed/ansi.h"
inherit "obj/treasure";

reset(arg) {
  if(arg) return;

set_id("eyewing tear");
set_alias("tear");
set_short(HIC+"eyewing tear"+NORM);
set_long(
  "This vile blue tear comes from the very acidic eyewing.  It has\n"+
  "strong medicinal value when used in healing elixirs.  The right\n"+
  "person would surely 'barter' for it.\n");

set_weight(1);
set_value(170 + random(10));
set_save_flag();
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int num;
num = 4400 + random(350);
if(!present("madame rue",ETP)) { write("What?\n"); return 1; }
if(str == "tear" || str == "eyewing tear") {
  write("Madame Rue's eyes grow big.  She scoops the blue tear into a\n"+
        "bottle and examines it closely.  When she finishes, she offers\n"+
        "to take it off your hands.  You laugh at the measly price she\n"+
        "tries to give you and the haggling begins.  You finally agree\n"+
        "on a fair price and you pocket the "+num+" coins she hands you.\n");
  TP->add_money(num);
  destruct(TO);
  return 1; }
}
