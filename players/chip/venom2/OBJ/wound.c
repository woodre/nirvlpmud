#include "/players/chip/ansi.h"

int how_many;

drop(){ return 1; }

id(str){ return str == "wound" || str == "wounded_object_venom"; }

long(){
	write("A deep hole that is "+HIR+"bleeding profusely"+NORM+".  Something is moving\n"+
	"around inside of it.\n");
	return 1;
}

query_value(){ return 0; }
query_weight(){ return 0; }

reset(){
	call_out("hurt_them", 3);
}

set_how_many(int i){ how_many = i; }
query_how_many(){ return how_many; }

hurt_them(){
	int damage;
	if(!environment()) return;
	if(!living(environment())){ destruct(this_object()); return 1; }
	if(!how_many){
		destruct(this_object());
		return 1;
	}
	damage = random(4) + 4; /*changed from random(2) + 1 to bring up a bit closer to today's power standards -Chip(4-15-09)*/
	tell_object(environment(),
	HIR+"Something infests your body...it feels like something living!"+NORM+"\n");
      tell_room(environment(environment()),
      environment()->query_name()+" cries out in pain!\n",({ environment() }));
	environment()->heal_self(-damage);
	environment()->add_spell_point(damage);
	how_many -= 1;
	remove_call_out("hurt_them");
	call_out("hurt_them", random(3) + 1);
}
