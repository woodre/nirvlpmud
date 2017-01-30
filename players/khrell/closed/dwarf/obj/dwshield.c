#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/armor";

reset(arg) {
   set_name("Dwarfen shield");
   set_alias("shield");
   set_short("Dwarfen shield");
   set_long(
      "This is the long description\n");
   
   set_ac(1);
   set_type("shield");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(2);
   set_value(500);
}
