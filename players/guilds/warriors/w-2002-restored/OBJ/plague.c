#include "/players/maledicta/ansi.h"

int power;
int duration;

get(){ return 1; }
drop(){ return 1; }

query_weight(){ return 0; }
query_value(){ return 0; }

set_duration(int i){ duration = i; }
query_duration(){ return duration; }
add_duration(int i){ duration += i; }

set_power(int i){ power = i; }
query_power(){ return power; }

reset(){ 
  set_heart_beat(1);  
  }

id(str){ return str == "plague_woot"; }

heart_beat(){
 if(!environment()) return;
 if(!living(environment())){ destruct(this_object()); }
 if(duration) duration -= 1;
 environment()->heal_self(-(random(power) + 1));
 if(!duration){
  tell_room(environment(environment()),
  environment()->query_name()+" recovers from plague.\n"); 
  destruct(this_object());
  }
 }

