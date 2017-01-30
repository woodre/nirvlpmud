inherit "obj/armor";
#include "/open/ansi.h"

reset(arg){
   ::reset(arg);
   set_short(YEL+"Platinum breastplate"+NORM);
   set_long("A breastplate made of platinum, it has some strange and wonderful incisions on\nit.\n");
   set_ac(5);
   set_weight(3);
   set_value(1500);
   set_alias("plate");
   set_name("breastplate");
   set_type("armor");
}
