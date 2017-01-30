inherit "/players/mizan/closed/poly/mob.c";
#include "/players/mizan/esc.h"


#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

string fruitname;
int fruit_count;
object room;

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A spotted black and white sphere");
   set_long_desc("You look into the sphere and the face of a COW staring back at you.\n"+
      "The sphere contains the matrix of regeneration for\n"+
      "your current polymorph as a cow.\n"+
      "Type 'class' to see your new abilities.\n");
      
   set_helpfile("cow");
   set_deathtime(3000);
   set_block_wield();
   set_block_armor();
   set_block_magic();

   if(ENV) command("follow", ENV);
} 

extra_long() 
{
   if(ENV) return (ENV->query_name()) + " is a cow. Perhaps you can 'milk " + ENV->query_objective()  +"'";
}

