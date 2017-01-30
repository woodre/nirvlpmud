#include <ansi.h>
inherit "obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("diamond earrings");
  set_alias("earrings");
  set_short(HIW+"Diamond earrings"+NORM);
  set_long("\
Cubic zirconium earrings, if you don't tell her they're fake\n\
she will never know\n"
  );
  set_ac(1);
  set_type("earring");
  set_weight(2);
  set_value(300);
}