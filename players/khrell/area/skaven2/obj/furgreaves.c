#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/armor";

reset(arg) {
   set_name("furgreaves");
   set_alias("armor");
   set_short("A piece of armor");
   set_long(
      "This is the long description\n");
   
   set_ac(2);
   set_type("pants");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(1);
   set_value(2000);
}
