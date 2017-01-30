/************************************************************************   
*  The Dark Ranger Master Guild Object                                *
*  Created by Beck/Russ Warren for Nirvana.                            *
*  Last Changed 12/15/97.                                               *
************************************************************************/

int PowerPoints;
string cmds;
mapping Rangers;

mapping MartialArts;
status MartialArtsDef;
#include "/players/beck/Defs.h"
#include "/players/beck/DarkRangers/MasterInc/CreateMonster.h"
#include "/players/beck/DarkRangers/RangerDefs.h"
#include "/players/beck/DarkRangers/MasterInc/TrainingMessage.h"
#include "/players/beck/DarkRangers/MasterInc/Rsc.h"
#include "/players/beck/DarkRangers/MasterInc/Ri.h"
#include "/players/beck/DarkRangers/MasterInc/Rwear.h"
#include "/players/beck/DarkRangers/MasterInc/Rwield.h"
#include "/players/beck/DarkRangers/MasterInc/Aid.h"
#include "/players/beck/DarkRangers/MasterInc/Donate.h"
#include "/players/beck/DarkRangers/MasterInc/Lead.h"
#include "/players/beck/DarkRangers/MasterInc/Practice.h"
#include "/players/beck/DarkRangers/MasterInc/Study.h"
#include "/players/beck/DarkRangers/MasterInc/Blaster.h"
#include "/players/beck/DarkRangers/MasterInc/Jet.h"
#include "/players/beck/DarkRangers/MasterInc/Communication.h"
#include "/players/beck/DarkRangers/MasterInc/Teleport.h"
#include "/players/beck/DarkRangers/MasterInc/Rwho.h"
#include "/players/beck/DarkRangers/MasterInc/Time.h"
#include "/players/beck/DarkRangers/MasterInc/Help.h"
#include "/players/beck/DarkRangers/MasterInc/Unmorph.h"
#include "/players/beck/DarkRangers/MasterInc/Morph.h"
#include "/players/beck/DarkRangers/MasterInc/Ninja.h"
#include "/players/beck/DarkRangers/MasterInc/Zord.h"
#include "/players/beck/DarkRangers/MasterInc/Megazord.h"
#include "/players/beck/DarkRangers/MasterInc/Teach.h"

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

RemoveRanger(string name, object ranger){
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
SPowerPoints(arg){ PowerPoints = arg; }
QPowerPoints(){ return PowerPoints; }

/*  Called by object or function to add or subtract from guild power */
APowerPoints(num){
   PowerPoints += num;
}

CheckPower(){  /* For Player to Check Guild Power Level */ 
   string msg;
   if(PowerPoints == 0){
      msg = "Guild Power is GONE"; }
   if(PowerPoints > 0){
      msg = "Guild Power Levels are critical"; }
   if(PowerPoints > 100){
      msg = "Guild Power is very low"; }
   if(PowerPoints > 300){
      msg = "Guild Power is low"; }
   if(PowerPoints > 600){
      msg = "Guild Power is at normal levels"; }
   if(PowerPoints > 1200){
      msg = "Guild Power is in good shape"; }
   if(PowerPoints > 2000){
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
   if(verb == "rsc"){ return Rsc(); }
   if(verb == "ri"){ return Ri(); }
   if(verb == "rwear"){ return Rwear(str); }
   if(verb == "rwield"){ return Rwield(str); }
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
   if(verb == "drt"){ return RangerTalk(verb,"all",str); }
   if(verb == "ranger"){ ranger_help(str); return 1;}
   if(verb == "rwho"){ return RangerWho("all"); }
   if(verb == "drwho"){ return RangerWho("all"); }
   if(verb == "armor"){ COMM->MetallicArmor(); return 1;}
   if(verb == "weapon"){ COMM->PowerWeapon(); return 1;}
   if(verb == "rte"){ return RangerTalk(verb,"all",str); }
   if(verb == "drte"){ return RangerTalk(verb,"all",str); }
   if(verb == "blaster"){ call_blaster(); return 1;}
   if(verb == "zord"){ Zord(); return 1; }
   if(verb == "megazord"){ RangerMegazord(str); return 1; }
}
MartialArtsDef(){
   MartialArtsDef = 1;
   MartialArts =
   (["backflip": ({ 1," does a backflip and dodges ","." }),
         "block":({ 1," blocks the attack of "," with a defensive chop." }), 
         "shiho-nage":({  1," grabs " ,"'s arm and throws them using shiho-nage."  }), 
         "irimi-nage":({ 1," moves toward " ," and throws them with irimi-nage."  }),
         "kaiten-nage":({1," gives " ," a rotary kaiten-nage throw."  }),
         "kote-gaeshi":({  1," grabs " ,"'s wrist and applies kote-gaeshi." }), 
         "ikkyo":({  1," pins " ,"'s arm with ikkyo technique." }), 
         "nikyo":({  1," turns " ,"'s wrist inward with nikyo." }),
         "sankyo":({  1," twists " ,"'s wrist with sankyo." }), 
         "yonkyo":({  1," pins ","'s wrist with yonkyo technique."  }),
         "koshi-nage":({ 2," gives " ," a hip throw using koshi-nage." }),
         "tenchi-nage":({  3," applies a tenchi-nage, heaven and earth throw to ","." }),
         "juji-garami":({  2," entangles and throws " ," with juji-garami." }),
         "aiki-otoshi":({  2," gives " ," an aiki drop using aiki-otoshi." }),
         "sumi-otoshi":({  2," gives " ," a corner drop with applied sumi-otoshi." }),
         "kokyu-nage":({  2," gives " ," an elegant breath throw using your kokyu-nage." }),
         "aiki-nage":({  2," gives " ," an aiki throw using aiki-nage." }),
         "chop":({1," gives "," a chop to the head."}),
         "butterfly":({3," does an artistic butterfly kick to ","."}),
         "laugh":({1," laughs in ","'s face...as cocky as they are."}), 
         "death":({4," reaches out with one finger, and lightly deliver the DEATH TOUCH to ","!"}),
         "slap":({1," slaps "," in the face."}),
         "scratch":({1," scratches ","'s face with their nails."}), 
         "throw":({2," grabs "," and throws them to the floor."}), 
         "press":({3," raises "," up in a gorilla press, and drops them to the ground."}),
         "elbow":({2," turns and bashes "," with the side of the elbow."}),
         "punch":({1," gives "," a solid punch to the chest."}),
         "axe":({2," raises their foot and crashes it down on the shoulder of ","."})]);
}
UseMartialArts(string skill){
   if(!MartialArtsDef)
      MartialArtsDef();
   return MartialArts[skill];
}

