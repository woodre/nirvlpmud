/*  Changed to barterable item 8/17/02 - Eurale  */

#define ETP environment(this_player())
#include "/open/ansi.h"
inherit "obj/treasure";

reset(arg) {
  if(arg) return;

set_id("horn");
set_alias("triceratops horn");
set_short(HIW+"triceratops horn"+NORM);
set_long(
  "This horn from the mighty triceratops is often ground up and used in\n"+
  "potions of many kinds.  It is a valuable item to barter with.\n");

set_weight(4);
set_value(1000);
set_save_flag();
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int nm;
if(!str) { write("Barter what?\n"); return 1; }
if(str == "horn" || str == "triceratops horn") {
if(!present("sedjak",ETP)) { write("What?\n"); return 1; }
  nm = 4800 + random(300);
  write("Sedjack rubs his hands together in anticipation.  He whispers,\n"+
  "'I've been waiting a long time for one of these.  I will put it to\n"+
  "good use in my potions' and he gives you "+nm+" coins for it.\n");
  this_player()->add_money(nm);
  destruct(this_object());
  return 1;}
}
