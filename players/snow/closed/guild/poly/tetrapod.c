#define MORPH_ID "Mizan-morph-object"
#include "/players/mizan/esc.h"
#define HELPFILE "/players/mizan/closed/poly/help/tetrapod"
#define MASTER_R "/players/mizan/closed/poly/PDM.c"
#define ENV environment(this_object())
#define DEATHTIME 4600


object weapon;

get() { return 1; }
drop () { return 1; }
id(str) { return str == "sphere" || str == MORPH_ID; }
reset(arg) {
  if(!weapon) weapon = allocate(3);
  if(!arg) call_out("force_return", DEATHTIME);
  call_out("fake_beat", 1);
}

no_wimpyallow() { return 1; }

exit() 
{
  object ob;
  object oc;
  ob = first_inventory(this_object());
  while(ob) 
  {
  oc = ob;
    if(environment(this_object()))
       move_object(oc, environment(this_object()));
    ob = next_inventory(ob);
  }
}


extra_look() 
{
  if(ENV) return (ENV->query_name()) + 
     " has four arms and looks really damn fearsome!"+
    "\n"+
    (ENV->query_name()) + " is constantly looking for someone to pound on";
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
      attacker = ENV->query_attack();
      if(attacker) 
      {
         while(i < sizeof(weapon)) 
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
    
             /* berserk attack- looks painful but actually can cancel other weaps */
              if(1 == random(23)) 
              {
                 tell_object(ENV, ESC + "[1m" + ESC + "[31m" + "You go BERSERK!\n");
                 ENV->remote_say(ESC + "[1m" + ESC + "[31m" + (ENV->query_name()) + " goes BERSERK!\n" + ESC + "[0m");
                 MASTER_R->extra_hit((tmp * 3), i, attacker, ENV);
                 tell_object(ENV, ESC + "[0m");
                 
                 /* mind you, this is where the real damage is being done */
                 MASTER_R->hit_creature(ENV, attacker, (total_damage + (tmp * 3)));
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
         if(random(ENV->query_attrib("ste")) < 6) 
         {
            MASTER_R->hit_creature(ENV, attacker, 0);
         }
         else MASTER_R->hit_creature(ENV, attacker, total_damage);
      }
   }

   /* Chance of weapon breaking is slightly higher than normally wielded */
   if(ENV)
   if(ENV->query_dead()) unstrap_all();
   remove_call_out("fake_beat");
   if(ENV)
   call_out("fake_beat", 1);
}

strap_weapon(str) { return MASTER_R->strap_weapon(str); }


unstrap_weapon(str) { return MASTER_R->unstrap_weapon(str); }

short() { return MASTER_R->multiweapon_mob_short(this_object(),"A bright orange sphere"); }

long() {
  int a;
  write("You look into the sphere and see a fearsome multilimbed creature.\n"+
  "It contains the matrix of regeneration for\n"+
  "your current polymorph as a tetrapod.\n"+
  "Type 'class' to see your new abilities.\n");
  while(a < 3) {
    if(weapon[a]) write((weapon[a]->short()) + " is strapped " + MASTER_R->get_type(a) + ".\n");
    a++;
  }
}

init() {
  add_action("class","class");
  add_action("strap_weapon","strap");
  add_action("unstrap_weapon","unstrap");
  add_action("tetrapod_raar","raar");
  add_action("tetrapod_blitz","blitz");
  add_action("block_wimpy","wimpy");
  add_action("block_magic","mi");
  add_action("block_magic","missile");
  add_action("block_magic","sh");
  add_action("block_magic","shock");
  add_action("block_magic","so");
  add_action("block_magic","sonic");
  add_action("block_magic","fi");
  add_action("block_magic","fireball");
}

class() { return cat(HELPFILE); }
tetrapod_blitz() { return MASTER_R->tetrapod_blitz(); }
tetrapod_raar(str) { return MASTER_R->tetrapod_raar(str); }


block_wimpy() {
  write("No way! You'd rather die fighting than wimp out.\n");
  return 1;
}

block_magic() {
  write("You are ignorant of magic.\n");

  return 1;
}

force_return() {
  if(ENV) tell_object(ENV, ESC + "[1m" + ESC + "[31m" +
    "You begin to tire, and feel that you can no longer assume this\n" +
  "morph form much longer...\n" + ESC + "[0m");
  call_out("force_return2", 60);
}

force_return2() {
  if(ENV) {
    if((ENV)->query_dead()) return 0;
    tell_object(ENV, "For no reason whatsoever, you suddenly lose concentration.\n");
    command("revert", ENV);
  }
}


/* ---- called when player quits, reverts, or dies --- */

unstrap_all() { return MASTER_R->unstrap_all(ENV); }

query_weapon_list() { return weapon; }
set_weapon_list(arg) {
  weapon = arg;
  if(!weapon) weapon = allocate(5);
}

