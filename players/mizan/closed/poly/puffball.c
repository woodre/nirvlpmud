inherit "/players/mizan/closed/poly/mob.c";
#include "/players/mizan/esc.h"


#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A crackling red sphere");
   set_long_desc("You look into the sphere and see the reflection\n"+
     "of a flaming, pulsating, featureless fireball.\n"+
     "It contains the matrix of regeneration for\n"+
     "you see your new abilities.\n");
      
   set_helpfile("puffball");
   set_deathtime(9800);
   set_block_armor();
} 

extra_look() 
{
  if(ENV) return (ENV->query_name()) + " is a fiery, non corporeal being made entirely of energy";
}

init()
{
   add_action("puffball_nova","nova");
   add_action("puffball_vaporize","vaporize");
   add_action("puffball_fry","fry");
   add_action("puffball_gain","gain");
   add_action("puffball_finish","finish");
   ::init();
}

puffball_fry(str) { return MASTER_R->puffball_fry(str); }
puffball_nova(arg) { return MASTER_R->puffball_nova(arg); }
puffball_vaporize(arg) { return MASTER_R->puffball_vaporize(arg); }
puffball_gain(arg) { return MASTER_R->puffball_gain(arg); }
puffball_finish(arg) { return MASTER_R->puffball_finish(arg); }

