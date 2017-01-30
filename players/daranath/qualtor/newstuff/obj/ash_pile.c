/* Average coins of 750 */
#include <ansi.h>

inherit "obj/treasure";
reset(arg) {
  if(arg) return;

set_id("ashen pile");
set_alias("ash");
set_short(BLK+BOLD+"A small pile of ash"+NORM);
set_long("A small pile of ash, left over from a battle.\n");
set_weight(1);
set_value(500+random(500));
}
