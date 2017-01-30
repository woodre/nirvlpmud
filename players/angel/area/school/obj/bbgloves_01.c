#include <ansi.h>
inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("baseball glove");
   set_alias("gloves");
   set_short("Baseball Glove");
   set_long("\
This is a left handed baseball glove. It is well worn.\n"
   );
   set_ac(1);
   set_type("gloves");  
   set_weight(1);
   set_value(300);
}