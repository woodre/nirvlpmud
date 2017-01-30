inherit "/obj/armor";
#include <ansi.h>

reset(arg) {
  if(arg) return;
  set_name("gloves");          
  set_short("Fuzzy gloves");
  set_long(
  "  A nice warm pair of gloves covered with fur.\n");
  set_type("ring");
  set_ac(1);
  set_weight(1);
  set_value(1400);
}
