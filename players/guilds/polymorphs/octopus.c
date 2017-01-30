inherit "/players/mizan/closed/poly/mob.c";
#include "/players/mizan/esc.h"
#include "definitions.h"

inherit "/players/mizan/closed/poly/mob.c";

#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

/*
* DAMAGE FORMULAS:
*
* There can be up to 3 extra limbs, for a total of 4 weapon hit attacks.
* The actual hits are called from fake_beat in gob.c
* This is so hit_player is called only once per round.
* 
* Every heartbeat the list of extra limbs is cycled.
* If the limb is unarmed the damage is random(3) PER LIMB.
* If there is a weapon, 1/2 of its WC is used to compute damage = random(1/2 * WC)
* 50% of the time 1/4 of the weapon class is used so damage = random(WC/2)
*
* These are then totaled up and fed to the damage queue.
* In the gob.c, the damage is called, with 40 being a hard cap on damage per round.
* That's it!
*
*/

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A swirly purple sphere");
   set_long_desc("You look into the sphere and see a slap happy octopus.\n"+
      "It contains the matrix of regeneration for\n"+
      "your current polymorph as a octopus.\n"+
      "Type 'class' to see your new abilities.\n");
   
   set_helpfile("octopus");
   set_multilimbed(7);
   set_weapon_wlim(2);
   set_deathtime(2100);
   set_block_wimpy();
   set_block_magic();
} 

init()
{
   add_action("octopus_inkjet","inkjet");
   ::init();
}

extra_look() 
{
   if(ENV) return (ENV->query_name()) + 
      " appears to really be an octopus.\n";
}

random_emote()
{
   if(1 == random(60)) 
      {
      tell_object(ENV, "You scratch yourself. Eight times.\n");
      ENV->remote_say((ENV->query_name()) + " scratches " + ENV->query_objective() + "self ... Eight times.\n");
   }
   
   if(1 == random(40)) 
      {
      tell_object(ENV, "You wave your tentacles about menacingly.\n");
      ENV->remote_say((ENV->query_name()) + " waves " + ENV->query_possessive() + " tentacles about menacingly.\n");
   }
}

/* this has been redone to fit the new damage system */
fake_beat() 
{
   object attacker;
   int i, j, total_damage;
   int tmp;
   
   /* Total damage should not exceed 50 per round. */
   if(ENV)
   {
      
      attacker = ENV->query_attack();
      
      if(!attacker) random_emote();
      
      /*Put in ghost check due to double deaths -Snow 4/99 */
      if(attacker && !ENV->query_ghost())
      {
         
        /* What's happening here looks crazy but its actually quite
         * simple. One of two attack types will happen.
         *
         * (7/8ths of the time...)
         * Cyclic: Only two arms per round will engage, randomly
         * during the combat round. This gives the player a
         * strike that is halfway between tetrapod and golem.
         *
         * (1/8th of the time...)
         * Synchronized: All arms will engage and strike the target
         * at once. This is the fun one.
         */
         
         j = MASTER_R->multilimb_synchronized_attack(
                ENV,         /* ourselves */
                attacker,    /* our attacker */
                8,           /* The chance of this attack hitting, in this case 1 / x of the time */
                ESC + "[1m" + ESC + "[31m" + "You find your rhythm!" + ESC + "[0m\n" + ESC + "[1m" + ESC + "[37m",
                ENV->query_name() + " finds a wicked beating rhythm...\n" + ESC + "[1m" + ESC + "[37m",
                1,           /* The WC divisor applied to our strapped weapons, where = to 1 / x */
                2,           /* The chance our WC gets gutted for no reason, where = to 1 every x rounds */
                2,           /* The divisor we get gutted, where damage = to damage / x hitpoints */
                4700000,     /* The divisor our our weapon breakage. Can be tweaked to break sooner */
                COMBAT_DAMAGE_CAP);  /* The max cumulative damage per round that can be done */
             
         if(!j) MASTER_R->multilimb_cyclic_attack(
                   ENV,       /* ourselves */
                   attacker,  /* our attacker */
                   2,         /* The chance that the hit lands, where for each arm 1 / x chance hits */
                   0,         /* A string that we tell ourselves */
                   0,         /* A string everyone else sees */
                   1,         /* The divisor applied to our WC on each limb. Default is 1. */
                   3,         /* The chance we get gutted, where = 1 per every x combat round */
                   2,         /* the divisor for what we gut our damage, where damage = damage / x hitpoints */
                   4700000);  /* Our weapon breakage divisor */       
            
      } /* end of if ENV */
   }
         
   ::fake_beat();
      
}
   
   
octopus_inkjet() { return MASTER_R->octopus_inkjet(); }
   
