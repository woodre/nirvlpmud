inherit "/players/mizan/closed/poly/mob.c";
#include "/players/mizan/esc.h"


#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("An ebony black sphere");
      set_long_desc("You look into the sphere and see the reflection\n"+
     "of cold, hardened DEATH. Empty sockets where your eyes once.\n"+
     "were, and a shallow gap where your lips had once been take you\n"+
     "aback... You cannot stand the sight of this horrid, wretched, and\n"+
     "misbegotten creature with dripping and crumbling flesh...\n"+
     "...yet you are intrigued and fascinated by the sight of it.\n"+
     "This sphere contains your matrix of regneration for a necromonger.\n"+
     "Type 'class' to see your new abilities.\n");
      
   set_helpfile("necromonger");
} 

init() 
{
   add_action("necromonger_cold","cold");
   add_action("necromonger_animate","animate");
   add_action("necromonger_jerky","jerky");
   add_action("necromonger_cloudkill","cloudkill");
   ::init();
}

extra_look() 
{
   if(ENV) return (ENV->query_name()) + " appears to be heavily caffienated";
}

necromonger_cold(str) { return MASTER_R->necromonger_cold(str); }
necromonger_animate(str) { return MASTER_R->necromonger_animate(str); }
necromonger_jerky(str) { return MASTER_R->necromonger_jerky(str); }
necromonger_cloudkill(str) { return MASTER_R->necromonger_cloudkill(str); }


