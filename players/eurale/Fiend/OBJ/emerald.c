#define tp this_player()
#define ETP environment(this_player())
#include "/open/ansi.h"
inherit "obj/treasure";
reset(arg) {
  if(arg) return;

set_id("emerald");
set_alias("gem");
set_short(GRN+"sparkling "+HIG+"*"+NORM+GRN+" emerald"+NORM);
set_long(
  "This beautiful green stone is a valuable gem to many.  All one\n"+
  "has to do is 'barter' it to receive its value.\n");

set_weight(1);
set_value(1510);
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int num;
if(!present("sedjak",ETP)) return 0;
if(str == "emerald" || str == "gem") {
  num = 4800 + random(250);
  write("You hand the beautiful emerald to Sedjak.  He looks it over\n"+
        "and hands you "+num+" coins for your trouble.\n");
  tp->add_money(num);
  destruct(this_object());
  return 1; }
}
