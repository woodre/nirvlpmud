/* Slowly regens a player by 5 hps every other hb while raising 
   intox by 1 pt every other time. Lasts for 30x's
   30 hb's x 5 hps = 150 hps, 1pt(intox) x 15 = 15 total tox
   Cost is supposed to be 3300 - 1/3(heals hps only), but I set
   it at 3000 coins.  I used wockets idea of just using the
   same object instead of desting this one and cloning another
   to handle the regening */

#include "/players/maledicta/ansi.h"

#define USER environment()
int duration;
int used;
int count;
int count2;

id(str){ 
  if(!used) return str == "potion";
  else return str == "nvision_object_mal" || str == "dark_sight_object";
  }

short() { if(!used) return "Potion of "+HIW+"Infravision"+NORM;
          else return; }  
long(){
if(!used)
   write(
"  This small vial holds a few drops of misty liquid which swishes\n"+
"around at the bottom.  You may 'drink infravision' to gain its\n"+
"power.\n");
else return;
 }

query_value(){ if(!used) return 1000; else return 0; }
query_save_flag(){ return 1; }

reset(arg){
  if(arg) return;
  duration = 60;
  }
  
init(){
   add_action("use_kit", "drink");
   }
   
drop(){
 if(USER->query_ghost()){
  remove_call_out("gogogadgestvision");
  destruct(this_object());
  return 1;
  }
 if(used) return 0;
 else return;
 }

use_kit(str){

if(str == "infravision"){
if(environment(this_object()) != this_player()) return 0;
if(present("nvision_object_mal", this_player())){
    write("You are already able to see in the dark!\n");
    return 1;
   }
   used = 1;
   tell_object(USER,
   "You drink the infravision potion...\n");
	tell_room(environment(USER),
   USER->query_name()+" drinks a potion.\n", ({ USER }));
	this_object()->set_weight(0);
   call_out("gogogadgetvision", 1200);
   return 1;
   }	
return;
}

gogogadgetvision(){
      call_other(USER, "recalc_carry");
      tell_object(USER, "The infravision potions wears off...\n");
      destruct(this_object());
      return 1;
      }


get(){ return 1; }
query_weight(){ if(!used) return 1; else return 0; }	
