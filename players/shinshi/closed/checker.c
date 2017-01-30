inherit "/obj/treasure.c";
#include <ansi.h>

id(str) {
return str == "wicket_lois_check";
}

get() { return 0; }

reset(arg){
	if(arg) return;
	set_heart_beat(1);
}

heart_beat(){
	object lois, stewie, stewie2, attacker;
	
	lois = present("shinshi_lip_mob", environment(this_object()));
	stewie = present("shinshi_key_mob", environment(this_object()));
	stewie2 = clone_object("/players/shinshi/areas/coining/mobs/studenttampon.c");
	
	if(!lois->query_attack()){
		return;
	}
	
	attacker = lois->query_attacker();
	if(lois->query_attacker()){
		if(stewie){
			command("kill student", attacker);
			return 1;
		}
		
		if(!stewie){
			move_object(stewie2, environment());
			command("kill student", attacker);
		return 1;
		}
		return 1;
	}
	return 1;
}