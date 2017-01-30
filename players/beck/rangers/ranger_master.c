/************************************************************************   
 *  The Power Ranger Master Guild Object                                *
 *  Created by Beck/Russ Warren for Nirvana.                            *
 *  Last Changed 1/15/97.                                               *
 ************************************************************************/

int power_points;
string cmds;
static string *active_rangers;
#include "/players/beck/rangers/defs.h"
#include "cosmo/blast.h"
#include "cmds/lead.h"
#include "cmds/lamp.h"
#include "cmds/practice.h"
#include "cmds/study.h"
#include "cmds/2-person.h"
#include "cmds/blaster.h"
#include "cmds/speedster.h"
#include "cmds/armor.h"
#include "cmds/offense.h"
#include "cmds/defense.h"
#include "cmds/communication.h"
#include "cmds/teleport.h"
#include "cmds/who.h"
#include "cmds/time.h"
#include "cmds/help.h"
#include "cmds/train.h"
#include "cmds/unmorph.h"
#include "cmds/morph.h"
#include "cmds/call_thunderzord.h"
#include "cmds/call_megazord.h"
#include "cmds/battlezord.h"

/* The Guild Power Level (pool) */
set_power_points(arg){ power_points = arg; return 1; }
query_power_points(){ return power_points; }
reset(){ active_rangers = ({}); }
check_power(){  /* For Player to Check Guild Power Level */ 
   string msg;
   if(query_power_points() == 0){
      msg = "Guild Power is GONE"; }
   if(query_power_points() > 0){
      msg = "Guild Power Levels are critical"; }
   if(query_power_points() > 100){
      msg = "Guild Power is low"; }
   if(query_power_points() > 500){
      msg = "Guild Power is in good shape"; }
   if(query_power_points() > 1000){
      msg = "Guild Power levels are very good"; }
   if(this_player()->query_level() > 49){
      write("GUILD POWER LEVEL: "+query_power_points()+"\n");
   }
   write("GUILD POWER LEVEL: "+msg+".\n");
   return 1;
}

/*  Allows a player to convert spell points to guild power */
donate_power(num){
   int amount;
   if(sscanf(num, "%df", amount) !=1){
      write("Generate <spell points>\n");
      return 1;
   }
   if(amount < 1){
      write("You can't take away power points dummy.\n");
      return 1;
   }
if(this_player()->query_level() >19 && NAME != "beck"){
      write("Wizards may not donate power!\n");
      return 1;
   }
   if(this_player()->query_sp() < amount){
      write("You don't have that many spell points.\n");
      return 1;
   }
   this_player()->add_spell_point(-amount);
   COMM->add_skill_practice(amount/20);
   amount = amount - 20;
   amount += random(20);
   if(amount < 0){
      amount = 1;
   }
   write("You generate "+amount+" Power Points for the guild.\n");
   add_power_points(amount);
   return 1;
}

/*  Called by object or function to add or subtract from guild power */
add_power_points(num){
   power_points += num;
   return 1;
}


ranger_power(str){
   string verb;
   verb = query_verb();
   if(verb == "train"){ convert_gym_stats(); return 1;}
   if(verb == "lead"){ lead_battle(); return 1;}
   if(verb == "offense"){ identify_offense(); return 1;}
   if(verb == "defense"){ identify_defense(); return 1;}
   if(verb == "study"){ study_enemy(str); return 1;}
   if(verb == "lamp"){ ranger_lamp(); return 1;}
   if(verb == "dkick"){ double_kick(str); return 1;}
   if(verb == "morph"){ morph_ranger(str); return 1;}
   if(verb == "unmorph"){ unmorph_ranger(); return 1;}
   if(verb == "jet"){ ranger_jet(str); return 1; }
   if(verb == "practice"){ practice_arts(str); return 1;}
   if(verb == "power"){ check_power(); return 1;}
   if(verb == "generate"){ donate_power(str); return 1;}
   if(verb == "donate"){ ranger_blast(str); return 1;}
   if(verb == "time"){ check_time(); return 1;}
   if(verb == "teleport"){ teleport_ranger(str); return 1;}
   if(verb == "rt"){ ranger_talk(str); return 1;}
   if(verb == "ranger"){ ranger_help(str); return 1;}
   if(verb == "rwho"){ ranger_who(); return 1;}
   if(verb == "armor"){ metal_armor(); return 1;}
   if(verb == "weapon"){ metal_weapon(); return 1;}
   if(verb == "megazord"){ call_megazord(); return 1;}
   if(verb == "thunderzord"){ call_thunderzord(str); return 1;}
   if(verb == "rte"){ ranger_emote(str); return 1;}
   if(verb == "battlezord"){ call_battlezord(); return 1;}
   if(verb == "blaster"){ call_blaster(); return 1;}
}

use_defense(str){
   if(str == "backflip"){ return 1;}
   if(str == "block"){ return 1;}
   if(str == "shiho-nage"){ return 1;}
   if(str == "irimi-nage"){ return 1;}
   if(str == "kaiten-nage"){ return 1;}
   if(str == "kote-gaeshi"){ return 1;}
   if(str == "ikkyo"){ return 1;}
   if(str == "nikyo"){ return 1;}
   if(str == "sankyo"){ return 1;}
   if(str == "yonkyo"){ return 1;}
   if(str == "koshi-nage"){ return 2;}
   if(str == "tenchi-nage"){ return 3;}
   if(str == "juji-garami"){ return 2;}
   if(str == "aiki-otoshi"){ return 2;}
   if(str == "sumi-otoshi"){ return 2;}
   if(str == "kokyu-nage"){ return 2;}
   if(str == "aiki-nage"){ return 2;}
}


use_offense(str){
   if(str == "chop"){ return 1;}
   if(str == "butterfly"){ return 3;}
   if(str == "laugh"){ return 1;}
   if(str == "death"){ return 4;}
   if(str == "slap"){ return 1;}
   if(str == "scratch"){ return 1;}
   if(str == "throw"){ return 2;}
   if(str == "press"){ return 3;}
   if(str == "elbow"){ return 2;}
   if(str == "punch"){ return 1;}
   if(str == "axe"){ return 2;}
}

