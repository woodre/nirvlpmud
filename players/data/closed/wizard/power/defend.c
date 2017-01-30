

#include "/players/maledicta/closed/w/sdefine.h"

main(string str, object gob, object player)
{ 
object lwho;
object aided;
object aided2;
object att1,att2;

   if(!str){ tell_object(USER, "Defend who?\n"); return 1; }
   if(USER->query_ghost()) return 0;
	if(GOB->query_spell_delay()){
		tell_object(USER,
		"You are already using a skill.\n");
		return 1;
	}
   if(USER->query_sp() < 15){  
      tell_object(USER, "You are too weak to perform this.\n");
      return 1;
      }
   if(!GOB->get_skill(70)){
    if(USER->test_dark()){
      return 1;
      }
     }  


aided = present(str, environment(USER));
if(!aided) { tell_object(USER, "That person is not here.\n"); return 1; }

if(aided->query_attack() == this_player()){
tell_object(USER, "You can't defend against yourself!\n");
return 1;
}

att1 = aided->query_attack();
att2 = aided->query_alt_attack();

if(!att1){
tell_object(USER,
"That person is not fighting.\n");
return 1;
}
if(att1->query_attack() == this_player()){
tell_object(USER, "You are already leading the fight!\n");
return 1;
}   
tell_room(environment(USER),
USERN+" rushes to defend "+capitalize(str)+"!\n", ({ aided }));

tell_object(aided, HIW+"You are pushed back as "+USERN+" rushes to defend you!\n"+NORM);

USER->add_spell_point(-15);
GOB->set_delay(1);


USER->attack_object(att1);
att1->attack_object(USER);
if(att2)
att2->attack_object(USER);
return 1;
}

