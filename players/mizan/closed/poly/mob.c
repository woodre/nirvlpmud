#include "/players/mizan/esc.h"

/*
 * mob.c
 *
 * This is the morph object that is used to standardize certain functions
 * across all morph forms. It's fairly basic and crude in certain respects
 * but a lot of that was to preserve some compatibility with stuff.
 *
 */

#define ENV environment(this_object())
#define MORPH_ID "Mizan-morph-object"
#define GUILD_ID "Mizan-guild-object"
#define MASTER_R "/players/mizan/closed/poly/PDM.c"
#define HELPPATH "/players/mizan/closed/poly/help/"


object weapon;         /* [ARRAY] This is our array of weapons */
string short_desc;     /* The short() of the sphere */
string long_desc;      /* The long() of the sphere */
string helpfile;       /* The name of the file (not path) when a player types 'class' */
int num_limbs;         /* The number of limbs we have */
int deathtime;         /* The amount of life in callout seconds that we can assume this form. */
int weapon_wlim;       /* The weight that multilimbed forms are limited to using as weapons */
int maximum_weight;    /* The maximum weight we can carry in our mob */
int local_weight;      /* What our current carry is. */
int dam_factor;        /* Used for calculating damage loss/efficiency for lower level morph forms in multilimb */
int teambonus_present; /* The number of members around */

status block_wimpy_tl;     /* If on, blocks wimpy from happening. */
status block_magic_tl;     /* If on, prevents players from casting game spells like sonic. */
status block_say_tl;       /* If on, the player cannot use conventional conversation. */
status block_armor_tl;     /* If on, the player cannot wear armors. */
status block_weapon_tl;    /* If on, the player cannot wield weapons. */
status block_killcmd_tl;   /* If on, the player cannot type 'kill' */
status block_movement_tl;  /* If on, the player cannot move in standard directions. */
status is_multilimbed;     /* If on, the player has multiple limbs */
status is_timed;           /* If on, the form will expire in a given time */
status is_weapon_wlim;     /* If on, the form has a weapon weight limit */
status is_teambonused;     /* If on, the form has a bonus when other forms like it are around */
status is_nightvision;     /* If on, the form has night vision */
status can_store_items;    /* If on, the mob can be grobbled with items like a bag. */
status allow_fireball;     /* If on, allows the game fireball spell despite being magic blocked. */
status allow_sonic;        /* If on, allows the game sonic spell despite being magic blocked. */

/*
 * CORE FUNCTIONS
 */
id(str)
{
   string night_vision;
   string armor;
   string magic;

   if(is_nightvision) night_vision = "dark_sight_object";
   else night_vision = "not_dark_sight_object"; 

   if(block_magic_tl) magic = "no_spell";
   else magic = "spells_okay";

   if(block_armor_tl) magic = "notarmor";
   else armor = "armors_okay";

   return str == "sphere" || str == MORPH_ID || str == magic || str == armor || str ==night_vision;
}

short() { return MASTER_R->multiweapon_mob_short(this_object(), short_desc); }

long() 
{
   int a;
   write(long_desc);
   write("\n");
   if(!weapon) weapon = ({ }); /* by verte 9.13.01 */
   while(a < sizeof(weapon))
   {
      if(weapon[a]) write((weapon[a]->short()) + " is strapped " + MASTER_R->get_type(a) + ".\n");
      a++;
   }
}

reset(arg)
{
   if(!arg)
   {
      call_out("fake_beat", 1);
      call_out("slow_reset", 1);
   }
}

slow_reset()
{
   if(ENV && ENV->query_level())
   {
      /* this calculates our damage cap */
      if(ENV->query_level() >= 19) dam_factor = 4;
      else if(ENV->query_level() >= 17) dam_factor = 3;
      else if(ENV->query_level() >= 14) dam_factor = 2;
      else if(ENV->query_level() >= 8) dam_factor = 1;
      else dam_factor = 0;
   }

}

