/**************************************************************************
* The Power Ranger Communicator (Guild Object)                            *
* Created by Beck/Russ Warren for Nirvana.                                *
* Last changed 02/07/99.                                                  *
**************************************************************************/

int SkillPoint;
int NextSkillCost;
int BuildPoint;
 
mapping Skills;

mixed *SkillsSaved;

string OldPretitle;       
string OldTitle;          
string RangerColor;            /* Color Name                    */
string RangerDino;
string RangerAnimal;
string RangerWeapon;     
string RangerNumber; 
string RangerAlign;
string RangerAnsi;
string RangerHome;

static int Morphed;
static int Muffles;

static mixed *TempVars;
static string *GeneralSkills;
static string *OffSkills;
static string *DefSkills;

id(str){ 
   return str == "communicator" || str == "RangerCommunicator" || 
   str == "pro_object" || str == "guild_object" || str == "no_spell" || 
   str == "ranger_object" || str == "channel_object"; 
}

query_name(){ return "Power Ranger Communicator"; }


query_combat_method(){ return 2; }

#include "/players/beck/Defs.h"



#include "/players/beck/RangersNew/RangerDefs.h" 
#include "CommInc/RangerWeapon.h"
#include "CommInc/RangerArmor.h"
#include "CommInc/Train.h"
#include "CommInc/Communicator.h"
/*
#include "CommInc/Gym.h"
#include "CommInc/RangerPack.h"

*/


#include "CommInc/SkillMapping.h"

short() {
   string msg;
/*
   if(Morphed){
      msg = PowerWeapon ? "A Power "+RangerWeapon+"\n" : "";
      msg += RangerPack ? "A "+RangerColor+" Power Pack. (worn)\n": "";
      msg += "A "+RangerColor+" "+RangerAlign+" Suit. (worn)";
      msg += MetallicArmor ? " (metallic)\n" : "\n"; 
      msg += "A "+RangerColor+" "+RangerAlign+" Helmet. (worn)";
      msg += HelmetLamp ? " (lit)\n" : "\n"; 
      msg = msg +""+RangerColor+" "+RangerAlign+" Boots. (worn)\n"+
      RangerColor+" "+RangerAlign+" Gloves. (worn)\n";
      msg = msg+"A "+RangerAlign+" Coin.\n"+"A "+RangerAlign+" Communicator";
   }
   else {
      if(ENVOB->GLEVEL > 9){
         msg = "A "+RangerAlign+" Morpher.\n"+"A "+RangerAlign+" Communicator";
      }
      else{
         msg = "A "+RangerAlign+" Communicator";
      }
   }
*/
msg = "Ranger Comm";
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

query_auto_load(){ return AUTOLOAD; }



init_arg() {
   

   int i;

   if(restore_object(RANGERDIR+TPRNAME)){
      write("Setting your Power Levels...\n");
   }
   else { SaveRanger(); }
   
   if(TP->is_player() && TP == this_player() && !TP->is_kid()){
      if(TP->query_level() < 20){

         if(!RangerAlign)
               RangerAlign = "Power Ranger";
        
         if(!RangerHome)
               RangerHome = "/players/beck/Rangers/CommandCenter/CommandCenter.c";
       
         if(RangerAlign == "Power Ranger")
            TP->set_guild_name("rangers");

         if(TP->query_guild_name() == "rangers"){
            call_other(TP,"set_home",RangerHome);
         }

         RestoreSkillsSaved();
         
         if(!Morphed){
            TP->set_title(OldTitle);
            TP->set_pretitle(OldPretitle);
         }

         if(!RangerAnsi)
            RangerAnsi = OFF;

         set_class(0);
         wielded_by = TP;
         TP->wield(TO,1);
         wielded = 1;

         set_ac(0);
         set_weight(8);
         set_type("armor");
         call_other(TP, "wear", this_object(), 1, "armor", ({"physical",0,0,"shield_bonus"}));
         worn_by = TP;
         worn = 1;


      }
   }

   if(TP->RangerNPC()){
      for (i=0; i<sizeof(Skills); i++){
         add_action("RangerPower",Skills[i]);
      }
      if(!RangerAnsi)
         RangerAnsi = "";
      set_class(10);
      set_ac(3);
      set_weight(8);
      set_type("armor");
      call_other(TP, "wear", this_object(), 1, "armor", ({"physical",3,0,"shield_bonus"}));

      worn_by = TP;
      wielded_by = TP;
      call_other(TP, "wield", this_object());
      worn = 1;
      wielded = 1;

   }
  
   CHANNEL->AddChannel(RangerAlign,TO);
   return;

}


void init(){
   int i;
  


   if(ENVOB){
      if(ENVOB->is_player() && ENVOB == this_player() && !TP->is_kid()){
         if(ENVOB->query_level() > 19){
            write("Wizards may not have this object!!!\n"+
               "Clone HonorRangerCommunicator instead\n");
            destruct(this_object());
         }
         /*carry_weight();*/
         add_action("Spam","spam");
         add_action("TrainRanger1_5","rangertrainfinal");
         add_action("check_ranger_kill","kill");
         add_action("quit","quit");
         add_action("inactive","inactive");
         add_action("Muffles","rtm");


    
         

         for (i=0; i<sizeof(SKILLS); i++){
            
            add_action("RangerPower",SKILLS[i]);
         }

      }
   }
}

void SaveRanger(){ save_object(RANGERDIR+ENVOB->query_real_name()); }

void restore_ranger(){restore_object(RANGERDIR+ENVOB->query_real_name());}

get(){ return 1;}
drop(){ 
   
   return 1;
}



RangerPower(str){ 
   string verb;
   int skill_level;
   string wizard_name;
   string *Filenamee;

   verb = query_verb();
   
   skill_level = QuerySkillLevel(verb);

   wizard_name = QuerySkillWiz(verb);

   if(!wizard_name)
      wizard_name = "beck";
   
   
   Filenamee = files("/players/"+wizard_name+"/Rangers/Commands/*.c");

   verb = capitalize(verb)+".c";

   if(TP->is_npc())
      Filenamee = ({"Aid.c","Teleport.c","Rt.c","Rte.c","Morph.c"});

   if(member_array(verb, Filenamee) != -1){
      verb = "/players/"+wizard_name+"/Rangers/Commands/"+capitalize(query_verb())+"";
      verb->RangerPower(str,RangerAlign);
   }
   else
      MASTER->RangerPower(str,RangerAlign); 

  return 1;
}



quit(){
   CHANNEL->RemoveChannel(RangerAlign,TO);
   SaveSkillsSaved();
   SaveRanger();
   return;
}


