#define ETP environment(this_player())
#include "/players/eurale/closed/ansi.h"
inherit "obj/treasure.c";

reset(arg){
  if (arg) return;

set_id("china cup");
set_alias("cup");
set_short("A delicate china cup");
set_long(
  "This delicate china cup came from a matched set.  It is hand\n"+
  "painted and very rare.  It surely would have a high barter value.\n");
set_weight(1);
set_value(1250);
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int num;
if(!present("sedjak",ETP)) return 0;
if(str == "cup" || str == "china cup") {
  num = 1900 + random(150);
  write("Sedjak looks the cup over and hands you "+num+" coins for it.\n");
  this_player()->add_money(num);
  destruct(this_object());
  return 1; }
}
