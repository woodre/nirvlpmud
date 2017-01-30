#include <ansi.h>
inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("levi blue jeans");
  set_alias("jeans");
  set_short("Blue Jeans");
  set_long("\
These blue jeans are snug tight. They make everyone take a\n\
second look.\n");
  set_ac(1);
  set_type("pants");
  set_weight(1);       
  set_value(300);
}
