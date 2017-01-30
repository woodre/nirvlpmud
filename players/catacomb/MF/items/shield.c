#include "/players/catacomb/misc/ansi.h"
inherit "/obj/armor";

reset(arg) 
{
  if(arg) return;
  set_name("shield");
  set_short("A well used shield");
  set_long(
   "  A worn out but still effective shield.\n");
  set_type("shield");
  set_ac(1);
  set_weight(1);
  set_value(1000);
}
