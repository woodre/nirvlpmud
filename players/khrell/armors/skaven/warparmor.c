#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/armor";

reset(arg) {
   set_name("warparmor");
   set_alias("armor");
   set_short(GRN+"Warpstone"+HIK+" Armor"+NORM);
   set_long(
      "Warpstone armor contains powdered warpstone that is\n"+
      "mixed in with the metal during its forging process.\n");
   set_ac(4);
   set_type("armor");
   set_weight(2);
   set_res(10);
   set_value(12000);
}
