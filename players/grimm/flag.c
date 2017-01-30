#include <ansi.h>
inherit "/obj/treasure";
reset(arg) {
  if(arg) return;
  set_short("flag");
  set_alias("flag");
  set_weight(0);
  set_value(0);
}
long() {
  write(WHT + "A " + RED + "F" + GRN + "l" + HIY + "a" + BLU + "g" + NORM "\n");
  return 1;
}
