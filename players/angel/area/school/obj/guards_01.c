#include <ansi.h>
inherit "obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("shin guards ");
  set_alias("guards");
  set_short("Shin Guards");
  set_long("\
The shin guards are protective wear while playing softball.\n"
  );
  set_ac(1);
  set_type("misc");  
  set_weight(1);
  set_value(300);
}