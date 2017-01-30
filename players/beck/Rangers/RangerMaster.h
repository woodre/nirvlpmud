/************************************************************************   
*  The Power Ranger Master Guild Object                                *
*  Created by Beck/Russ Warren for Nirvana.                            *
*  Last Changed 12/15/97.                                               *
************************************************************************/

string cmds;

mapping MartialArts;
status MartialArtsDef;
#include "/players/beck/Rangers/MasterInc/CreateMonster.h"
#include "/players/beck/Rangers/RangerDefs.h"
#include "/players/beck/Rangers/MasterInc/PowerPoints.h"
#include "/players/beck/Rangers/MasterInc/Blast.h"
#include "/players/beck/Rangers/MasterInc/TrainingMessage.h"
#include "/players/beck/Rangers/MasterInc/Ri.h"
#include "/players/beck/Rangers/MasterInc/Rwear.h"
#include "/players/beck/Rangers/MasterInc/Rwield.h"
#include "/players/beck/Rangers/MasterInc/Aid.h"
#include "/players/beck/Rangers/MasterInc/Donate.h"
#include "/players/beck/Rangers/MasterInc/Lead.h"
#include "/players/beck/Rangers/MasterInc/Practice.h"
#include "/players/beck/Rangers/MasterInc/Study.h"
#include "/players/beck/Rangers/MasterInc/Blaster.h"
#include "/players/beck/Rangers/MasterInc/Jet.h"
#include "/players/beck/Rangers/MasterInc/Time.h"
#include "/players/beck/Rangers/MasterInc/Help.h"
#include "/players/beck/Rangers/MasterInc/Unmorph.h"
#include "/players/beck/Rangers/MasterInc/Ninja.h"
#include "/players/beck/Rangers/MasterInc/Zord.h"
#include "/players/beck/Rangers/MasterInc/Teach.h"


RangerPower(str,string type){
   string verb;
   verb = query_verb();
   if(verb == "ansi"){ return RangerAnsi(str); }
   if(verb == "blast"){ return Blast(type); }
   if(verb == "parry"){ return COMM->RangerTactic("parry"); }
   if(verb == "wolfpack"){ return COMM->RangerTactic("wolfpack"); }
   if(verb == "pack"){ return COMM->RangerPack(type); }
   if(verb == "autogen"){ COMM->AutoGenerate(str); return 1; }
   if(verb == "rsc"){ return Rsc(type); }
   if(verb == "ri"){ return Ri(str); }
   if(verb == "rwear"){ return Rwear(str,type); }
   if(verb == "rwield"){ return Rwield(str,type); }
   if(verb == "aid"){ AidRanger(str,type); return 1;}
   if(verb == "ninja"){ MorphNinja(type); return 1;}
   if(verb == "teach"){ TeachRanger(str); return 1; }
   if(verb == "lead"){ lead_battle(type); return 1;}
   if(verb == "skills"){ COMM->SeeSkills(); return 1; }
   if(verb == "offense"){ COMM->SeeOffense(); return 1;}
   if(verb == "defense"){ COMM->SeeDefense(); return 1;}
   if(verb == "study"){ study_enemy(str); return 1;}
   if(verb == "lamp"){ COMM->SHelmetLamp(); return 1;}
   if(verb == "morph"){ MorphRanger(type); return 1;}
   if(verb == "unmorph"){ UnmorphRanger(); return 1;}
   if(verb == "jet"){ ranger_jet(str); return 1; }
   if(verb == "practice"){ practice_arts(str); return 1;}
   if(verb == "power"){ CheckPower(type); return 1;}
   if(verb == "generate"){ GeneratePower(str,type); return 1;}
   if(verb == "donate"){ ranger_blast(str,type); return 1;}
   if(verb == "time"){ check_time(); return 1;}
   if(verb == "teleport"){ teleport_ranger(str,type); return 1;}
   if(verb == "rt"){ return RangerTalk(verb,type,str); }
   if(verb == "ranger"){ ranger_help(str); return 1;}
   if(verb == "rwho"){ return RangerWho(type); }
   if(verb == "armor"){ COMM->MetallicArmor(); return 1;}
   if(verb == "weapon"){ COMM->PowerWeapon(); return 1;}
   if(verb == "rte"){ return RangerTalk(verb,type,str); }
   if(verb == "blaster"){ call_blaster(type); return 1;}
   if(verb == "zord"){ Zord(type); return 1; }
   if(verb == "megazord"){ RangerMegazord(str,type); return 1; }
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
         "tenchi-nage":({  2," applies a tenchi-nage, heaven and earth throw to ","." }),
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

