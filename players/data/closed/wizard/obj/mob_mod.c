#include "/players/maledicta/ansi.h"

get(){ return 1; }
drop(){ return 1; }

query_weight(){ return 0; }
query_value(){ return 0; }

int owc;
int oac;
int wc;
int ac;
int duration;

originals(){ 
 owc = environment()->query_wc(); 
 oac = environment()->query_ac();
 }
             
wc_mod(){ 
  duration += 6;
  environment()->set_wc(environment()->query_wc() - 1);
  } 
      
ac_mod(){ 
  duration += 6; 
  environment()->set_ac(environment()->query_ac() - 1);
  }

reset(){ 
  duration = 6;
  set_heart_beat(1);  
  }

id(str){ return str == "acwc_modifier"; }

heart_beat(){
 if(!environment()) return;
 if(!living(environment())){ destruct(this_object()); }
 if(duration) duration -= 1;
 if(!duration){
  environment()->set_wc(owc);
  environment()->set_ac(oac);
  tell_room(environment(environment()),
  environment()->query_name()+" seems to recover.\n"); 
  destruct(this_object());
  }
 }

