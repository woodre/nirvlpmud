#include <ansi.h>
int time;

id(str) { return str == "water_damage_bitch"; }
get() { return 1; }
drop() { return 1; }

set_damlength(num) {
	time = num;
	call_out("end_damage", time);
}

start_it(){
  set_heart_beat(1);
}

heart_beat()
{
  object ob;
  int damage;
  
  ob = environment();
  damage = 5 + random(10);
  
  tell_object(ob, "\
You gasp for air but your lungs are filled with "+HIB+"water"+NORM+".\n");
  tell_room(environment(ob), "\
  "+ob->query_name()+" gasps for air!\n");
  ob->hit_player(damage, "water");
}

end_damage(){
	if(environment(this_object())){
		if(environment(environment(this_object())))
		tell_room(environment(environment(this_object())), capitalize(environment()->query_name())+" finally coughs up all the water!\n");
	else
		tell_room(environment(environment(this_object())), "You cough really hard and expel all of the water from your lungs!\n");
		destruct(this_object());
	}
}
			


