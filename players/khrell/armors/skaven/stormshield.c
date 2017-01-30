#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/armor";

reset(arg) {
   set_name("greatshield");
   set_short(HIK+"Stormvermin Greatshield"+NORM);
   set_long(
"   This is the standard greatshield used by the elite stormvermin.\n"+
"Thick planks of enchanted wood are banded together by a lightweight\n"+
"dark metal.\n");
   set_ac(2);
   set_type("shield");
   set_weight(2);
   set_value(2000);
}
