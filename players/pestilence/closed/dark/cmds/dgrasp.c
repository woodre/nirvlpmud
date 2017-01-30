#include "/players/pestilence/ansi.h"

main(string str) {
object target, web, comp;
int USER;
USER = this_player();
    if(USER->query_ghost()) return 0;
    if(USER->query_guild_rank() < 9) return 0;
    
        if(str){
        target = present(str, environment(USER));
        }
        else{
    target = USER->query_attack();
        }
        if(!target){
                  tell_object(USER, "You do not see "+str+" here.\n");
                  return 1;
            }
        if(target->is_living() && !target->query_npc()){
                write("You cannot cast this on players!\n");
				}
				
				  if(query_attribute("stunned", target)) {
    write(target->query_name()+" has already been Demon Grasped.\n");
    return 1;
  }
if(target->query_npc() && living(target)){
                if(USER->query_spell_point() < 40){
                        tell_object(USER, "You don't have enough mana for this.\n");
                        return 1;
                }
                        if(target->webbed()){ 
                        tell_object(USER, "You cannot Demon Grasp "+target->query_name()+" again!\n"); 
                        return 1; 
                }
if(random(70) > (USER->query_attrib("int") + USER->query_attrib("wil") + random(40))){
tell_object(USER,
"You to Demon Grasp "+target->query_name()+", but fail!\n");
USER->add_spell_point(-20);
return 1;
}
tell_room(environment(USER),
USER->query_name()+" utters some "+HIK+"Archaic"+NORM+" words.\nTwo hands begin to reach from the ground and grasp "+target->query_name()+"\nwith such force they remain motionless.\n", ({USER}));
tell_object(USER,
USER->query_name()+" utters some "+HIK+"Archaic"+NORM+" words.\nTwo hands begin to reach from the ground and grasp "+target->query_name()+"\nwith such force they remain motionless.\n");          
                USER->add_spell_point(-35);
                web = clone_object("/players/pestilence/closed/dark/obj/distraught2.c");
                web->set_time(4);
                web->web_person(target);
	    		  this_player()->attack_object(target);
                 add_attribute("stunned", target);
                 call_out("unstun", 180, target);
                return 1;
                }
        else return 0;
        return 1;
}

unstun(ob){
  if(ob) {
    delete_attribute("stunned", ob);
  }
}
