inherit "obj/monster";
#include "definitions.h"


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("rabbit");
   set_short( "A rabbit");
   set_alias("rabbit");
   set_level(3);
   set_race("rabbit");
   set_hp(45);
   set_wc(6);
   set_ac(4);
   set_long(
"     This is a cute fuzzy bunny. Its fur is sandy brown. Bunnies like\n"+
"these inhabit the plains in large numbers. Though you need not worry,\n"+
"it looks very harmless.\n");
}
