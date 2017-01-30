#include "/players/mizan/esc.h"

inherit "/players/mizan/closed/poly/mob.c";

#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A wooden textured sphere");
   set_long_desc("You look into the sphere and see the reflection\n"+
  "of a large, mobile siege catapult. Frock!\n"+
  "You get the urge to rain all sorts of stuff on your\n"+
  "friends, and enemies (which are your SPECIAL friends).\n"+
  "Not bad. This sphere contains your matrix of regneratin\n"+
  "your current form as an Acme [tm] siege catapult.\n"+
  "Type 'class' to see your new abilities.\n");
      
   set_helpfile("catapult");
   set_deathtime(3600);
   set_block_armor();
   set_block_wield();
   set_block_magic();
} 
