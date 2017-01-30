inherit "obj/armor";
#include "/open/ansi.h"

reset(arg){
   ::reset(arg);
   set_short(YEL+"Platinum helmet"+NORM);
   set_long("This is a platinum helmet, it protects your head from beeing smashed.\n");
   set_ac(2);
   set_weight(2);
   set_value(1000);
   set_alias("platinum helmet");
   set_name("helmet");
   set_type("helmet");
}
