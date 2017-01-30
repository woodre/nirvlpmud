#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/armor";

reset(arg) {
   set_name("robe");
   set_alias("robes");
   set_short("Robes of"+HIK+" Death"+NORM);
   set_long("This shouldn't be seen by players.\n");
   
   set_ac(5);
   set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
   set_weight(0);
   set_value(0);
}
