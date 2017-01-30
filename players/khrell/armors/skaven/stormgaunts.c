#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/armor";

reset(arg) {
   set_name("battle-gauntlets");
   set_alias("gauntlets");
   set_short(HIK+"Stormvermin Battle-Gauntlets"+NORM);
   set_long(
"   The standard gauntlets for the Stormvermin.  A light durable\n"+
"leather glove has been fitted with dark metal plates to provide\n"+
"good protection for anyone wearing them.\n"); 
   set_ac(2);
   set_type("gloves");
   set_weight(2);
   set_value(2000);
}
