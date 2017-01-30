inherit "/players/mizan/closed/poly/mob.c";
#include "/players/mizan/esc.h"
#define GUILD_ID "Mizan-guild-object"
#define MORPH_ID "Mizan-morph-object"
#define HELPFILE "/players/mizan/closed/poly/help/gambler"
#define MASTER_R "/players/mizan/closed/poly/PDM.c"

#define ENV environment(this_object())
#define DEATHTIME 4000

/* can only strap weapons under a certain weight limit */
#define MAX_STRAP_WEIGHT     4

/* This is our array of weapons */
object weapon;

/* the number of limbs we may have. This value is RANDOMLY available */
int limbs;

status can_multilimb;
status can_gobblespew;
status can_usemagic;
status can_wimpy;

#define WEIGHT_MAX 20   /* Maximum weight of items allowed inside this object */

int local_weight;

get() { return 1; }
drop () { return 1; }
id(str) { return str == "sphere" || str == MORPH_ID; }

short() { return MASTER_R->multiweapon_mob_short(this_object(),"A plated gold sphere"); }

long() 
{
  write("You look into the sphere and see the reflection\n"+
  "of face that has a big toothy grin and what appears to be some\n"+
  "seriously slicked back hair with a pimp jacket. Yes, you are gambler.\n"+
  "This sphere contains your matrix of regneration for a gambler.\n"+
  "Type 'class' to see your new abilities.\n");
}

reset(arg) 
{


   if(!limbs) limbs = random(5) + 1;
   if(!weapon) weapon = allocate(limbs);
   if(!arg) call_out("force_return", DEATHTIME);

   call_out("slow_reset", 1);
   call_out("fake_beat", 1);

}

display_settings()
{
    if(can_multilimb)
    {
        write("You are able to use multiple limbs in combat.\n");
        write("You also have " + limbs + " extra limbs.\n");
    }
    else
        write("\nYou are NOT able to use multiple limbs in combat.\n");


    if(can_gobblespew)
        write("You are able to gobble and spew items.\n");
    else
        write("You are NOT able to gobble and spew items.\n");


    if(can_usemagic)
        write("You are able to use conventional magic in combat.\n");
    else
        write("You are NOT able to use conventional magic in combat.\n");

    
    if(can_wimpy)
        write("You are able to wimpy in combat.\n");
    else
        write("You are NOT able to wimpy in combat.\n");

    return 1;
}

slow_reset()
{
   if(ENV)
   {
      if(1 == random(2))
         can_multilimb = 1;
      else 
         can_multilimb = 0;
    
      if(1 == random(2))
         can_gobblespew = 1;
      else 
         can_gobblespew = 0;
      
      if(1 == random(2)) 
         can_usemagic = 1;
      else 
         can_usemagic = 0;

      
    
      if(1 == random(2)) 
         can_wimpy = 1;
         
      else 
         can_wimpy = 0;

      
      command("display_settings", ENV);
   }
}

extra_look() 
{
  if(ENV) return (ENV->query_name()) + 
     " appears to be one biznatch high roller.\n";
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

     /*Put in ghost check due to double deaths -Snow 4/99 */

     if(attacker && !ENV->query_ghost() && can_multilimb)
      {
      
         /* What's happening here looks crazy but its actually quite
          * simple. One of two attack types will happen.
          *
          * (7/8ths of the time...)
          * Cyclic: Only one extra arm per round will engage, randomly
          * during the combat round. This gives the player a
          * strike that is halfway between tetrapod and golem.
          *
          * (1/8th of the time...)
          * Synchronized: All arms will engage and strike the target
          * at once. This is the fun one.
          */
      
         /* THE SYNCHRONIZED ATTACK */
         if(1 == random(8))
         {

             tell_object(ENV, ESC + "[1;33m" + "You get LUCKY!" + ESC + "[0m\n");

             /* this sets up the extra ANSI */
             tell_object(ENV, ESC + "[1;37m");

             ENV->remote_say(ESC + "[1;33m" + ENV->query_name() + " gets some LUCKY shots!\n" + ESC + "[0m");

             while(i < sizeof(weapon)) 
             {
                if(weapon[i] && environment(weapon[i]) == this_object()) 
                {
                   tmp = weapon[i]->weapon_class();
                   
                   if(1 == random(10))
                   {
                       tell_object(ENV, "You sense a lucky shot...\n");
                       /* since we are a GAMBLER we randomly get a weapon specials jackpot as well */
                       tmp += call_other(weapon[i], "hit" ,attacker);
                   }

                   /* randomly dull the shot */
                   if(1 == random(3)) tmp = tmp / 2;

                   total_damage = total_damage + tmp;
                   weapon[i]->count_hit_made();
     
                   if(weapon[i]->query_wear() > 1 && 
                      random(4700000/weapon[i]->query_wear()) < 10)
                      weapon[i]->weapon_breaks();
        
                   MASTER_R->extra_hit(tmp, i, attacker, ENV);
                }
                else
                {
                   /* bare-fisted */
                   MASTER_R->extra_hit(3, i, attacker, ENV);
                   total_damage += 3;
                }
               
                i++;
             }

             /* this cleans up the extra ANSI */
             tell_object(ENV, ESC + "[0m");
             
             MASTER_R->hit_creature(ENV, attacker, total_damage);

         }  /* END SYNCHRONIZED ATTACK */


         else
         
         /* THE CYCLIC ATTACK */
         while(i < sizeof(weapon)) 
         {
            /* extra arms have a 1/2 chance of striking hits */
            
            if(1 == random(2))
            {
              if(weapon[i] && environment(weapon[i]) == this_object()) 
              {
                 tmp = weapon[i]->weapon_class();
                 if(1 == random(3)) tmp = tmp / 2;
                 total_damage = total_damage + tmp;
                 weapon[i]->count_hit_made();

                 if(weapon[i]->query_wear() > 1 && 
                    random(4700000/weapon[i]->query_wear()) < 10)
                    weapon[i]->weapon_breaks();
      
                 MASTER_R->extra_hit(tmp, i, attacker, ENV);
              }
              else
              {
                 /* bare-fisted */
                 MASTER_R->extra_hit(3, i, attacker, ENV);
                 total_damage += 3;
              }
            } /* end while random */
                       
            i++;
         }
         
         if(random(ENV->query_attrib("ste")) < 3) 
         {
            MASTER_R->hit_creature(ENV, attacker, 0);
         }
         else MASTER_R->hit_creature(ENV, attacker, total_damage);
         /* END CYCLIC ATTACK */
         
      } /* end of if ATTACKER */

   } /* end of if ENV */

   /* Chance of weapon breaking is slightly higher than normally wielded */
   if(ENV)
   if(ENV->query_dead()) unstrap_all();
   remove_call_out("fake_beat");
   if(ENV)
   call_out("fake_beat", 1);
}