init() 
{

   if(block_wimpy_tl)
      add_action("block_wimpy","wimpy");

   if(block_weapon_tl)
   {
      add_action("block_wield","wield");
      add_action("block_wield","#");
   }      
   if(block_magic_tl)
   {
      add_action("block_magic","mi");
      add_action("block_magic","missile");
      add_action("block_magic","sh");
      add_action("block_magic","shock");

      /*  /players/jaraxle/cont/bdragon/amulet  */
      add_action("block_magic","electrify");
      add_action("block_magic","elec");
      
      /* francesco's laser */
      add_action("block_magic","trigger");


      if(!allow_sonic)
      {
         add_action("block_magic","so");
         add_action("block_magic","sonic");
      }
      if(!allow_fireball)
      {
         add_action("block_magic","fi");
         add_action("block_magic","fireball");
      }
   }
   
   if(block_movement_tl)
   {
      add_action("block_movement","n");
      add_action("block_movement","s");
      add_action("block_movement","e");
      add_action("block_movement","w");
      add_action("block_movement","nw");
      add_action("block_movement","ne");
      add_action("block_movement","nw");
      add_action("block_movement","se");
      add_action("block_movement","sw");
      add_action("block_movement","u");
      add_action("block_movement","d");
      add_action("block_movement","out");
      add_action("block_movement","in");
      add_action("block_movement","north");
      add_action("block_movement","south");
      add_action("block_movement","east");
      add_action("block_movement","west");
      add_action("block_movement","northwest");
      add_action("block_movement","northeast");
      add_action("block_movement","southwest");
      add_action("block_movement","southeast");
      add_action("block_movement","up");
      add_action("block_movement","down");
      add_action("block_movement","enter");
   }
   
   if(block_killcmd_tl)
   {
      add_action("block_kill", "kill");
   }

   if(is_multilimbed)
   {
      add_action("strap_weapon","strap");
      add_action("unstrap_weapon","unstrap");
   }
   
   if(can_store_items)
   {
      add_action("mob_gobble","gobble");
      add_action("mob_spew","spew");
   }
   
   if(is_timed)
      add_action("rtime","rtime");

   if(block_say_tl)
   {
      add_action("block_say","say");
      add_action("block_say","ring");
#ifndef __LDMUD__
      add_action("block_say"); add_xverb("'");
      add_action("block_say"); add_xverb("\"");
#else
      add_action("block_say", "'", 3);
      add_action("block_say", "\"", 3);
#endif
      add_action("block_say","gossip");
      add_action("block_say","risque");
      add_action("block_say","junk");
      add_action("block_say","msg");
      add_action("block_say","equip");
      add_action("block_say","babble");
      add_action("block_say","chat");
      add_action("block_say","chate");
      add_action("block_say","tale");
      add_action("block_say","talee");
      add_action("block_say","story");
      add_action("block_say","storye");
      add_action("block_say","tempt");
      add_action("block_say","meow");
      add_action("block_say","meowe");
      add_action("block_say","alt");
      add_action("block_say","ale");
      add_action("block_say","brag");
      add_action("block_say","brage");
      add_action("block_say","shout");
      add_action("block_say","com");
      add_action("block_say","converse");
      add_action("block_say","be");
      add_action("block_say","fli");
      add_action("block_say", "tell");
      add_action("block_say","bdt");
      add_action("block_say","bbe");
      add_action("block_say","farem");
      add_action("filter_party","party");
      add_action("block_say","pe");
      add_action("block_say","pt");
      add_action("block_say","emote");
#ifndef __LDMUD__
      add_action("block_say"); add_xverb(";");
      add_action("block_say"); add_xverb(":");
#else
      add_action("block_say", ";", 3);
      add_action("block_say", ":", 3);
#endif
      add_action("block_say","communicate");
      add_action("block_insert","put");
      add_action("block_remove","get");
   }
   
   add_action("class","class");
   add_action("block_insert","put");
   add_action("block_remove","get");
}

