/*
 * Green Lantern Ring - cosmetic only
 */

#include <ansi.h>

inherit "obj/armor";

void reset(int arg) {
  ::reset(arg);
  if (arg)
    return;
  set_name("ring");
  set_short(HIG+"Green Lantern"+NORM+" Ring");
  set_long("A custom "+HIG+"Green Lantern"+NORM+" Ring.\n"+
"One would think this would have special powers, but alas, only the true\n"+
"Green Lantern can make heads or tails of how to use it.\n");
  set_ac(0);
  set_type("ring");
  set_weight(1);
  set_value(2);
}
