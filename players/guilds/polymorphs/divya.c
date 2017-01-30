inherit "/players/mizan/closed/poly/mob.c";
#include "/players/mizan/esc.h"
#include "definitions.h"


#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

/* messages used in combat for synchronized hits */
string sync_mess;
string sync_say_mess;

/* messages used as random says in combat */
string att_mess;

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A brilliant sky blue sphere");
   set_long_desc("You look into the sphere and see the reflection\n"+
      "of a beautiful femme warrior! Long silver hair flows\n"+
      "down past your waist and your own piercing blue eyes set you\n"+
      "aback for just a moment.\n\n"+
      "Then you realize that the pristine face of beauty and terror staring\n"+
      "back at you really is indeed yourself.\n\n"+

      "This sphere contains your matrix of regneration for a divya.\n"+
      "Type 'class' to see your new abilities.\n");
      
   set_helpfile("divya");
   set_multilimbed(5);
   set_weapon_wlim(2);
   set_deathtime(1800);
   set_block_wimpy();
   set_block_magic();
   set_allow_fireball();

   if(!sync_mess)
      sync_mess = ({
         "You catch a wicked beat!",
         "Your concentration pays off!",
         "Excellent. You connect a synchronized series of hits.",
         "You shout: 'COMBINATION!'",
         "You mutter: 'Om Gum Ganapatayei Namaha...'\nA series of hits follows.",
         "You mutter: 'Om Shrim Mahalakshmiyei Swaha...'\nA fertile blast of hits ensues.",
         "You mutter: 'Om Dum Durgayei Namaha...'\nA ritual of delicate limb dislocation is played.",
         "You mutter: 'Om Eim Saraswatyei Swaha...'\nA private song of destruction is started.",
         "You mutter: 'Teah jaggananth...'\nThe cycle of rolling death begins.",
         "You mutter: 'Beatings will continue until morale improves.'",
         "Your chakras align and the beating begins!",
      });

   if(!sync_say_mess)
      sync_say_mess = ({
         "catches a wicked beat!",
         "concentrates deeply and executes a flow of hits!",
         "falls into a dreamy rhythm of pain infliction.",
         "shouts: 'COMBINATION!'",
         "mutters: 'Om Gum Ganapatayei Namaha...'\nA series of hits follows.",
         "mutters: 'Om Shrim Mahalakshmiyei Swaha...'\nA fertile blast of hits ensues.",
         "mutters: 'Om Dum Durgayei Namaha...'\nA ritual of delicate limb dislocation is played.",
         "mutters: 'Om Eim Saraswatyei Swaha...'\nA private song of destruction is started.",
         "mutters: 'Teah jaggananth...'\nThe cycle of rolling death begins.",
         "mutters: 'Beatings will continue until morale improves.'",
         "aligns the chakras and issues a systematic beatdown!",
      });
   
   if(!att_mess)
      att_mess = ({
         "It is a miracle that you are still alive.",
         "Are you wearing that outfit just to be funny?",
         "Come closer, sucker.",
         "Your existence is putrid. Absolutely putrid.",
         "Is that the best you can do? Surely you jest.",
         "You hedgepig.",
         "You wormfeeder.",
         "You useless lump.",
         "*snicker*",
         "Fish bait.",
         "Are you stupid, or gullible? Perhaps both.",
         "Look at me. I am taunting your existence",
         "I think, therefore I am. That does not apply to you.",
         "Look at me. Good. Now you understand my superiority.",
         "You will have to try harder than that, hedgepig.",
         "Hedgepig! You need discipline.",
         "Someday you would have grown up. Unfortunately you met me.",
         "Destitute are you, if fighting skills were wealth.",
         "It is a pity that you must be killed. A pity you have made my swords dirty.",
         "Is it refreshing you see yourself bleed?",
      });


} 

init()
{
   add_action("divya_switch","switch");
   add_action("divya_egress","egress");
   add_action("divya_lswords","lswords");
   add_action("divya_dswords","dswords");
   ::init();
}

extra_look() 
{
   if(ENV) return (ENV->query_name()) + 
       " is a six armed goddess";
}

random_emote()
{
   if(1 == random(200)) 
   {
       tell_object(ENV, "You smirk.\n");
       ENV->remote_say((ENV->query_name()) + " smirks wickedly.\n");
   }

   if(1 == random(200)) 
   {
      tell_object(ENV, "You stifle a snicker.\n");
      ENV->remote_say((ENV->query_name()) + " stifles a snicker.\n");
   }
}

