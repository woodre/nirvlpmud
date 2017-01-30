inherit "/obj/armor";
#include <ansi.h>

reset(arg) {
  if(arg) return;
  set_name("boots");          
  set_short("Big "+BOLD+BLK+"Black"+NORM+" Work Boots");
  set_long(
  "  A pair of thick black work boots.\n");
  set_type("boots");
  set_ac(1);
  set_weight(2);
  set_value(1100);
}
