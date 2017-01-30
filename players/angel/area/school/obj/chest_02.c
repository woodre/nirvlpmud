#include <ansi.h>
inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("school team shirt");
   set_alias("shirt");
   set_short("team shirt");
   set_long(
       "A red and white school team shirt.\n"
   );
   set_ac(1);
   set_type("chest");  
   set_weight(1);
   set_value(300);
}