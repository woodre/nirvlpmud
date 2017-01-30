inherit "obj/monster";
#include "definitions.h"


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("crab");
   set_short( "A giant crab");
   set_alias("crab");
   set_level(5);
   set_race("crab");
   set_hp(70);
   set_wc(8);
   set_ac(6);
   set_aggressive(1);
   set_long(
"     A three foot tall crab stares at you with its steady gaze. Its\n"+
"large pincers are raised in the air for defense. The rest of its body\n"+
"is mainly red in color, with some orange splotches.\n");
}
