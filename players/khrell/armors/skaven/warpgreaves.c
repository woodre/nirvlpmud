#include "/players/khrell/define.h"
#include <ansi.h>
inherit "obj/armor";

reset(arg) {
   set_name("warparmor");
   set_alias("armor");
   set_short(GRN+"Warpstone"+HIK+" Armor"+NORM);
   set_long(
      "Warpstone armor contains powdered warpstone that is\n"+
      "mixed in with the metal during its forging process.\n"+
      "These greaves look crude, but provide ample protection\n"+
      "for the wearers legs.\n");
   set_ac(2);
   set_type("pants");
   set_weight(2);
   set_res(2);
   set_value(9000);
}
