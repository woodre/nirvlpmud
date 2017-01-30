#include "/players/mizan/esc.h"
#include "definitions.h"

inherit "/players/mizan/closed/poly/mob.c";

#define ENV environment(this_object())
#define MASTER_R "/players/mizan/closed/poly/PDM.c"
#define DARK_R "/players/mizan/closed/poly/dark_tetrapodDM.c"

/*
 * DAMAGE FORMULAS:
 *
 * There can be up to 3 extra limbs, for a total of 4 weapon hit attacks.
 * The actual hits are called from fake_beat in gob.c
 * This is so hit_player is called only once per round.
 * 
 * Every heartbeat the list of extra limbs is cycled.
 * If the limb is unarmed the damage is random(3) PER LIMB.
 * If there is a weapon, 2/3 of its WC is used to compute damage = random(2/3 * WC)
 * 50% of the time 1/2 of the weapon class is used so damage = random(WC/2)
 *
 * These are then totaled up and fed to the damage queue.
 * In the gob.c, the damage is called, with 40 being a hard cap on damage per round.
 * This form costs 23 SP per minute, with a computed amount being 30 mins / 700 sp.
 * That's it!
 *
 */

/*
 * Serious changes as to how tetrapod does damage.
 * It is weak until a player is L15.
 */

int previous_round_hp;
int previous_stat_delta;

reset(arg)
{
   if(arg) return;
   ::reset();
   
   set_short_desc("A burning brown sphere");
   set_long_desc("You look into the sphere and see the reflection\n"+
  "of a nightmarish, multilimbed creature with a psychopathic\n"+
  "gleam of fury in its eyes...\n"+
  "This sphere contains your matrix of regneration for a dark tetrapod .\n"+
  "Type 'class' to see your new abilities.\n");
      
   set_helpfile("dark_tetrapod");
   set_multilimbed(3);
   set_deathtime(1800);
   set_block_wimpy();
   set_block_magic();
   set_allow_sonic();
   set_night_vision();
} 

init()
{
   add_action("tetrapod_raar","raar");
   add_action("tetrapod_blitz","blitz");
   add_action("dark_tetrapod_cloak", "cloak");
   add_action("dark_tetrapod_vigor", "vigor");
   add_action("dark_tetrapod_calm", "calm");
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
   object room;
   room = environment(ENV);
   
   if(1 == random(120)) 
   {
       tell_object(ENV, "You growl and search for someone to beat on.\n");
       ENV->remote_say((ENV->query_name()) + " growls and searches for someone's skull to break open.\n");
   }

   if(1 == random(120)) 
   {
      tell_object(ENV, "You chomp on some dirt.\n");
      ENV->remote_say((ENV->query_name()) + " chomps on some dirt.\n");
   }

   if(1 == random(60) && room && sizeof(all_inventory(room)) > 1) 
   {
      tell_object(ENV, "You glance across the room in a calculating manner...\n");
      ENV->remote_say((ENV->query_name()) + " appears to be calculating something evil.\n");
      tell_object(ENV, DARK_R->calculate_weakest(room));
   }
}


/* this has been redone to fit the new damage system */
fake_beat() 
{
   object attacker;
   int i, total_damage;
   int current_hp, tmp;

   /* Total damage should not exceed 50 per round. */
   if(ENV)
   {
      current_hp = ENV->query_hp();
      if(!previous_round_hp) previous_round_hp = current_hp;
      
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
dark_tetrapod_cloak(str) { return MASTER_R->dark_tetrapod_cloak(str); }
dark_tetrapod_vigor(str) { return MASTER_R->dark_tetrapod_vigor(str); }
dark_tetrapod_calm() { return MASTER_R->dark_tetrapod_calm(); }
