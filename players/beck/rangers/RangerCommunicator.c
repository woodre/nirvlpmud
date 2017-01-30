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

id(str){ 
   return str == "communicator" || str == "RangerCommunicator" || 
   str == "pro_object" || str == "guild_object" || str == "no_spell" || 
   str == "ranger_object" || str == "notarmor" ||  str == "notweapon";
}
query_combat_method(){ return 2; }

#include "/players/beck/rangers/Defs.h" 
#include "/players/beck/rangers/RangerWeapon.h"
#include "/players/beck/rangers/RangerArmor.h"
#include "/players/beck/rangers/Communicator.h"
#include "/players/beck/rangers/Training.h"
#include "/players/beck/rangers/Gym.h"

short() {
   string msg;
   if(Morphed){
      msg = "";
      if(PowerWeapon){ msg = "A Power "+RangerWeapon+"\n"; }
      msg=msg+ "A "+RangerColor+" Power Ranger Suit. (worn)";
      if(MetallicArmor){ msg = msg + " (metallic)\n"; }
      if(!MetallicArmor){ msg = msg+"\n"; }
      msg = msg +"A "+RangerColor+" Power Ranger Helmet. (worn)";
      if(HelmetLamp){ msg = msg +" (lit)\n"; }
      if(!HelmetLamp){ msg = msg +"\n"; }
      msg = msg +""+RangerColor+" Power Ranger Boots. (worn)\n"+
      RangerColor+" Power Ranger Gloves. (worn)\n";
      msg = msg+"A Power Ranger Coin.\n"+"A Power Ranger Communicator";
   }
   if(!Morphed){
      if(ENVOB->GLEVEL > 9){
         msg = "A Power Ranger Morpher.\n"+"A Power Ranger Communicator";
      }
      if(ENVOB->GLEVEL < 10){
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
   if(KarateLevel == 1){ msg = "has a White belt in the martial arts";}
   if(KarateLevel == 2){ msg = "has a Yellow belt in the martial arts";}
   if(KarateLevel == 3){ msg = "has an Orange belt in the martial arts";}
   if(KarateLevel == 4){ msg = "has a Red belt in the martial arts";}
   if(KarateLevel == 5){ msg = "has a Green belt in the martial arts";}
   if(KarateLevel == 6){ msg = "has a Blue belt in the martial arts";}
   if(KarateLevel == 7){ msg = "has a Purple belt in the martial arts";}
   if(KarateLevel == 8){ msg = "has a Brown belt in the martial arts";}
   if(KarateLevel >= 9){ msg = "has a Black belt in the martial arts";}
   return capitalize(ENVOB->query_real_name())+" "+msg;
}

query_auto_load(){ return "/players/beck/Rangers/RangerCommunicator:";}

init_arg() {
   if(restore_object(RANGERDIR+NAME))
      {
      write("Setting your Power Levels...\n");
write("\n\n\nLog out and back in for new guild object\n\n\n");
   }
   else { save_ranger(); }
   return;
}

void init(){
   int i;
   string skill;
   if(ENVOB){
      if(ENVOB->is_player() && ENVOB == this_player() && !TP->is_kid()){
         if(this_player()->query_level() < 20){
            this_player()->set_guild_name(GUILDNAME);
            call_other(this_player(),"set_home","/players/beck/room/headqtr.c");
            if(!Morphed){
               this_player()->set_title(OldTitle);
               this_player()->set_pretitle(OldPretitle);
            }
            set_class(0);
            set_ac(0);
            set_weight(8);
            set_type("armor");
            message_hit=({"massacre"," to small fragments","smashed"," with a bone crushing sound","hit"," very hard","hit"," hard","hit","","grazed","","tickled"," in the stomach"});  
            call_other(this_player(), "wear", this_object());
            worn_by = this_player();
            worn = 1;
            wielded_by = this_player();
            call_other(this_player(), "wield", this_object());
            wielded = 1;
         }
         if(ENVOB->query_level() > 19){
            write("Wizards may not have this object!!!\n"+
               "Clone HonorRangerCommunicator instead\n");
            destruct(this_object());
         }
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
      if(ENVOB->RangerNPC()){
         for (i=0; i<sizeof(Skills); i++){
            skill = Skills[i];
            add_action("RangerPower",skill);
         }
         set_class(10);
         set_ac(3);
         set_weight(8);
         set_type("armor");
         message_hit=({"massacre"," to small fragments","smashed"," with a bone crushing sound","hit"," very hard","hit"," hard","hit","","grazed","","tickled"," in the stomach"});  
         
         call_other(ENVOB, "wear", this_object());
         worn_by = ENVOB;
         wielded_by = ENVOB;
         call_other(ENVOB, "wield", this_object());
         worn = 1;
         wielded = 1;
      }
      MASTER->AddRanger("all",ENVOB);
   }
}

void SaveRanger(){ save_object(RANGERDIR+ENVOB->query_real_name());
   save_object("players/beck/Rangers/Save/"+ENVOB->query_real_name());
}

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

