inherit "/players/mizan/closed/poly/mob.c";
#include "/players/mizan/esc.h"


#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A LARGE squishy blue sphere");
   set_long_desc("You look into the sphere and see a happy, faceless, and amorphous mass.\n"+
      "The sphere contains the matrix of regeneration for\n"+
      "your current polymorph as a Spucktrooper. Roor!\n"+
      "There is a happy feeling as you assume the shape anf form\n"+
      "of some of the most stalwart and loyal denziens of the Jello.\n"+
      "Type 'class' to see your new abilities.\n");
      
   set_helpfile("spucktrooper");
   set_deathtime(4800);
   set_weight_limit(120);
} 

extra_look() 
{
  if(ENV) return (ENV->query_name()) + " is a large, fuzzy, blinking, squishy thing";
}


init()
{
   add_action("spucktrooper_squit","squit");
   add_action("spucktrooper_hwarf","hwarf");
   add_action("spucktrooper_bletch","bletch");
   ::init();
}

spucktrooper_squit(str) { return MASTER_R->spucktrooper_squit(str); }
spucktrooper_hwarf(str) { return MASTER_R->spucktrooper_hwarf(str); }
spucktrooper_bletch(str) { return MASTER_R->spucktrooper_bletch(str); }

