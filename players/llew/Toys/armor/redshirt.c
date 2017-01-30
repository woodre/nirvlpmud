#include "/players/llew/closed/ansi.h"

inherit "obj/armor";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_id("shirt");
   set_name(RED+"Red Shirt"+NORM);
   set_short(RED+"Red Shirt"+NORM);
   set_value(300);
   set_weight(2);
   set_ac(2);
   set_alias("red shirt");
   set_long("The bright red shirt of Winnie the Pooh is made of soft\n"+
            "cotton and offers some protection from attacks.\n");
   set_type("armor");
}

id(str) { return ::id(str) || str == "shirt"; }

