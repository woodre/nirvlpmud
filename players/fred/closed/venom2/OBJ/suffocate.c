#include "/players/maledicta/ansi.h"

object who;

drop(){ return 1; }

id(str){ return str == "suffocate_object_venom"; }

query_value(){ return 0; }
query_weight(){ return 0; }

init(){
      if(environment()){
        if(living(environment())){
	call_out("hurt_them", 1);
        }
      }
   }

set_who(ob){ who = ob; }
query_who(){ return who; }

hurt_them(){
	int damage;
	if(!environment()) return;
	if(!living(environment())){ destruct(this_object()); return 1; }
		if((environment()->query_hp()*10)/(environment()->query_mhp()) > 3){
	      tell_room(environment(environment()),
            environment()->query_name()+" shrugs off the tentacle suffocating it!\n");
       	destruct(this_object());
		return 1;
      	}
      if(!present(who, environment(environment()))){
           destruct(this_object());
           return 1;
           }
      if(!environment()->query_attack()){
          tell_room(environment(environment()),
          environment()->query_name()+" yanks the tentacle out of its throat!\n");
          destruct(this_object());
          return 1;
          }
      if(environment()->query_hp() < 6){
        environment()->heal_self(-6);
        }
        damage = random(6) + 4;
      if(!random(3))
      tell_room(environment(environment()),
      environment()->query_name()+" gags as the tentacle burrows deeper down their throat!\n",({ environment() }));
	environment()->heal_self(-damage);
	remove_call_out("hurt_them");
	call_out("hurt_them", 2);
}
