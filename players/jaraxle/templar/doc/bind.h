
web(string str){
object target, web, comp;
    if(USER->query_ghost()) return 0;
    if(USER->query_level() < 14) return 0;
    if(!venomed) return 0;
    
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
		return 1;
	}
if(target->query_npc() && living(target)){
		if(USER->query_spell_point() < 30){
			tell_object(USER, "Your symbiotic link is too weak for that.\n");
			return 1;
		}
		if(mp < 10){
		 tell_object(USER,
		 "Your symbiotic link is too weak for that.\n");
		 return 1;
		 }
            		if(target->webbed()){ 
			tell_object(USER, "You cannot web "+target->query_name()+" again!\n"); 
			return 1; 
		}
if(random(100) > (USER->query_attrib("int") + USER->query_attrib("wil") + random(100))){
tell_object(USER,
"You attempt to web "+target->query_name()+", but miss!\n");
mp -= 5;
USER->add_spell_point(-20);
return 1;
}
tell_room(environment(USER),
"A stream of "+HIW+"webs"+NORM+" fly from "+capitalize(symb_name)+"'s hands covering "+target->query_name()+"!\n", ({USER}));
tell_object(USER,
"A stream of "+HIW+"webs"+NORM+" fly from your hands covering "+target->query_name()+"!\n");		
		USER->add_spell_point(-30);
		mp -= 10; 
		web = clone_object("/players/maledicta/venom/OBJ/webbing.c");
		web->set_time(20 + USER->query_level() + USER->query_extra_level());
		web->web_person(target);
		return 1;
		}
	else return 0;
	return 1;
}
