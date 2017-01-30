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

mapping ac_mod;
mapping wc_mod;

originals(){ 
 owc = environment()->query_wc(); 
 oac = environment()->query_ac();
 }
             
wc_mod(){ 
  object ob;
  ob = environment(this_object());
  duration += 6;
  if(!wc_mod)
    wc_mod = ([]);
  if(wc_mod[ob])
  {
    wc_mod[ob]--;
  }
  else
  {
    wc_mod[ob]-=1;
  }
  ob->RegisterWeapon(this_object(), ({"physical",wc_mod[ob],0}));
  } 
      
ac_mod(){ 
  object ob;
  ob = environment(this_object());
  duration += 6;
  if(!ac_mod)
    ac_mod = ([]);
  if(ac_mod[ob])
  {
    ac_mod[ob]--;
  }
  else
  {
    ac_mod[ob]-=1;
  } 
  ob->RegisterArmor(this_object(), ({"physical",ac_mod[ob],0,0}));
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

no_exp_effect(){ return 1; }