inherit "/obj/armor";
#include <ansi.h>

reset(arg) {
  if(arg) return;
  set_name("jacket");
  set_alias("flack jacket");          
  set_short(BOLD+BLK+"Flack Jacket"+NORM);
  set_long(
  "  A light weight jacket composed of tightly wound fibers\n"+
  "that provide excellent protection against various types\n"+
  "of weapons.\n");
  set_type("armor");
  set_ac(4);
  set_weight(2);
  set_value(2100);
}
