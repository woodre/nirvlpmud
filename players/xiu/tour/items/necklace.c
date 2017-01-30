inherit "obj/armor";
#include <ansi.h>

reset(arg)
{
  ::reset(arg);
  if(arg) return;
set_name("necklace");
set_alias("beads");
set_short("A "+RED+"beaded"+BOLD+GRN+" hemp"+NORM+" necklace");
set_long("A necklace with beads that glow with a strange, almost spirital aura.\n");
set_type("necklace");
set_ac(2);
  set_weight(1);
  set_value(50);
}
