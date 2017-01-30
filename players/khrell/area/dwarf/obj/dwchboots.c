#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/armor";

reset(arg) {
   set_name("dwarf chain boots");
   set_alias("boots");
   set_short("Dwarfen Chain Boots");
   set_long(
      "This is the long description\n");
   
   set_ac(1);
   set_type("boots");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(1);
   set_value(800);
}
