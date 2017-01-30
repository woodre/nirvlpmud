#include <ansi.h>
inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("spider man undies");
   set_alias("undies");
   set_short(HIR+"Spider Man Undies"+NORM);
   set_long("\
These underwear are made of a high quality cotton. They have\n\
spider man all over them. The tag reads XL.\n"
   );
   set_ac(1);
   set_type("underwear");
   set_weight(1);
   set_value(300);
}