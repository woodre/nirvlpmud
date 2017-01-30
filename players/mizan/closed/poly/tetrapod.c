inherit "/players/mizan/closed/poly/mob.c";
#include "/players/mizan/esc.h"
#include "definitions.h"


#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

/*
 * TETRAPOD
 *
 * This is a medium strength, rather hard hitting form that allows each limb
 * to connect every combat round. Duration therefore is relatively light.
 * Once the top level form, it has reshaped and has been slightly detuned to be
 * the workhorse manual beatdown form, with extremely limited magic abilities.
 */


/* Changed DEATHTIME from 4600 to 1200 (1.3 hours to 20 mins) due to low cost of guild
 * in terms of exp and sp / damage done. -Snow 6/99  
 */

/* changed 1200 to 3000 (20 min to 50 min) because of increase in cost of guild levels
 * and attributes - Mythos <10-15-1999> 
 */

/* Changed back to 1800 after fixing extra hit attacks
 * 27 AUG 2001 - miz 
 */

/*
 * Serious changes as to how tetrapod does damage.
 * It is weak until a player is L15. Also the extra limb stuff has been daemonized.
 * The improvements made over time by other wizzes has been invaluable in strengthening
 * the code. A shout out to all the homiez who had to wade through my spaghetti-ass shit!
 */

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A bright orange sphere");
   set_long_desc("You look into the sphere and see a fearsome multilimbed creature.\n"+
      "It contains the matrix of regeneration for\n"+
      "your current polymorph as a tetrapod.\n"+
      "Type 'class' to see your new abilities.\n");
      
   set_helpfile("tetrapod");
   set_multilimbed(3);
   set_deathtime(1800);
   set_block_wimpy();
   set_block_magic();
} 

init()
{
   add_action("tetrapod_raar","raar");
   add_action("tetrapod_blitz","blitz");
   ::init();
}

extra_look() 
{
   if(ENV) return (ENV->query_name()) + 
       " has four arms and looks really damn fearsome!"+
       "\n"+
       (ENV->query_name()) + " is constantly looking for someone to pound on";
}

random_emote()
{
   if(1 == random(40)) 
   {
       tell_object(ENV, "You growl and search for someone to beat on.\n");
       ENV->remote_say((ENV->query_name()) + " growls and searches for someone's skull to break open.\n");
   }

   if(1 == random(40)) 
   {
      tell_object(ENV, "You chomp on some dirt.\n");
      ENV->remote_say((ENV->query_name()) + " chomps on some dirt.\n");
   }
}

/* this has been redone to fit the new damage system */
fake_beat() 
{
   object attacker;
   int i, total_damage;
   int tmp;

   /* Total damage should not exceed 50 per round. */
   if(ENV)
   {
      attacker = ENV->query_attack();
      if(!attacker) random_emote();

      /*Put in ghost check due to double deaths -Snow 4/99 */
      if(attacker && !ENV->query_ghost())
      {

         /* Our bonus strike */
         MASTER_R->multilimb_synchronized_attack(
                ENV,         /* ourselves */
                attacker,    /* our attacker */
                23,          /* The chance of this attack hitting, in this case 1 / x of the time */
                ESC + "[1m" + ESC + "[31m" + "You go BERSERK!\n",
                ESC + "[1m" + ESC + "[31m" + (ENV->query_name()) + " goes BERSERK!\n",
                -2,           /* The WC divisor applied to our strapped weapons, where = to 1 / x */
                5,           /* The chance our WC gets gutted for no reason, where = to 1 every x rounds */
                2,           /* The divisor we get gutted, where damage = to damage / x hitpoints */
                3800000,     /* The divisor our our weapon breakage. Can be tweaked to break sooner */
                COMBAT_DAMAGE_CAP + 5);  /* The max cumulative damage per round that can be done */

         MASTER_R->multilimb_synchronized_attack(
                ENV,         /* ourselves */
                attacker,    /* our attacker */
                1,           /* The chance of this attack hitting, in this case 1 / x of the time */
                0,
                0,
                1,           /* The WC divisor applied to our strapped weapons, where = to 1 / x */
                2,           /* The chance our WC gets gutted for no reason, where = to 1 every x rounds */
                2,           /* The divisor we get gutted, where damage = to damage / x hitpoints */
                4700000,     /* The divisor our our weapon breakage. Can be tweaked to break sooner */
                COMBAT_DAMAGE_CAP);  /* The max cumulative damage per round that can be done */
             
      }
   }

   ::fake_beat();
}

tetrapod_blitz() { return MASTER_R->tetrapod_blitz(); }
tetrapod_raar(str) { return MASTER_R->tetrapod_raar(str); }

