#include <ansi.h>
inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("tank top");
  set_alias("top");
  set_short("Red Tank Top");
  set_long("This is a red tank top. It is made of cotton.\n");
  set_ac(1);
  set_type("chest");
  set_weight(1);       
  set_value(300);
}
