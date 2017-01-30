#include "/open/ansi.h"
inherit"obj/armor";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("talisman");
set_short(HIG+"Emerald Talisman"+NORM);
set_long(
  "A sparkling emerald talisman that glows with an inner light.\n");
set_weight(1);
set_value(300);
set_arm_light(1);
set_ac(2);
set_type("necklace");
}

query_save_flag() { return 1; }
