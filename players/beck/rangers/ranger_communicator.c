/**************************************************************************
* The Power Ranger Communicator (Guild Object)                           *
* Created by Beck/Russ Warren for Nirvana.                               *
* Last changed 2/17/97.                                                  *
**************************************************************************/
string *skills;            /* All power ranger functions, stored as verbs */
string *defense;           /* Power Ranger Defense Skills                 */
string *offense;           /* Power Ranger Offensive Skills               */      
string *quests;            /* Power Ranger Quests Completed               */
string *RangerTypes;
int karate_level;          /* Power Ranger Training level                 */
string old_pretitle;       /* Players set pretitle, stored for safety     */
string old_title;          /* Players real title, stored for safety       */
string ranger_color;       /* Power Ranger chosen color                   */
string ranger_ansi;        /* Power Ranger chosen ANSI color for title    */
string ranger_animal;      /* Power Ranger chosen animal name             */
string ranger_thunderzord; /* Power Ranger chosen thunderzord name        */
string ranger_weapon;      /* Power Ranger chosen weapon name             */
int skill_practice;        /* Total Practice/Experience                   */
int strength;              /* Strength variable modified by Golds Gym     */
int speed;                 /* Speed variable modified by Golds Gym        */
int endurance;             /* Endurance variable modified by Golds Gym    */
static status muffles;     /* Guild Channel Muffles                       */
static status morphed;     /* Morphed Status                              */      
static status need_megazord;/* Status of Calling the Thunder Megazord     */
static status has_thunderzord;/* Status of Calling the Personal Thunderzord*/
static status has_battlezord;/* Status of Calling a Battlezord (pet)      */
static status metal_weapon;/* Power Ranger Metal Weapon Bonus             */
static status metal_armor; /* Power Ranger Metallic Armor Bonus           */
static status ranger_lamp; /* Power Ranger Helmet Light Source            */
id(str) { 
   return str == "communicator" || str == "ranger_communicator" || 
   str == "pro_object" || str == "guild_object" || str == "no_spell" || 
   str == "ranger_object" || str == "notarmor" ||  str == "notweapon";
}
query_combat_method(){ return 2; } 
#include "/players/beck/rangers/defs.h" 
#include "/players/beck/rangers/ranger_weapon.h"
#include "/players/beck/rangers/ranger_armor.h"
#include "/players/beck/rangers/communicator.h"
#include "/players/beck/rangers/practice.h"  
#include "/players/beck/rangers/training.h"

short() {
   string msg;
   if(morphed){
      msg = "";
      if(metal_weapon){ msg = "A Power "+ranger_weapon+"\n"; }
      msg=msg+ "A "+ranger_color+" Power Ranger Suit. (worn)";
      if(metal_armor){ msg = msg + " (metallic)\n"; }
      if(!metal_armor){ msg = msg+"\n"; }
      msg = msg +"A "+ranger_color+" Power Ranger Helmet. (worn)";
      if(ranger_lamp){ msg = msg +" (lit)\n"; }
      if(!ranger_lamp){ msg = msg +"\n"; }
      msg = msg +""+ranger_color+" Power Ranger Boots. (worn)\n"+
      ranger_color+" Power Ranger Gloves. (worn)\n";
      msg = msg+"A Power Ranger Coin.\n"+"A Power Ranger Communicator";
   }
   if(!morphed){
      msg = "A Power Ranger Morpher.\n"+"A Power Ranger Communicator";
   }
   return msg;
}

void long() {
   write(
      "This communicator is made with a steel case, and has a fine quartz crystal.\n"+
      "Looking closer you see little blinking lights all over the communicator.\n"+
      "Type 'ranger' for more information.\n"+
      "");
}

extra_look(){
   string msg;
   if(karate_level == 0){ return; }
   if(karate_level == 1){ msg = "has knowledge of basic martial art skills";}
   if(karate_level == 2){ msg = "has a White belt in the martial arts";}
   if(karate_level == 3){ msg = "has a Yellow belt in the martial arts";}
   if(karate_level == 4){ msg = "has an Orange belt in the martial arts";}
   if(karate_level == 5){ msg = "has a Red belt in the martial arts";}
   if(karate_level == 6){ msg = "has a Green belt in the martial arts";}
   if(karate_level == 7){ msg = "has a Blue belt in the martial arts";}
   if(karate_level == 8){ msg = "has a Purple belt in the martial arts";}
   if(karate_level == 9){ msg = "has a Brown belt in the martial arts";}
   if(karate_level >= 10){ msg = "has a Black belt in the martial arts";}
   return capitalize(ENV->query_real_name())+" "+msg;
}

query_auto_load(){ return "/players/beck/rangers/ranger_communicator:";}

init_arg() {
   if(restore_object(RANGERDIR+this_player()->query_real_name()))
{
      write("Setting your Power Levels...\n");
}
   else { save_ranger(); }
   return;
}

void init(){
   int i;
   string skill;
   if(ENV){
      if(ENV->is_player()){
         if(this_player()->query_level() < 20){
            this_player()->set_guild_name("rangers");
            call_other(this_player(),"set_home","/players/beck/room/headqtr.c");
            if(!morphed){
               this_player()->set_title(old_title);
               this_player()->set_pretitle(old_pretitle);
            }
            set_class(6);
            set_ac(3);
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
      }
   }
   add_action("check_ranger_kill","kill");
   add_action("quit","quit");
   add_action("muff_on","rtm");
   for (i=0; i<sizeof(skills); i++){
      skill = skills[i];
      add_action("ranger_power",skill);
   }
}

void save_ranger(){ save_object(RANGERDIR+ENV->query_real_name()); }

void restore_ranger(){restore_object(RANGERDIR+ENV->query_real_name());}

get(){ return 1;}
drop(){ return 1;}

ranger_power(str){ MASTER->ranger_power(str); return 1;}

quit() { command("unmorph", this_player()); save_ranger(); return; }

