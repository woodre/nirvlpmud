inherit "/players/mizan/closed/poly/mob.c";
#include "/players/mizan/esc.h"


#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A blippy red sphere");
   set_long_desc("You look into the sphere and see a biggly grinning face.\n"+
  "It contains the matrix of regeneration for\n"+
  "your current polymorph as a bogglemancer.\n"+
  "Type 'class' to see your new abilities.\n");
      
   set_helpfile("bogglemancer");
} 

init() 
{
   add_action("bog_tree","tree");
   add_action("bog_zokwave","zokwave");
   add_action("bog_speedball","speedball");
   add_action("bog_charbroil","charbroil");
   add_action("bog_lint","lint");
   add_action("bog_sandbag","sandbag");
   add_action("bog_piano","piano");
   add_action("bog_anvil","anvil");
   ::init();
}

extra_look() 
{
   if(ENV) return (ENV->query_name()) + " appears to be heavily caffienated";
}

bog_tree(str) { return MASTER_R->bogglemancer_tree(str); }
bog_zokwave(str) { return MASTER_R->bogglemancer_zokwave(str); }
bog_speedball(str) { return MASTER_R->bogglemancer_speedball(str); }
bog_charbroil(str) { return MASTER_R->bogglemancer_charbroil(str); }
bog_lint(str) { return MASTER_R->bogglemancer_lint(str); }
bog_sandbag(str) { return MASTER_R->bogglemancer_sandbag(str); }
bog_piano(str) { return MASTER_R->bogglemancer_piano(str); }
bog_anvil(str) { return MASTER_R->bogglemancer_anvil(str); }