/* this has been redone to fit the new damage system */
fake_beat() 
{
   object attacker;
   string say_msg, write_msg;
   int i, j, k, l, total_damage;
   int tmp;
   
   /* Total damage should not exceed 50 per round. */
   if(ENV)
      {
      
      attacker = ENV->query_attack();
      
      if(!attacker) random_emote();
      
      /* Put in ghost check due to double deaths -Snow 4/99 */
      
      if(attacker && !ENV->query_ghost())
         {
         
         /* What's happening here looks crazy but its actually quite
         * simple. One of two attack types will happen.
         *
         * (5/6ths of the time...)
         * Cyclic: Only two arms per round will engage, randomly
         * during the combat round. This gives the player a
         * strike that is halfway between tetrapod and golem.
         *
         * (1/6th of the time...)
         * Synchronized: All arms will engage and strike the target
         * at once. This is the fun one.
         *
         * (1/25th of the time...)
         * A bonus strike hits, with the same force of the synchronized attack.
         */

         k = random(sizeof(sync_say_mess));
         l = random(sizeof(att_mess));
         
         /* Our bonus strike */
         MASTER_R->multilimb_synchronized_attack(
                ENV,         /* ourselves */
                attacker,    /* our attacker */
                14,          /* The chance of this attack hitting, in this case 1 / x of the time */
                ESC + "[1m" + ESC + "[31m" + "You cries: 'COMBINATION!'" + ESC + "[0m" + "\n" + ESC + "[1m" + ESC + "[31m",
                ESC + "[1m" + ESC + "[31m" + ENV->query_name() + " cries: COMBINATION!" + ESC + "[0m" + "\n",
                -2,           /* The WC divisor applied to our strapped weapons, where = to 1 / x */
                50,           /* The chance our WC gets gutted for no reason, where = to 1 every x rounds */
                2,           /* The divisor we get gutted, where damage = to damage / x hitpoints */
                3300000,     /* The divisor our our weapon breakage. Can be tweaked to break sooner */
                COMBAT_DAMAGE_CAP + 10);  /* The max cumulative damage per round that can be done */

         j = MASTER_R->multilimb_synchronized_attack(
                ENV,         /* ourselves */
                attacker,    /* our attacker */
                6,           /* The chance of this attack hitting, in this case 1 / x of the time */
                ESC + "[1m" + ESC + "[36m" + (sync_mess[k]) + ESC + "[0m" + "\n" + ESC + "[1m" + ESC + "[37m",
                ESC + "[1m" + ESC + "[36m" + ENV->query_name() + " " + (sync_say_mess[k]) + ESC + "[0m" + "\n",
                1,           /* The WC divisor applied to our strapped weapons, where = to 1 / x */
                2,           /* The chance our WC gets gutted for no reason, where = to 1 every x rounds */
                2,           /* The divisor we get gutted, where damage = to damage / x hitpoints */
                4700000,     /* The divisor our our weapon breakage. Can be tweaked to break sooner */
                COMBAT_DAMAGE_CAP + 5);  /* The max cumulative damage per round that can be done */
             
         if(!j)
         {
            if(1 == random(8))
            {
                tell_object(ENV, ESC + "[1m" + ESC + "[36m" + "You look to " + (attacker->query_name()) + " and say: " + att_mess[l] + ESC + "[0m\n");
                ENV->remote_say(ESC + "[1m" + ESC + "[36m" + ENV->query_name() + " says to " + (attacker->query_name()) + ": " + att_mess[l] + ESC + "[0m" + "\n");
            }
            
            MASTER_R->multilimb_cyclic_attack(
                   ENV,       /* ourselves */
                   attacker,  /* our attacker */
                   2,         /* The chance that the hit lands, where for each arm 1 / x chance hits */
                   0,         /* A string that we tell ourselves */
                   0,         /* A string everyone else sees */
                   2,         /* The divisor applied to our WC on each limb. Default is 1. */
                   3,         /* The chance we get gutted, where = 1 per every x combat round */
                   2,         /* the divisor for what we gut our damage, where damage = damage / x hitpoints */
                   4700000);  /* Our weapon breakage divisor */       
         }


      } /* end of if ATTACKER */
         
   } /* end of if ENV */
      
   ::fake_beat();
}

divya_switch() { return MASTER_R->divya_switch(); }
divya_egress() { return MASTER_R->divya_egress(); }
divya_lswords(arg) { return MASTER_R->divya_lswords(arg); }
divya_dswords(arg) { return MASTER_R->divya_dswords(arg); }

