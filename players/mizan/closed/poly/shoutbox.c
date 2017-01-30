inherit "/players/mizan/closed/poly/mob.c";
#include "/players/mizan/esc.h"


#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A billowing purple sphere");
   set_long_desc("You look into the sphere and see a really big mouth\n"+
  "smiling back at you. It can be none other than your own.\n"+
  "The sphere contains the matrix of regeneration for\n"+
  "your current polymorph as a shoutbox.\n"+
  "Type 'class' to see your new abilities.\n");
      
   set_helpfile("notarmor");
   set_deathtime(3200);
   set_block_armor();
} 

init() 
{
   add_action("shoutbox_superblink","superblink");
   add_action("shoutbox_bellow","bellow");
   add_action("shoutbox_holler","holler");
   add_action("shoutbox_shrill","shrill");
   add_action("shoutbox_curse","curse");
   add_action("shoutbox_reverb","reverb");
   add_action("shoutbox_calm","calm");
   ::init();
}

extra_look() 
{
   if(ENV) return (ENV->query_name()) + " appears to be incredibly loud and boisterous\n";
}

shoutbox_curse(str) { return MASTER_R->shoutbox_curse(str); }
shoutbox_reverb(str) { return MASTER_R->shoutbox_reverb(str); }
shoutbox_superblink(str) { return MASTER_R->shoutbox_superblink(str); }
shoutbox_holler(str) { return MASTER_R->shoutbox_holler(str); }
shoutbox_bellow(str) { return MASTER_R->shoutbox_bellow(str); }
shoutbox_shrill(str) { return MASTER_R->shoutbox_shrill(str); }
shoutbox_calm() { return MASTER_R->shoutbox_calm(); }

