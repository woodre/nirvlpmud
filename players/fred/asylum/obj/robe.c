inherit "/obj/armor";
#include <ansi.h>

reset(arg) {
  if(arg) return;
  set_name("robe");          
  set_short("A "+CYN+"Blue Robe"+NORM);
  set_long(
  "  A long blue robe that almost hangs down to the floor.\n"+
  "It wraps around most of the body and ties in the back.\n");
  set_type("armor");
  set_ac(3);
  set_weight(2);
  set_value(2300);
}