fake_beat() 
{
   object ob, gob, mob, room;
   int i;
   
   if(ENV)
   {
      room = environment(ENV);
      
      if(ENV->query_dead() && is_multilimbed) unstrap_all();
      if(block_weapon_tl && ENV->query_weapon()) ENV->stop_wielding();
      if(is_teambonused && room)
      {
         teambonus_present = 0;
         
         ob = all_inventory(room);
         for(i = 0; i < sizeof(ob); i ++)
         {
             mob = present(MORPH_ID, ob[i]);
            if(mob && ob[i] != ENV && mob->query_morphname() == helpfile) teambonus_present++;
         }
         
         if(teambonus_present > 0) teambonus_beat();
      }
   
      call_other(this_object(), "random_emote");
   } /* end of if ENV */
   
   remove_call_out("fake_beat");
   if(ENV) call_out("fake_beat", 1);
}

/* This method is called if there are members of the room present who are
 * also in the same morph form. */
teambonus_beat()
{

/*
   if(ENV) tell_object(ENV, "[" + teambonus_present + "] members present.\n");
 */
}

show_light(arg)
{
   object room;
   
   room = arg;
   
   if(ENV)
   {
      set_light(1);
   }   
}

/*
 * QUERY FUNCTIONS
 */

/* For dealing with the weight of strapped weapons. -Feldegast 12-31-00 */
query_weight() 
{
   int weight, i;
   
   if(!weapon) return;

   for(i = 0; i < sizeof(weapon); i++)
      if(weapon[i]) weight += weapon[i]->query_weight();
   return weight;
}

query_weapon_limit()
{
   if(is_multilimbed) return (num_limbs + 1); 
   else return 0;
}

query_weapon_list() { return weapon; }

query_rtime()
{
   int foo, i;
   string dc_text;
   
   if(is_timed && (i = find_call_out("force_return")) >= 0)
   {
      dc_text = "";

      foo = i / 60;
      if((i-foo) == 0) dc_text = dc_text + ("(" + foo + " minutes).\n");
      else dc_text = dc_text + ("(" + foo + " minutes, " + (i-(foo * 60)) + " seconds)");

      return dc_text;
  }
  else return 0;
}

query_weapon_wlim() { return weapon_wlim; }

query_morphname() { return helpfile; }
query_damage_level_filter() { return dam_factor; }

/*
 * SET FUNCTIONS
 */
set_short_desc(arg)
{
   short_desc = arg;
   if(!short_desc) short_desc = "An orange sphere";
}

set_long_desc(arg)
{
   long_desc = arg;
}

set_helpfile(arg)
{
   helpfile = arg;
}

/* Called when cloned... set the number of limbs we are allowed to have */
set_multilimbed(arg)
{
   if(!arg || arg < 1 || arg > 11) return 0;
   weapon = allocate(arg);
   is_multilimbed = 1;
}

set_deathtime(arg)
{
   if(!arg) return 0;
   is_timed = 1;
   deathtime = arg;

   remove_call_out("force_return");
   call_out("force_return", deathtime);
}

set_night_vision() { is_nightvision = !is_nightvision; }
set_is_team_bonused() { is_teambonused = !is_teambonused; }

set_block_wimpy() { block_wimpy_tl = !block_wimpy_tl; }
set_block_magic() { block_magic_tl = !block_magic_tl; }
set_block_say() { block_say_tl = !block_say_tl; }
set_block_armor() { block_armor_tl = !block_armor_tl; }
set_block_weapon() { block_weapon_tl = !block_weapon_tl; }
set_block_wield() { block_weapon_tl = !block_weapon_tl; }
set_block_movement() { block_movement_tl = !block_movement_tl; }
set_allow_fireball() { allow_fireball = !allow_fireball; }
set_allow_sonic() { allow_sonic = !allow_sonic; }

set_block_killcmd()
{
  block_killcmd_tl = !block_killcmd_tl;
  if(block_killcmd_tl) block_weapon_tl = 1;
  else block_weapon_tl = 0;
  if(block_killcmd_tl) block_magic_tl = 1;
  else block_magic_tl = 0;
}

set_weapon_list(arg) 
{
   weapon = arg;
   if(!weapon) weapon = allocate(num_limbs);
   if(!is_multilimbed) is_multilimbed = 1;
}

set_weapon_wlim(arg)
{
   if(!arg)
   {
      is_weapon_wlim = 0;
      weapon_wlim = 0;
   }
   else
   {
      is_weapon_wlim = 1;
      weapon_wlim = arg;
   }
}

