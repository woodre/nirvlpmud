#include <ansi.h>
inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("cotton sweater");
  set_alias("sweater");
  set_short("Cotton sweater");
  set_long("This a basic cotton sweater. It keeps you warm in the cold.\n");
  set_ac(1);
  set_type("chest");
  set_weight(1);       
  set_value(300);
}
