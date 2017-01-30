#include "/players/dusan/ansi.h"
inherit "obj/treasure";

reset(arg) {
if(arg) return;
set_id("hide");
set_alias("vhide");
set_short(""+BOLD+""+BLK+"Vraaak hide"+NORM+"");
set_long(
  "A supple vraaak hide taken from a vraaak hatchling.\n");
set_weight(1);
set_value(400);
}
