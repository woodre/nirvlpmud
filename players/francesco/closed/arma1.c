#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("ring");
set_short("Francesco's armour (worn)");
set_long(
  "An armor\n");
set_value(0);
set_arm_light(1);  /*  makes armor glow if it's > 0  */
}

get() {return 0;}

drop() {destruct(this_object()); return 1;}
