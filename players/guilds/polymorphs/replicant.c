inherit "/players/mizan/closed/poly/mob.c";
#include "/players/mizan/esc.h"


#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A glowing crystal sphere");
   set_long_desc("You look into the sphere and see your own reflection.\n"+
     "It contains the matrix of regeneration for\n"+
     "your current polymorph as a replicant.\n"+
     "Type 'class' to see your new abilities.\n");
      
   set_helpfile("replicant");
   set_deathtime(6600);
} 

extra_look() 
{
  if(ENV) return (ENV->query_name()) + " is bathed in an aura of fearlessness and is seething with confidence";
}
