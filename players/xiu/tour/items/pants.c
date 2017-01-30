inherit "obj/armor";
#include "/players/fred/ansi.h";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
set_name("pants");
set_alias("patchwork");
set_short("Patchwork pants");
set_long("A pair of pants made of velvet patches.");
set_type("pants");
  set_ac(1);
  set_weight(1);
  set_value(50);
}
