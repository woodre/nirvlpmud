inherit "obj/armor";
#include "/open/ansi.h"

reset(arg){
   ::reset(arg);
   set_short(BOLD+"thick leather boots"+NORM);
   set_long("A pair of thick leather boots, protecting your thighs, knees, heels and feet.\n");
   set_ac(2);
   set_weight(2);
   set_value(1000);
   set_alias("leather boots");
   set_name("boots");
   set_type("boots");
}
