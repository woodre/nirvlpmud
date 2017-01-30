inherit "/players/mizan/closed/poly/mob.c";
#include "/players/mizan/esc.h"
#include "definitions.h"


#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

id(str) { return str == "dark_sight_object" || str == "sphere" || str == MORPH_ID; }

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A fuzzy green sphere");
   set_long_desc("You look into the sphere and see a strange, nocturnal creature\n"+
  "of the fungal elements.\n"+
  "The sphere contains the matrix of regeneration for\n"+
  "your current polymorph as a fungoid.\n"+
  "Type 'class' to see your new abilities.\n");
      
   set_helpfile("fungoid");
   set_deathtime(9000);
   
} 

init() 
{
   add_action("fungoid_gribble","gribble");
   add_action("fungoid_puff","puff");
   add_action("fungoid_spog","spog");
   add_action("fungoid_spore","spore");
   ::init();
}

extra_look() 
{
  if(ENV) return (ENV->query_name()) + " looks like an overgrown mushroom-like thing";
}

fungoid_gribble(arg) { return MASTER_R->fungoid_gribble(arg); }
fungoid_puff(arg) { return MASTER_R->fungoid_puff(arg); }
fungoid_spog(arg) { return MASTER_R->fungoid_spog(arg); }
fungoid_spore(arg) { return MASTER_R->fungoid_spore(arg); }


