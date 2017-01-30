inherit "/players/mizan/closed/poly/mob.c";
#include "/players/mizan/esc.h"


#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A dark granite sphere");
   set_long_desc("You look into the sphere and see a dark, stony face\n"+
      "staring right back.\n"+
      "The sphere your current polymorph as a golem.\n"+
      "Type 'class' to see your new abilities.\n");
      
   set_helpfile("golem");
   set_multilimbed(1);
   set_deathtime(3200);
   set_block_say();
   set_block_magic();
} 

extra_look() 
{
   if(ENV) return (ENV->query_name()) + " is a giant stone creature, mute and therefore\n"+
      "unable to communicate with you in normal methods";
}

fake_beat() 
{
   object attacker;
   int i, total_damage;
   int tmp;
   

   if(ENV)
   {
      attacker = ENV->query_attack();

      /*Put in ghost check due to double deaths -Snow 4/99 */
      if(attacker && !ENV->query_ghost())
      {
         /* cycle through the weapons for hits */
         while(i < sizeof(weapon)) 
         {
            if(weapon[i] && environment(weapon[i]) == this_object()) 
            {
               tmp = damage_level_filter(weapon[i]->weapon_class());

               /* randomly half it. */
               if(1 == random(4)) tmp = tmp / 2;
               total_damage = total_damage + tmp;
               weapon[i]->count_hit_made();
 
               if(weapon[i]->query_wear() > 1 && 
                  random(4700000/weapon[i]->query_wear()) < 10)
                  weapon[i]->weapon_breaks();
    
              /* berserk attack */
              if(1 == random(14)) 
              {
                 tell_object(ENV, "You get your second wind!\n");
                 ENV->remote_say((ENV->query_name()) + " gets a second wind!\n");

                 MASTER_R->extra_hit((tmp * 2), i, attacker, ENV);
                 
                 break;
              }
              else MASTER_R->extra_hit(tmp, i, attacker, ENV);
            }
            else
            {
               /* bare-fisted */
               MASTER_R->extra_hit(3, i, attacker, ENV);
               total_damage += 3;
            }
           
            i++;
         }

         if(random(ENV->query_attrib("ste")) < 2) 
         {
            MASTER_R->hit_creature(ENV, attacker, 0);
         }
         else MASTER_R->hit_creature(ENV, attacker, total_damage);
         
      }
   }

   ::fake_beat();
}


