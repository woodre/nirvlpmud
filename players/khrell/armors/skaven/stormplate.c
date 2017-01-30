#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/armor";

reset(arg) {
   set_name("platemail");
   set_short(HIK+"Stormvermin Platemail"+NORM);
   set_long(
"   This is the standard body armor of the stormvermin.  Large\n"+
"interlocking plates rivited together provides one with alot of\n"+
"protection against incomming blows.\n");
   set_ac(4);
   set_type("armor");
   set_weight(3);
   set_value(2000);
}
