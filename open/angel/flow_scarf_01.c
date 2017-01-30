#include <ansi.h>
inherit "obj/armor";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("flowing scarf");
   set_alias("scarf");
   set_short(HIR+"A Flowing Scarf"+NORM);
   set_long(
      "This scarf is made from superman's cape. It is bright red and\n"+
      "flow in the wind.\n"
   );
   set_ac(2);
   set_type("misc");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(2);
   set_value(1000);
}

