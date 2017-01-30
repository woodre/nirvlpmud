inherit "/obj/armor";
#include "/obj/ansi.h"
 
void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("belt");
  set_alias("belt_1");
  set_short(" "+HIY+"Utility belt"+NORM+"");
  set_long("A Yellow utility belt in which batman carries all his bat stuff.\n");

  
  set_params("other|evil",0,15,0);
  set_ac(2);
  set_type("belt");
  set_weight(1);
  set_value(1200);
}