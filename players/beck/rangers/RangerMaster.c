/************************************************************************   
*  The Power Ranger Master Guild Object                                *
*  Created by Beck/Russ Warren for Nirvana.                            *
*  Last Changed 12/15/97.                                               *
************************************************************************/

int PowerPoints;
string cmds;
mapping Rangers;
#include "/players/beck/rangers/Defs.h"
#include "cmds/TrainingMessage.h"
#include "cmds/Aid.h"
#include "cosmo/Donate.h"
#include "cmds/Lead.h"
#include "cmds/Practice.h"
#include "cmds/Study.h"
#include "cmds/Blaster.h"
#include "cmds/Jet.h"
#include "cmds/Offense.h"
#include "cmds/Defense.h"
#include "cmds/Communication.h"
#include "cmds/Teleport.h"
#include "cmds/Rwho.h"
#include "cmds/Time.h"
#include "cmds/Help.h"
#include "cmds/Unmorph.h"
#include "cmds/Morph.h"
#include "cmds/Ninja.h"
#include "cmds/Zord.h"
#include "cmds/Megazord.h"
#include "cmds/Teach.h"

void AddRanger(string name, object ranger){
   object *rangers;
   int i;
   if(Rangers == 0){ Rangers = ([ ]); }
   if(!(rangers = Rangers[name])){
      Rangers[name] = ({ ranger });
   }
   rangers = Rangers[name];
   if (member_array(ranger, rangers) < 0) {
      if ((i = member_array(0, rangers)) < 0)
         Rangers[name] += ({ ranger });
      else
         rangers[i] = ranger;
   }
}

void RemoveRanger(string name, object ranger){
   object *rangers;
   if(Rangers == 0){ Rangers = ([ ]); }
   if(rangers = Rangers[name]){
      Rangers[name] -= ({ranger});
   }
   else{
      return;
   }
}

/* The Guild Power Level (pool) */
SPowerPoints(arg){ PowerPoints = arg; return 1; }
QPowerPoints(){ return PowerPoints; }

/*  Called by object or function to add or subtract from guild power */
APowerPoints(num){
   PowerPoints += num;
   return 1;
}

CheckPower(){  /* For Player to Check Guild Power Level */ 
   string msg;
   if(QPowerPoints() == 0){
      msg = "Guild Power is GONE"; }
   if(QPowerPoints() > 0){
      msg = "Guild Power Levels are critical"; }
   if(QPowerPoints() > 100){
      msg = "Guild Power is low"; }
   if(QPowerPoints() > 500){
      msg = "Guild Power is in good shape"; }
   if(QPowerPoints() > 1000){
      msg = "Guild Power levels are very good"; }
   write("GUILD POWER LEVEL: "+msg+".\n");
   return 1;
}

/*  Allows a player to convert spell points to guild power */
GeneratePower(num){
   int amount;
   if(sscanf(num, "%df", amount) !=1){
      write("Generate <spell points>\n");
      return 1;
   }
   if(amount < 1){
      write("You can't take away power points dummy.\n");
      return 1;
   }
   if(TP->LEVEL > 19){
      write("Wizards may not donate power!\n");
      return 1;
   }
   if(TP->SP < amount){
      write("You don't have that many spell points.\n");
      return 1;
   }
   this_player()->add_spell_point(-amount);
   amount = amount - 20;
   amount += random(20);
   if(amount < 0){
      amount = 1;
   }
   write("You generate "+amount+" Power Points for the guild.\n");
   APowerPoints(amount);
   if(COMM){
      COMM->ASkillExp(amount/10);
   }
   return 1;
}



RangerPower(str){
   string verb;
   verb = query_verb();
   if(verb == "aid"){ AidRanger(str); return 1;}
   if(verb == "ninja"){ MorphNinja(); return 1;}
   if(verb == "teach"){ TeachRanger(str); return 1; }
   if(verb == "lead"){ lead_battle(); return 1;}
   if(verb == "skills"){ COMM->SeeSkills(); return 1; }
   if(verb == "offense"){ COMM->SeeOffense(); return 1;}
   if(verb == "defense"){ COMM->SeeDefense(); return 1;}
   if(verb == "study"){ study_enemy(str); return 1;}
   if(verb == "lamp"){ COMM->SHelmetLamp(); return 1;}
   if(verb == "morph"){ MorphRanger(str); return 1;}
   if(verb == "unmorph"){ UnmorphRanger(); return 1;}
   if(verb == "jet"){ ranger_jet(str); return 1; }
   if(verb == "practice"){ practice_arts(str); return 1;}
   if(verb == "power"){ CheckPower(); return 1;}
   if(verb == "generate"){ GeneratePower(str); return 1;}
   if(verb == "donate"){ ranger_blast(str); return 1;}
   if(verb == "time"){ check_time(); return 1;}
   if(verb == "teleport"){ teleport_ranger(str); return 1;}
   if(verb == "rt"){ return RangerTalk(verb,"all",str); }
   if(verb == "ranger"){ ranger_help(str); return 1;}
   if(verb == "rwho"){ return RangerWho("all"); }
   if(verb == "armor"){ COMM->MetallicArmor(); return 1;}
   if(verb == "weapon"){ COMM->PowerWeapon(); return 1;}
   if(verb == "rte"){ return RangerTalk(verb,"all",str); }
   if(verb == "blaster"){ call_blaster(); return 1;}
   if(verb == "zord"){ Zord(); return 1; }
   if(verb == "megazord"){ RangerMegazord(str); return 1; }
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

