#include "/players/maledicta/closed/w/sdefine.h"

main(string str, object gob, object player)
{ 
object target, web, comp;
int plvl;
    if(USER->query_ghost()) return 0;
    if(!GOB->get_skill(70)){
    if(USER->test_dark()){
      return 1;
      }
     }  
	if(str){
	target = present(str, environment(USER));
	}
	else{
    target = USER->query_attack();
	}
   plvl = GOB->get_skill(40);
	if(!target){
        tell_object(USER, "You do not see "+str+" here.\n");
        return 1;
        }
   if(!WEP){
      write("You must use a weapon if you wish to pummel someone!\n");
      return 1;
      }
  if(living(target) && !target->query_npc()){
		write("You cannot pummel a player!\n");
		return 1;
	}
   if(target->query_npc() && living(target)){
		if(USER->query_spell_point() < 50 - plvl * 5){
			tell_object(USER, "You are too weak to Pummel anyone.\n");
			return 1;
		}
   if(target->pummeled()){ 
			tell_object(USER, "You cannot pummel "+target->query_name()+" again!\n"); 
			return 1; 
		}
if(random(100) > plvl * 20){
tell_object(USER,
"You attempt to pummel "+target->query_name()+", but miss!\n");
USER->add_spell_point(-(25 - (plvl * 2)));
return 1;
}
tell_room(environment(USER),
HIW+USERN+" charges forward and strikes "+target->query_name()+" on the head!\n"+
target->query_name()+" stumbles around dazed from the blow!"+NORM+"\n", ({USER}));
 GOB->ast(40);
 GOB->ast(40);
 GOB->ast(40);
 GOB->ast(40);
tell_object(USER,
"You leap forward and smash "+target->query_name()+" in the head with your "+WEPN+"!\n");		
		USER->add_spell_point(-(50 - (plvl * 5)));
		web = clone_object("/players/maledicta/closed/w/OBJ/pummel.c");
web->set_time(10 + plvl * 3);
		web->web_person(target);
		return 1;
		}
	else return 0;
	return 1;
}
