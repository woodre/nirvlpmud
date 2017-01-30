#include "/players/mythos/closed/ansi.h"

inherit "obj/treasure";
reset(arg) {
  if(arg) return;
    set_id("taormin");
    set_alias("jewel");
    set_short(RED+"TAORMIN"+NORM);
    set_long("The Taormin.\n"+
    "A jewel of great power and beauty.\n"+
    "Horlach searched far and wide for this...\n");
    set_weight(5);
    set_value(1000000);
}
