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
   
   set_short_desc("A pudgy brown sphere");
   set_long_desc("You look into the sphere and see the fat, pudgy face of Loafy the dog.\n"+
      "The sphere contains the matrix of regeneration for your current polymorph as loafy.\n"+
      "Type 'class' to see your new abilities.\n");
      
   set_helpfile("loafy");
   set_deathtime(3000);
   set_block_wield();
   set_block_armor();
   set_block_magic();

   if(ENV) command("follow", ENV);
} 

extra_long() 
{
   if(ENV) return (ENV->query_name()) + " is a fat, brown dog";
}

