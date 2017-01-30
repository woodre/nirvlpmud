#include <ansi.h>
inherit "obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("school team shirt");
  set_alias("shirt");
  set_short(HIR+"Team Shirt"+NORM);
  set_long("\
This is a red and white school team shirt. It has a\n\
Indian head on the front.\n"
  );
  set_ac(1);
  set_type("chest");  
  set_weight(1);
  set_value(300);
}