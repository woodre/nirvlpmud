inherit "/players/mizan/closed/poly/mob.c";
#include "/players/mizan/esc.h"
#include "definitions.h"


#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"
#define PHB_R "/players/mizan/closed/poly/phbDM.c"

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("An argyle and navy blue sphere");
   set_long_desc("You look into the sphere and see the reflection\n"+
  "of something so distinctively horrifying and disgusting that\n"+
  "you nearly vomit on your shoes. You are a 'Pointy Haired Boss',\n"+
  "one of the most fearsome and despised creatures of any multiverse..\n"+
  "This sphere contains your matrix of regneration for a pointy haired boss.\n"+
  "Type 'class' to see your new abilities.\n");

   set_deathtime(3000);      
   set_helpfile("phb");
   set_block_weapon();
} 

init() 
{
   add_action("phb_prev","prev");
   add_action("phb_micr","micr");
   add_action("phb_dele","dele");
   add_action("phb_pepr","pepr");
   add_action("phb_buzz","buzz");
   add_action("phb_confcall","confcall");
   add_action("phb_motivate","motivate");
   add_action("phb_mission","mission");
   add_action("phb_bs","bs");
   ::init();
}

extra_look() 
{
   if(ENV) return (ENV->query_name()) + " appears to wearing a cheap suit and a tie";
}

random_emote()
{
   string random_bs;
   
   if(1 == random(100)) 
   {
      tell_object(ENV, "You adjust your pants.\n");
      ENV->remote_say((ENV->query_name()) + " adjusts " + ENV->query_possessive() + " pants.\n");
   } 
   else if(1 == random(100)) 
   {
      random_bs = PHB_R->get_bullshit();

      tell_object(ENV, "You exclaim: We strive to " + random_bs + ".\n");
      ENV->remote_say((ENV->query_name()) + " exclaims: We strive to " + random_bs + ".\n");
   }
}

phb_prev(str) { return MASTER_R->phb_prev(str); }
phb_micr(str) { return MASTER_R->phb_micr(str); }
phb_dele(str) { return MASTER_R->phb_dele(str); }
phb_pepr(str) { return MASTER_R->phb_pepr(str); }
phb_buzz(str) { return MASTER_R->phb_buzz(str); }
phb_motivate(str) { return MASTER_R->phb_motivate(str); }
phb_confcall(str) { return MASTER_R->phb_confcall(str); }
phb_mission(str) { return MASTER_R->phb_mission(str); }
phb_bs(str) { return MASTER_R->phb_bs(str); }

