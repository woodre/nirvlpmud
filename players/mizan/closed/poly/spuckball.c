inherit "/players/mizan/closed/poly/mob.c";
#include "/players/mizan/esc.h"


#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A squishy blue sphere");
   set_long_desc("You look into the sphere and see a happy, faceless, and amorphous mass.\n"+
     "It contains the matrix of regeneration for\n"+
     "your current polymorph as a spuckball.\n"+
     "Type 'class' to see your new abilities.\n");
      
   set_helpfile("spuckball");
   set_deathtime(9800);
   set_weight_limit(54);
} 

extra_look() 
{
  if(ENV) return (ENV->query_name()) + " is a fuzzy, blinking, squishy thing";
}

init()
{
   add_action("spuckball_squit","squit");
   ::init();
}

spuckball_squit(str) { return MASTER_R->spuckball_squit(str); }
