inherit "/players/mizan/closed/poly/mob.c";
#include "/players/mizan/esc.h"


#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A spotted green sphere");
   set_long_desc("You look into the sphere and see the reflection\n"+
  "of a spotted tropical pufferfish. How goofy looking they are!\n"+
  "Well, right now you are morphed as one, and this sphere\n"+
  "contains your matrix of regneration for it,\n"+
  "Type 'class' to see your new abilities.\n");
      
   set_helpfile("pufferfish");
   set_multilimbed(1);
   set_deathtime(6600);
   set_block_wield();
   set_block_armor();
} 

extra_look() 
{
   if(ENV) return (ENV->query_name()) + " is a giant spotted puffer fish!";
}
