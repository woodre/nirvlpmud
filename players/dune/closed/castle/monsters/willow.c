inherit "obj/monster";
#include "definitions.h"


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("willow");
   set_short("A large willow tree");
   set_alias("willow");
   set_level(10);
   set_race("tree");
   set_hp(180);
   set_wc(10);
   set_ac(10);
   set_long(
"        You peer at the willow tree. Its numerous long tentacle-like\n"+
"vines droop down and touch the swamp floor. The limbs of the tree\n"+
"seem strong and muscular.\n");
}
