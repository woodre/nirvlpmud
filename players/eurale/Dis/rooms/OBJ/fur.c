inherit "obj/treasure";
#include "/open/ansi.h"
#define ETP environment(this_player())
reset(arg) {
  if(arg) return;

set_id("wolf fur");
set_alias("fur");
set_short(BOLD+"black wolf fur"+NORM);
set_long(
	"This beautiful, thick wolf fur was taken from the Big Bad Wolf \n"+
	"of 3 little pig fame.  You might want to barter this.\n");

set_weight(4);
set_value(4500);
set_save_flag();
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int nm;
if(!str) { write("What?\n"); return 1; }
if(present("rue",ETP)) { write(
  "Rue smiles and shakes her head saying, 'Not something I want.'\n"); return 1; }
if(!present("sedjak",ETP)) { write("What?\n"); return 1; }
if(str == "fur" || str == "wolf fur") {
  nm = 4000 + random(1200);
  write("Sedjak takes the beautiful pelt, rubs it against his face and whispers\n"+
        "to you, 'thank ye, I'll take it' and hands you "+nm+" coins.\n");
  this_player()->add_money(nm);
  destruct(this_object());
  return 1; }
}
