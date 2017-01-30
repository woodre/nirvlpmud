#include "/players/tristian/lib/goblin_define.h"
inherit "obj/treasure.c";

reset(arg) {
   if(arg) return;
   
   set_id("Wolf Pelt");
   set_alias("pelt");
   set_short("A dingy "+HIM+"wolf pelt"+NORM);
   set_long(
      "This is the pelt from the wolf riders mount.\n"+
      "It should be worth a few coins to almost any merchant.\n"
   );
   set_value(100);
   set_weight(1);
}
