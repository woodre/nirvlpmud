/* 

*/

#include "/players/maledicta/closed/w/sdefine.h"


main(string str, object gob, object player)
{

object target;
object plague;
int dose;
dose = GOB->query_skills(99);

   if(USER->query_ghost()) return 1;
   if(!GOB->check_align("evil")){
      tell_object(USER, "You are not evil!\n");
      return 1;
      }
   if(GOB->query_delay()){ 
      tell_object(USER, "You are already casting!\n");
      return 1;
      }
   if(USER->query_sp() < 25 || GOB->query_end() < 20){
      tell_object(USER,"You are too weak to cast.\n");
      return 1;
      }  
    
   if(!str && USER->query_attack())
		target = USER->query_attack();
	else if(str)
		target = present(str, environment(USER));

	else if(!str && !USER->query_attack()){
            tell_object(USER,"plague who?\n");
		return 1;
            }
     if(!target && str){
		tell_object(USER,
		"You don't see "+str+" here.\n");
		return 1;
	      }
     if(!present(target, environment(USER))){
		tell_object(USER,
      	"You don't see them here!\n");
		return 1;
	      }
     if(target == USER){
            tell_object(USER, "You cannot cast plague at yourself!\n");
            return 1;
            }
     if(!living(target) || target->is_player()){
		tell_object(USER,
		"You cannot plague that!\n");
		return 1;
            }
      

USER->add_spell_point(-25);
GOB->add_end(-20);
GOB->set_delay(1);

 tell_object(USER, 
 HIW+"["+HIG+"PlaGuE"+HIW+"]"+NORM+" You summon forth plague!\n"+
 target->query_name()+" is inflicted!\n");

 tell_room(environment(USER),
 USERN+" calls forth plague against "+target->query_name()+"!\n", ({USER}));
if(!present("plague_woot", target)){
plague = clone_object("/players/maledicta/closed/w/OBJ/plague.c");
plague->set_duration(GOB->query_skills(99) * 2);
plague->set_power(random(GOB->query_skills(99)) + 1);
move_object(plague, target);
}
else{
present("plague_woot", target)->add_duration(GOB->query_skills(99));
}
return 1;
}
