#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "obj/armor";

reset(arg) {
   set_name("armor");
   set_alias("armor");
   set_short(RED+"A Shardak"+NORM+HIR+" Helmet"+NORM);
   set_long(
      "This is the long description\n");
   
   set_ac(2);
   set_type("helmet");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(1);
   set_value(0);
}
