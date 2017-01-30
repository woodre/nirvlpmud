inherit "/obj/treasure.c";
#include "../../defs.h"

reset(arg){
  if(arg) return;
  set_id("salt");
  set_short("A small vial of "+BOLD+"salt"+OFF);
  set_alias("vial");
  set_long("A small vial of salt.\n");
  set_weight(1);
  set_value(10);
}
