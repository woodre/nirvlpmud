inherit "/players/mizan/closed/poly/mob.c";

#include "/players/mizan/esc.h"


#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A muted rainbow sphere");
   set_long_desc("You look into the sphere and see the reflection\n"+
  "of yourself. How goofy looking you are!\n"+
  "This sphere contains your matrix of regneration for a mimic.\n"+
  "Type 'class' to see your new abilities.\n");
      
   set_helpfile("high_mimic");
   set_deathtime(750);
   set_block_magic();
   set_block_armor();
   set_block_weapon();
} 

