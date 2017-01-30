inherit "obj/armor";
#include "/open/ansi.h"
reset(arg){
   ::reset(arg);
   set_name("black cloak");
   set_short(HIK+"A black cloak"+NORM);
   set_alias("cloak");
   set_long("A black full body cloak.\n");
   set_type("cloak");
   set_ac(2);
   set_weight(2);
   set_value(50);
}
