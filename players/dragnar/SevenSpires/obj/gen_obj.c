inherit "obj/treasure";
#include <ansi.h>

string ex_look;

void
reset(int arg) {
   if (arg) return;
   set_id("gen_obj");
   set_short("A Generic Obj");
   set_long( "It's generic.\n");
   set_weight(0);
   set_value(0);
}

extra_look() {
  return ex_look;
}
set_extra_look(string str) { ex_look = str; }
query_extra_look() { return ex_look; }
