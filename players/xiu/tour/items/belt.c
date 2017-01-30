inherit "obj/armor";
#include "/players/fred/ansi.h";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
set_name("hemp");
set_alias("belt");
set_short("A"+BOLD+GRN+" hemp"+NORM+" belt");
set_long("Essentially a flimsy long cord of braided hemp. It is quite flimsy.\n");
set_type("belt");
  set_ac(1);
  set_weight(1);
  set_value(50);
}
