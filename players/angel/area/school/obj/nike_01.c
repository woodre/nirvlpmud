#include <ansi.h>
inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("nike tennis shoes");
  set_alias("shoes");
  set_short("Nike shoes");
  set_long("\
These are a very nice pair of nike. They are black and\n\
grey with spring action. They cost 200 dollars.\n");
  set_ac(1);
  set_type("boots");
  set_weight(1);
  set_value(200);
}