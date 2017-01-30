/* changed this to a single use so that it fit the doc/build/RULES guidelines
   for treasure value.  Now there is a single full heal if the player kills
   both the hiv and the staphylococ. 8.16.02 - Eurale  */

#include "/open/ansi.h"
inherit "obj/treasure";
#define ETP environment(this_player())
#define TP this_player()

reset(arg) {
  if(arg) return;

set_id("repair");
set_alias("string");
set_short(GRN+"dna repair string"+NORM);
set_long(
  "This is a repair mechanism used to repair frame-shifted dna strings.  It\n"+
  "is also bartered for large sums of money to anyone who makes elixirs.  To\n"+
  "use just 'repair dna'.\n");

set_weight(1);
set_value(1300 + random(100));
}

query_save_flag() { return 1; }
clean_up() { return 0; }

init() {
  ::init();
  add_action("Barter","barter");
  add_action("Repair","repair");
}

Repair(str) {
if(str != "dna") { write("What?\n"); return 1; }
if(!present("dna",environment(this_object()))) {
  write("You need a DNA-string to do that.\n");
  return 1; }
write("You repair the DNA-string and feel it's healing powers surge through you.\n");
environment(this_object())->heal_self(600);
destruct(present("dna",environment(this_object())));
destruct(this_object());
return 1;
}

Barter(str) {
int money;
if(!present("rue",ETP)) return 0;
if(str == "repair" || str == "repair string" || str == "dna repair string") {
money = 3500 + random(800);
write(
  "Madame Rue opens her eyes in shock.  She whispers, 'I haven't gotten a hold\n"+
  "of any of these in ages' and she hands you "+money+" coins.\n");
TP->add_money(money);
destruct(this_object());
return 1; }
}
