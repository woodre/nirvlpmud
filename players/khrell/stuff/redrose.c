#include <ansi.h>
inherit "obj/treasure";
reset(arg) {
  if (arg) return;
  set_id("rose");
  set_alias("red rose");
  set_short(RED+"@"+NORM+GRN+">}---'---,----"+NORM);
  set_long(
  "A perfect long stemmed red rose.\n"+
  "Just looking at it fills you with a warmth.\n");
  set_weight(0);
  set_value(0);
}
