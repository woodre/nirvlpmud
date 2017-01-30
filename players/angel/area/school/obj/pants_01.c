#include <ansi.h>
inherit "obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("leather pants");
  set_alias("pants");
  set_short(HIR+"Leather pants"+NORM);
  set_long("Slick red leather pants, boot cut\n");
  set_ac(1);
  set_type("pants");  
  set_weight(1);
  set_value(300);
}