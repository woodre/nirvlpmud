#include <ansi.h>;
inherit "/obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
set_name("pass");
set_short("A pass");
  set_long(
"A simple 0.7 mm lead mechanical pencil.\n");
set_type("knife");
set_class(9);
set_weight(1);
set_value(100);
}
query_pass() { return 1; }

