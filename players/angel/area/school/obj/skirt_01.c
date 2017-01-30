#include <ansi.h>
inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("pleated skirt");
  set_alias("skirt");
  set_short("Pleated Skirt");
  set_long("This is a red pleated skirt with fringes along the bottom.\n");
  set_ac(1);
  set_type("pants");
  set_weight(1);
  set_value(300);
}