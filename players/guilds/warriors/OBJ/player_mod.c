#include "/players/maledicta/ansi.h"

get(){ return 1; }
drop(){ return 1; }

query_weight(){ return 0; }
query_value(){ return 0; }

int wc;
int ac;
int duration;

add_wc_mod(int i){ wc += i; if(wc > 5) wc = 5; duration += 6; }
add_ac_mod(int i){ ac += i; if(ac > 5) ac = 5; duration += 6; }

reset(){ 
  duration = 6;
  set_heart_beat(1);  
  }

id(str){ return str == "wc_mod" || str == "generic_wc_bonus" ||
                str == "damage_report_object" || str == "acwc_modifier"; }

gen_wc_bonus(){
  return -wc; 
  }

report_damage(int total, object po){
int loop;
if(loop) return;
if(!po) return;
if(total < ac) return;
if(environment()->query_hp() < ac) return;
if(ac == 0) return;
environment()->add_hit_point(-ac);
loop = 1;
}

heart_beat(){
 if(!environment()) return;
 if(!living(environment())){ destruct(this_object()); }
 if(duration) duration -= 1;
 if(!duration){
  tell_room(environment(environment()),
  environment()->query_name()+" seems to recover.\n"); 
  destruct(this_object());
  }
 }

