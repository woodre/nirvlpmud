#include "/players/mizan/esc.h"

inherit "/players/mizan/closed/poly/mob.c";

#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A fuzzy yellow sphere");
   set_long_desc("You look into the sphere and see a big yellow thing\n"+
  "staring back at you.\n"+
  "It contains the matrix of regeneration for\n"+
  "your current polymorph as a sponge.\n"+
  "Type 'class' to see your new abilities.\n");
      
   set_helpfile("sponge");
   set_deathtime(9800);
   set_block_killcmd();
} 

init() 
{
   add_action("sponge_sponge","sponge");
   add_action("sponge_evaluate","evaluate");
}

extra_look() 
{
   if(ENV) return (ENV->query_name()) + " appears to be a big yellow sponge\n)";
}

sponge_sponge(arg) { return MASTER_R->sponge_sponge(arg); }
sponge_evaluate(arg) { return MASTER_R->sponge_evaluate(arg); }