set_weight_limit(arg)
{
   if(!arg)
   {
      maximum_weight = 0;
      can_store_items = 0;
   }
   else
   {
      maximum_weight = arg;
      can_store_items = 1;
   }
}


/*
 * OTHER STUFF
 */
 
get() { return 1; }
drop () { return 1; }
can_put_and_get() { return 1; }

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

block_wimpy() 
{
   write("No way! You'd rather die fighting than wimp out.\n");
   return 1;
}

block_magic() 
{
   write("You are ignorant of magic.\n");
   return 1;
}

block_wield() 
{
  write("You are unable to wield weapons, for some reason.\n");
  return 1;
}

block_movement() 
{
  write("You are unable to.\n");
  return 1;
}

block_kill() 
{
  write("You can't!\n");
  return 1;
}

block_say() 
{
   write("You can't.\n");
   return 1;
}

filter_party(str) 
{
   string tmpl;
   if(!str) return 0;
   if(sscanf(str, "sa%s", tmpl) == 1 || sscanf(str, "tel%s", tmpl) == 1) return block_say();
   else return 0;
}


force_return()
{
   if(ENV)
      tell_object(ENV, ESC + "[1m" + ESC + "[31m" +
         "You begin to tire, and feel that you can no longer assume this\n" +
         "morph form much longer...\n" + ESC + "[0m");
   call_out("force_return2", 60);
}

force_return2() 
{
   if(ENV) 
   {
      if((ENV)->query_dead()) return 0;
      tell_object(ENV, ESC + "[1m" + ESC + "[31m" + "You are too tired to remain morphed. You revert instantly." + ESC + "[0m\n"); 
 
      if(environment(ENV))
          call_other(environment(ENV), "revert", ENV);

      MASTER_R->undo_polymorph(ENV);
   }
}

class() { return cat(HELPPATH + helpfile); }

strap_weapon(str) 
{
   if(is_multilimbed) return MASTER_R->strap_weapon(str, weapon_wlim);
   else return 0;
}

unstrap_weapon(str)
{
   if(is_multilimbed) return MASTER_R->unstrap_weapon(str);
   else return 0;
}

unstrap_all()
{
   if(is_multilimbed) return MASTER_R->unstrap_all(ENV);
   else return 0;
}

no_wimpyallow()
{
   if(block_wimpy_tl) return 1; 
   else return 0;
}

rtime() 
{
   int i;
   string dc_text;
   
   if(!is_timed) return 0;  

   if((i = find_call_out("force_return")) >= 0) 
   {
      dc_text = "Countdown until forced reversion: " + query_rtime() + ".\n";
      write(dc_text);
      return 1;
   }
   else
   {
      write("Forced reversion is happening very soon!\n");
      return 1;
   }
}


/* INVENTORY STUFF */

add_weight(arg) 
{
   int i;
   
   if(!can_store_items) return 0;
   
   i = arg;
   if((i + local_weight) > maximum_weight) return 0;
   else local_weight = local_weight + i;
   return 1;
}

burp_routine() 
{
   remove_call_out("burp");
   call_out("burp", 5);
}

burp()
{
   if(ENV) 
   {
      tell_object(ENV, "You burp loudly.\n");
      ENV->remote_say((ENV->query_name()) + " burps loudly.\n");
   }
}

mob_gobble(str) { return MASTER_R->spuckball_gobble(str); }
mob_spew(str) { return MASTER_R->spuckball_spew(str); }

/* COMBAT STUFF */
damage_level_filter(arg)
{
   if(dam_factor == 0)
   {
      /* We half the damage inflicted here no matter what. */
      return (arg / 2);
   }
   else if(dam_factor == 1)
   {
      /* We return 1/2 to 2/3 of the damage here */
      if(1 == random(3))
         return (arg * 2) / 3;
      else return (arg / 2);
   }
   else if(dam_factor == 2)
   {
      if(1 == random(3))
         return arg;
      else return (arg * 5) / 8;
   }
   else if(dam_factor == 3)
   {
      if(1 == random(2))
         return arg;
      else return (arg * 2) / 3;
   }
   else return arg;
   
}

