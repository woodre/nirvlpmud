#define TP this_player()
#define ETP environment(this_player())
#include "/players/eurale/closed/ansi.h"
inherit "obj/treasure";

reset(arg) {
  if(arg) return;

set_id("disir slime");
set_alias("slime");
set_short(GRN+"disir slime"+NORM);
set_long(
  "This gob of disir slime smells putrid.  It has a pale green color\n"+
  "and is said to be a power ingredient in the mixing of different\n"+
  "potions.  You could probably 'barter' with it if you find the right\n"+
  "person.\n");

set_weight(1);
set_value(270 + random(10));
set_save_flag();
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int num;
num = 4000 + random(300);
if(!present("madame rue",ETP)) { write("What?\n"); return 0; }
if(str == "slime" || str == "disir slime") {
  write("Rue takes the disir slime and puts it in a glass container.\n"+
        "She grins and says, 'A strong warrior you must be to slay\n"+
        "disirs.  Their slime is a powerful ingredient in my potions'\n"+
        "and she quickly hands you "+num+" coins.\n");
  TP->add_money(num);
  destruct(this_object());
  return 1; }
}
