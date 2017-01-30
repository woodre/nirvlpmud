inherit "/obj/armor";
#include <ansi.h>

reset(arg) {
  if(arg) return;
  set_name("gloves");          
  set_short("Heavy-Duty "+BOLD+GRN+"Rubber"+NORM+" Gloves");
  set_long(
  "  Thick green rubber gloves that have a few black\n"+
  "burn marks on them from repeated treatments.\n");
  set_type("ring");
  set_ac(1);
  set_weight(2);
  set_value(1100);
}
