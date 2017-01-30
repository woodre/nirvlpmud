inherit "obj/monster";
#include "definitions.h"


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("mosquito");
   set_short( "A large nesting mosquito");
   set_alias("mosquito");
   set_level(2);
   set_race("mosquito");
   set_hp(30);
   set_wc(6);
   set_ac(3);
   set_aggressive(1);
   set_long(
"        The 6-inch tall mosquito has a menacing stinger. It may not\n"+
"be deadly itself, but in a large swarm, it would be lethal.\n");
}