strap_weapon(str) { 
   if(can_multilimb) return MASTER_R->strap_weapon(str, MAX_STRAP_WEIGHT);
   else return 0;
}

unstrap_weapon(str) {
   if(can_multilimb) return MASTER_R->unstrap_weapon(str);
   else return 0;
}

init() {
  add_action("class","class");
  add_action("strap_weapon","strap");
  add_action("unstrap_weapon","unstrap");
  add_action("gambler_gobble","gobble");
  add_action("gambler_spew","spew");
  add_action("block_wimpy","wimpy");
  add_action("block_magic","mi");
  add_action("block_magic","missile");
  add_action("block_magic","sh");
  add_action("block_magic","shock");
  add_action("block_magic","so");
  add_action("block_magic","sonic");
  add_action("block_magic","fi");
  add_action("block_magic","fireball");
  add_action("block_insert","put");
  add_action("block_remove","get");
  add_action("rtime","rtime");
  add_action("display_settings","display_settings");
}

can_put_and_get() { return 1; }

class() 
{
    cat(HELPFILE); 
    display_settings();
    return 1;
}

query_weapon_limit() { return 3; }
no_wimpyallow() { return 1; }

block_remove(str)
{
  string blah;
  if(str && sscanf(str, "%s from sphere", blah) == 1)
  {
     write("You cannot do that.\n");
     return 1;
  }
  else return 0;
}

block_insert(str)
{
  string blah;
  if(str && sscanf(str, "%s in sphere", blah) == 1)
  {
     write("You cannot do that.\n");
     return 1;
  }
  else return 0;
}

block_wimpy() {
   if(!can_wimpy)
   {
      write("You are not stealthy enough to flee.\n");
      return 1;
   }
}

block_magic() {
   if(!can_usemagic)
   {
      write("You are ignorant of magic.\n");
      return 1;
   }
}

force_return() {
  if(ENV) tell_object(ENV, ESC + "[1m" + ESC + "[31m" +
    "You begin to tire, and feel that you can no longer assume this\n" +
  "morph form much longer...\n" + ESC + "[0m");
  call_out("force_return2", 10);
}

force_return2() {
   if(ENV) {
      if((ENV)->query_dead()) return 0;
      tell_object(ENV, "For no reason whatsoever, you suddenly lose concentration.\n");
      if(environment(ENV))
         call_other(environment(ENV), "revert", ENV);
      MASTER_R->undo_polymorph(ENV);
   }
}

rtime() 
{
  int i;
  int foo;
  string dc_text;
  
  if((i = find_call_out("force_return")) >= 0) 
  {
    dc_text = ("Countdown until forced reversion: ");
    foo=i/60;
    if((i-foo) == 0) dc_text = dc_text + ("(" + foo + " minutes).\n");
    else dc_text = dc_text + ("(" + foo + " minutes, " + (i-(foo * 60)) + " seconds).\n");
    write(dc_text);
    return 1;
  }
  else
  {
    write("Forced reversion is happening very soon!\n");
    return 1;
  }
}


/* ---- called when player quits, reverts, or dies --- */

unstrap_all() { return MASTER_R->unstrap_all(ENV); }

query_weapon_list() { return weapon; }

set_weapon_list(arg) 
{
  weapon = arg;
  if(!weapon) weapon = allocate(limbs);
}

/* For dealing with the weight of strapped weapons. -Feldegast 12-31-00 */

query_weight() 
{
  int weight, i;
  if(!weapon) return;
  for(i=0; i < sizeof(weapon); i++)
    if(weapon[i]) weight+=weapon[i]->query_weight();
  return weight;
}

/* INVENTORY STUFF */

add_weight(arg)
{
  int i;
  i = arg;
  if((i + local_weight) > WEIGHT_MAX) return 0;
  else local_weight = local_weight + i;
  return 1;
}

burp_routine() 
{
  remove_call_out("burp");
  call_out("burp", 5);
}

burp(){
  if(ENV) {
    tell_object(ENV, "You burp loudly.\n");
    ENV->remote_say((ENV->query_name()) + " burps loudly.\n");
  }
}

gambler_gobble(str) {
   if(can_gobblespew) return MASTER_R->spuckball_gobble(str); 
   else return 0;
}

gambler_spew(str) {
   if(can_gobblespew) return MASTER_R->spuckball_spew(str); 
   else return 0;
}


