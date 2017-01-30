#include "/players/mizan/esc.h"
#include "definitions.h"

/*
 * BABOON
 *
 * This form is meant to be a good team form. It starts off a bit puny, and relatively
 * cheap in cost as well. However when other polys join in with the same form, each one
 * sees their hitting potential rise until they reach the point of being near Tetrapod,
 * for a much cheaper cost.
 *
 */

inherit "/players/mizan/closed/poly/mob.c";

#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

string baboon_write;
string baboon_say;

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A dark olive sphere");
   set_long_desc("You look into the sphere and see the hairy face of a baboon!\n"+
      "The sphere your current polymorph as a baboon.\n"+
      "Type 'class' to see your new abilities.\n");
      
   set_helpfile("baboon");
   set_multilimbed(1);
   set_deathtime(3200);
   set_block_say();
   set_is_team_bonused();
   
   if(!baboon_write)
      baboon_write = ({
         "You are emboldened by the presence of other baboons!\n",
      });
} 

init() 
{
   add_action("baboon_feces","feces");
   ::init();
}

extra_look() 
{
   if(ENV) return (ENV->query_name()) + " is a furry olive baboon, and unable to\n"+
      "communicate to you with typical conversational abilities";
}

teambonus_beat()
{
   object attacker;
   int tmp, i;
   
   if(ENV)
   {
      i = 0;
      attacker = ENV->query_attack();

      /*Put in ghost check due to double deaths -Snow 4/99 */
      if(attacker && !ENV->query_ghost())
      {

         for(i = 0; i < teambonus_present; i ++)
         {
            tmp = damage_level_filter(ENV->query_wc()) * 2;
            if(tmp > COMBAT_DAMAGE_CAP) tmp = COMBAT_DAMAGE_CAP;
            MASTER_R->extra_hit(tmp, i, attacker, ENV);
         } /* end for i */
      } /* end of if attacker */
   }

   ::teambonus_beat();
}

fake_beat() 
{

   ::fake_beat();
}

baboon_feces(arg) { return MASTER_R->baboon_feces(arg); }

