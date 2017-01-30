#include "/players/stark/defs.h"

mixed id(string str) { return str == "druid_plague_two"; }


void reset(int arg)
{
    if(arg) return;
    set_heart_beat(1);
}

drop() { return 1; }
get() { return 1; }

heart_beat()
{
	if(!environment(this_object())->query_attack()){
		tell_room(environment(environment(this_object())),"Worn off");
		destruct(this_object());
		return 1;}
	environment(this_object())->heal_self(-100);
	tell_room(environment(environment(this_object())),"OWCH");
}

