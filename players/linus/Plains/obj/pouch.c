inherit "/obj/treasure.c";
#include "/players/linus/def.h"

int mon;

 id(str) { return str == "pouch" || str == "bag" || str == "money pouch" || str == "money bag "; }
reset(arg) {
  if(arg) return;
  set_short("A money pouch");
 set_long(
 "A small leather pouch used for holding money.  Perhaps you could\n"+
 "'open' it to see if there is any money in it.\n");
  set_weight(2);
  set_value(500);
}
 init() {
  ::init();
add_action("open_pouch","open");
mon = (1000+random(2001));
}
open_pouch(string str) {
 if(!str) { write("Open what?\n"); return 1; }
  if(str=="pouch") {
  write("You open the pouch and pull out "+mon+" coins.\n");
  TP->add_money(mon);
 TP->add_weight(-2);
 destruct(this_object());
return 1;
}
}
