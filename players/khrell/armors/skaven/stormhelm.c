#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/armor";

reset(arg) {
   set_name("greathelm");
   set_alias("helm");
   set_short(HIK+"Stormvermin Greathelm"+NORM);
   set_long(
"   This is the standard greathelm of the stormvermin.  It\n"+
"covers the entire head for protection and a pair of crafted\n"+
"holes allow the wearer to see out. It is lightweight and made\n"+
"from some type of dark metal.\n");      
   set_ac(2);
   set_type("helmet");
   set_weight(1);
   set_value(2000);
}
