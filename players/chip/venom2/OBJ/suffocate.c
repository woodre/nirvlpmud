/* Now does up to 20 damage maximum as opposed to the previous 10 damage maximum. Balance purposes -Chip(4-15-09) */
#include "/players/chip/ansi.h"

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
      if(environment()->query_hp() < 8){
        environment()->heal_self(-25);  /* changed from heal_self(-8) -Chip(4-17-09)*/
        }
        damage = random(24) + 12;  /* up from damage = random(8) + 4; -Chip(4-17-09)*/
      if(!random(3))
      tell_room(environment(environment()),
      environment()->query_name()+" gags as the "+BOLD+"tentacle"+NORM+" burrows "+WHT+"deeper"+NORM+" down their throat!\n",({ environment() }));
	environment()->heal_self(-damage);
	remove_call_out("hurt_them");
	call_out("hurt_them", 2);
}
