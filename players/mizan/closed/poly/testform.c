inherit "/players/mizan/closed/poly/mob.c";
#include "/players/mizan/esc.h"


#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A rock maple sphere");
   set_long_desc("You look into the sphere and see the reflection\n"+
  "of a large treehouse, with all the happy trimmings of a\n"+
  "proper aerial fort. Even the 'NO GIRLS ALLOWED' sign is here.\n"+
  "This sphere contains your matrix of regneration for a treehouse.\n"+
  "Type 'class' to see your new abilities.\n");
      
   set_helpfile("treehouse");
   set_deathtime(7000);
   set_block_magic();
   set_block_armor();
   set_block_weapon();
} 




