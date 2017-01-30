#include "/players/wocket/closed/ansi.h"
object wep;
int bloodcount;
int hitcount;

set_bloodshadow(object obj){
wep = obj;
shadow(wep,1);
}

remove_bloodshadow(){
  shadow(wep,0);
  destruct(this_object());
  return 1;
}

query_bloodcount(){ return bloodcount; }

add_bloodcount(){
  bloodcount++;
  if(bloodcount > 4){
    write("The blood eats away at the "+wep->short()+".\n");
    wep->weapon_breaks();
    remove_bloodshadow();
}
}

hit(attacker){
  if(attacker->query_sinjaworm()){
   write("Pojoui blood seeps into the wounds of the Sinja worm....\n"+
       HIR+"\n          MASSIVE DESTRUCTION ERRUPTS \n\n"+NORM+
         "as the blood rips through the interal organs of the Sinja worm...\n");
    attacker->heal_self(-(100*bloodcount));
    attacker->set_heal(0,100000000);
    attacker->set_ac(40/bloodcount);
    attacker->set_wc(30+(40/bloodcount));
  } 
  if(random(20) < bloodcount){
    write(RED+"The blood of the pojoui burns deep into "+attacker->query_name()+".\n"+NORM);
    tell_object(attacker,RED+"You are burned by your opponents weapon.\n"+NORM);
    attacker->heal_self(-1-random(bloodcount));
    hitcount++;
  }
if(hitcount > 100){
  write("The blood eats away at the "+wep->short()+".\n");
    wep->weapon_breaks();
    remove_bloodshadow();
}
  if(wep->query_hit_func())
     return call_other(wep,"weapon_hit",attacker);
return 0;
}


long(){ wep->long(); write(RED+"It is covered in pojoui blood.\n"+NORM);}
query_save_flag(){ return 1; }
