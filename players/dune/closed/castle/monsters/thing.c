inherit "obj/monster";
#include "definitions.h"


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("Thing");
   set_short("The Thing");
   set_alias("thing");
   set_level(9);
   set_race("thing");
   set_hp(139);
   set_wc(13);
   set_ac(8);
   set_aggressive(1);
   set_long(
"     You look upon a mass of slime and tentacles. An oval-shaped mouth\n"+
"appears from its dark green every now and then. Then entire creature\n"+
"seems formless, it looks like a blob of green flesh. Water spurts from\n"+
"holes in its sides as it moves. The origins of this beast is unknown.\n");
}
