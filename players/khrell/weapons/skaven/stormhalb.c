#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/weapon.c";

reset(arg) {
   ::reset(arg);
   if (arg) return;
   
   set_name("halberd");
   set_type("polearm");
   set_short(HIK+"Stormvermin Halberd"+NORM);
   set_long(
"   This wicked halberd is the standard armament for the elite ranks\n"+
"of the Stormvermin.\n");
   set_class(16);
   set_weight(3);
   set_value(1200);
   set_hit_func(this_object());
}
