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
  else return str == "regen_object_mal";
  }

short() { if(!used) return "Potion of "+HIY+"Regeneration"+NORM;
          else return; }  
long(){
if(!used)
   write(
" This potion holds a bright yellow liquid that will slowly\n"+
"regenerate your wounds. All you need to do to activate this\n"+
"potion is 'drink potion of regeneration'.\n");
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
 if(used) return 0;
 else return;
 }

use_kit(str){

if(str == "potion of regeneration"){
if(environment(this_object()) != this_player()) return 0;
if(present("regen_object_mal", this_player())){
    write("You are already regenerating!\n");
    return 1;
    }
      used = 1;
      count = 1;
      set_heart_beat(1);
      tell_object(USER,
      "You drink the regeneration potion...\n");
	tell_room(environment(USER),
      USER->query_name()+" drinks a potion.\n", ({ USER }));
	this_object()->set_weight(0);
   return 1;
   }	
return;
}

heart_beat(){
  if(environment()->query_ghost()){
      call_other(USER, "recalc_carry");
      destruct(this_object());
      return 1;
      }
  if(!duration){
      call_other(USER, "recalc_carry");
      tell_object(USER, "The regeneration ends...\n");
      destruct(this_object());
      return 1;
      }
  count++;
  count2++;
  if(count == 2){
   if(USER->query_intoxination() > USER->query_level()+3){
    tell_object(USER, "You feel that your body cannot handle the regeneration...\n");
    }
   else{
   tell_object(USER, "You feel a healing energy flow through your veins...\n");
   USER->add_hit_point(5);
   if(count2 == 4){
    USER->drink_alcohol(1);
    count2 = 0;
    }   
   }
  count = 0;
  }   
duration -= 1;
}


get(){ return 1; }
query_weight(){ if(!used) return 1; else return 0; }	
