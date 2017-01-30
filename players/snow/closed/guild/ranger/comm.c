/**************************************************************************
* The Power Ranger Communicator (Guild Object)                           *
* Created by Beck/Russ Warren for Nirvana.                               *
* Last changed 12/17/97.                                                  *
**************************************************************************/
string *RangerTypes;
string *UnlearnedSkills;
string *Skills;            
string *Defense;           
string *Offense;           
int KarateLevel; 
int KarateExtraLevel;         
int RangerCombatExp;
int RangerMartialArtsExp;
int RangerSkillExp;
int RangerStrength;
int RangerSpeed;
int RangerEndurance;
string OldPretitle;       
string OldTitle;          
string RangerColor;       
string RangerDino;
string RangerAnimal;
string RangerWeapon;     
string RangerNumber;
string KarateDegree;
static status Muffles;     
static status Morphed;
static status Ninja;    
static status Zord; 
static status PowerWeapon;
static status MetallicArmor; 
static status HelmetLamp; 
static int RangerStrengthTemp;
static int RangerSpeedTemp;
static int RangerEnduranceTemp;
static int RangerMartialArtsExpTemp;
static status Spam;
int AutoGenLimit;
status AutoGen;
int AutoGenAmount;
static string NotArmor;
static string NotWeapon;
static object Weapon;

id(str){ 
   return str == "communicator" || str == "RangerCommunicator" || 
   str == "pro_object" || str == "guild_object" || str == "no_spell" || 
   str == "ranger_object" || str == NotArmor ||  str == NotWeapon;
}
query_combat_method(){ return 2; }

#include "/players/beck/Defs.h"
#include "/players/beck/Rangers/RangerDefs.h" 
#include "CommInc/RangerArmor.h"
#include "CommInc/RangerWeapon.h"
#include "CommInc/Communicator.h"
#include "CommInc/Training.h"
#include "CommInc/Gym.h"

short() {
   string msg;
   if(Morphed){
      msg = PowerWeapon ? "A Power "+RangerWeapon+"\n" : "";
      msg += "A "+RangerColor+" Power Ranger Suit. (worn)";
      msg += MetallicArmor ? " (metallic)\n" : "\n"; 
      msg += "A "+RangerColor+" Power Ranger Helmet. (worn)";
      msg += HelmetLamp ? " (lit)\n" : "\n"; 
      msg = msg +""+RangerColor+" Power Ranger Boots. (worn)\n"+
      RangerColor+" Power Ranger Gloves. (worn)\n";
      msg = msg+"A Power Ranger Coin.\n"+"A Power Ranger Communicator";
   }
   else {
      if(ENVOB->GLEVEL > 9){
         msg = "A Power Ranger Morpher.\n"+"A Power Ranger Communicator";
      }
      else{
         msg = "A Power Ranger Communicator";
      }
   }
   return msg;
}

void long() {
   write(
      "This communicator is made with a steel case,"+
      " and has a fine quartz crystal.\n"+
      "Looking closer you see little blinking lights\n"+
      "all over the communicator.\n"+
      "Type 'ranger' for more information.\n"+
      "");
}

extra_look(){
   string msg;
   if(KarateLevel == 0){ return; }
   else if(KarateLevel == 1){ msg = "has a White belt in the martial arts";}
   else if(KarateLevel == 2){ msg = "has a Yellow belt in the martial arts";}
   else if(KarateLevel == 3){ msg = "has an Orange belt in the martial arts";}
   else if(KarateLevel == 4){ msg = "has a Red belt in the martial arts";}
   else if(KarateLevel == 5){ msg = "has a Green belt in the martial arts";}
   else if(KarateLevel == 6){ msg = "has a Blue belt in the martial arts";}
   else if(KarateLevel == 7){ msg = "has a Purple belt in the martial arts";}
   else if(KarateLevel == 8){ msg = "has a Brown belt in the martial arts";}
   else if(KarateLevel == 9){ msg = "has a ";
      if(KarateExtraLevel > 0){ msg += "<"+KarateDegree+">"; }
      msg += " Black belt in the martial arts";
   }
   return capitalize(ENVOB->query_real_name())+" "+msg;
}

query_auto_load(){ return AUTOLOAD; }

init_arg() {
   int i;
   string skill;
   if(restore_object(RANGERDIR+TPRNAME)){
      write("Setting your Power Levels...\n");
   }
   else { save_ranger(); }
   if(TP->is_player() && TP == this_player() && !TP->is_kid()){
      if(TP->query_level() < 20){
         TP->set_guild_name(GUILDNAME);
         call_other(TP,"set_home","/players/beck/room/headqtr.c");
         if(!Morphed){
            TP->set_title(OldTitle);
            TP->set_pretitle(OldPretitle);
         }
         NotArmor = "notarmor";
         NotWeapon = "notweapon";
         set_class(0);
         set_ac(0);
         set_weight(8);
         set_type("armor");
         call_other(TP, "wear", this_object());
         worn_by = TP;
         worn = 1;
         wielded_by = TP;
         TP->wield(TO,1);
         wielded = 1;
      }
   }
   if(TP->RangerNPC()){
      for (i=0; i<sizeof(Skills); i++){
         skill = Skills[i];
         add_action("RangerPower",skill);
      }
      set_class(10);
      set_ac(3);
      set_weight(8);
      set_type("armor");
      call_other(TP, "wear", this_object());
      worn_by = TP;
      wielded_by = TP;
      call_other(TP, "wield", this_object());
      worn = 1;
      wielded = 1;
   }
   MASTER->AddRanger("all",TP);
   
   return;
}

void init(){
   int i;
   string skill;
   if(ENVOB){
      if(ENVOB->is_player() && ENVOB == this_player() && !TP->is_kid()){
         if(ENVOB->query_level() > 19){
            write("Wizards may not have this object!!!\n"+
               "Clone HonorRangerCommunicator instead\n");
            destruct(this_object());
         }
         add_action("Spam","spam");
         add_action("TrainRanger1_5","rangertrainfinal");
         add_action("check_ranger_kill","kill");
         add_action("quit","quit");
         add_action("inactive","inactive");
         add_action("Muffles","rtm");
         for (i=0; i<sizeof(Skills); i++){
            skill = Skills[i];
            add_action("RangerPower",skill);
         }
      }
   }
}

void SaveRanger(){ save_object(RANGERDIR+ENVOB->query_real_name()); }

void restore_ranger(){restore_object(RANGERDIR+ENVOB->query_real_name());}

get(){ return 1;}
drop(){ return 1;}

RangerPower(str){ MASTER->RangerPower(str); return 1;}

quit(){
   if(Morphed){
      MASTER->UnmorphRanger();
      if(Zord)
         command("release", this_player());
   }
   MASTER->RemoveRanger("all",ENVOB);
   SaveRanger();
   return;
}

inactive(){
   write("Power Rangers are not allowed to become inactive\n"+
      "as this is unfair to those who are active and to those who\n"+
      "would like to join.  If you are not planning on playing,\n"+
      "please leave the guild.\n");
   return 1;
}

