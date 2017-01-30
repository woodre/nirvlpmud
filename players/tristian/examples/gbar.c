#include "/players/ireland/ansi.h"
inherit "obj/treasure.c";

reset(arg) {
   if(arg) return;
   
   set_id("bar");
   set_alias("gold");
   set_short("A "+HIY+"gold "+NORM+"bar");
   set_long(
      "This is a bar of pure gold.  It should be worth some money.\n"
   );
   set_value(2000);
   set_weight(4);
}
