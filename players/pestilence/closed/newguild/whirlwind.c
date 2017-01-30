#include "/players/snow/dervish/def.h"
inherit "/obj/armor.c";
int time;

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_ac(0);
  set_silently(1); 
  set_id(WHIRLWIND);
  set_type(WHIRLWIND);
}


extra_look(){
    if(environment() == this_player())
      write("You are surrounded by a giant "+BOLD+RED+"Whirlwind"+OFF+" of "+BOLD+RED+"Sand"+OFF+".\n");
    else
      write(environment()->query_name() + " is surrounded by a giant "+BOLD+RED+"Whirlwind"+OFF+" of "+BOLD+RED+"Sand"+OFF+".\n");
}

do_special(owner){
  if(owner->query_attack())
  if(random(30) < environment(this_object())->query_level()){
    tell_object(owner,"The giant "+BOLD+RED+"Whirlwind"+OFF+" whips around your body deflecting part of the blow.\n");
    tell_object(owner->query_attack(),"A giant "+BOLD+RED+"Whirlwind"+OFF+" whips around "+owner->query_name()+" and deflected your blow.\n");
    return (2+random(5));
  }
}

init(){
if(environment()){
if(!environment(this_object())->is_player()){ blah(); return; }
  ::init();
  if(!"dknight_ob"){ destruct(this_object()); return 1; }
  wear("derv_whirlwind"); 
  }
 }




blah(){
  if(environment(this_object())){
    if(environment(environment(this_object())))
  tell_room(environment(environment(this_object())),BOLD+RED+"The Whirlwind dissipates from around "+capitalize(environment()->query_name())+"'s body.\n"+OFF);
    else
  tell_room(environment(this_object()),BOLD+RED+"The Whirlwind dissipates from around your body.\n"+OFF);
  }
  remove("derv_whirlwind");
  destruct(this_object());
}

set_time(amt){
  time = 9*amt;
  call_out("blah", time); 
  }
  
drop(){ return 1; }
