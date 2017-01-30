#include "/players/maledicta/ansi.h"

int how_many;

drop(){ return 1; }

id(str){ return str == "wound" || str == "wounded_object_venom"; }

long(){
	write("A gaping wound that "+HIR+"bleeds"+NORM+" continuously.  Something seems to\n"+
	"be burrowing in it.\n");
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
	damage = random(3) + 1;
	tell_object(environment(),
	HIR+"Something painfully burrows further into your body!"+NORM+"\n");
      tell_room(environment(environment()),
      environment()->query_name()+" writhes in agony!\n",({ environment() }));
	environment()->heal_self(-damage);
	environment()->add_spell_point(damage);
	how_many -= 1;
	remove_call_out("hurt_them");
	call_out("hurt_them", random(3) + 1);
}
