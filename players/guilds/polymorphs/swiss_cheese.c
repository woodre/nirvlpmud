inherit "/players/mizan/closed/poly/mob.c";

#include "/players/mizan/esc.h"


#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A yellow sphere pockmarked with holes");
   set_long_desc("You look into the sphere and see the reflection\n"+
  "of a giant wheel of Swiss cheese. You look goofy and smell bad.\n"+
  "Well, that's okay. People still love you. You are morphed as a giant\n"+
  "wheel of swiss cheese and this sphere contains your matrix of regneration.\n"+
  "Type 'class' to see your new abilities.\n");
      
   set_helpfile("swiss_cheese");
   set_multilimbed(1);
   set_deathtime(66600);
   set_block_wield();
   set_block_armor();
} 

extra_look() 
{
   if(ENV) return (ENV->query_name()) + " is a giant wheel of swiss cheese.";
}
