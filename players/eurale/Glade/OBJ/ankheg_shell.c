#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";
#define tp this_player()

reset(arg) {
set_name("ankheg shell");
set_alias("shell");
set_short(HIY+"Chitinous shell"+NORM);
set_long(
  "The smooth, yellow chitinous shell of Ankheg.\n");

set_ac(3);
set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(2);
set_value(1090);
set_arm_light(0);
}
