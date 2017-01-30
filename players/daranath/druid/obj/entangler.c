#include <ansi.h>

int limit;

drop(){ return 1; }
get(){ return 1; }
id(str){ return str == "stun_object_prof"; }

query_value(){ return 0; }
query_weight(){ return 0; }

reset(){
	call_out("end_it", 2);
}


end_it(){
remove_call_out("end_it");

if(!environment()){ destruct(this_object()); return 1; }
if(!living(environment())){ destruct(this_object()); return 1; }
if(limit > 10 && random(10) < 4){
  tell_object(environment(), "You recover from the charge.\n");
  tell_room(environment(environment()), 
  environment()->query_name()+" recovers from the charge.\n", ({ environment() }));
  destruct(this_object());
  return 1; 
  }

if(!random(2)){
tell_object(environment(), 
"You feel shaken and weak...\n");
}
else{
tell_object(environment(),
"You attempt to recover from the charge but fail...\n");
}
tell_room(environment(environment()),
environment()->query_name()+" looks shaken and weak...\n", ({ environment() }));
limit += 1;
call_out("end_it", random(3) + 2);
}
