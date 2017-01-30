#include <ansi.h>
int beats;
#define MAX_BEATS 5

id(str) { return str == "engulf_damage"; }
get() { return 1; }
drop() { return 1; }

start_it()
{
	set_heart_beat(1);
}

heart_beat()
{
	object ob;
	int damage;

	ob = environment();
	damage = 15 + random(11);

	tell_object(ob, BOLD+"\You double over in "+NORM+RED+"agony"+NORM+BOLD+" as your body "+HIR+"burns"+NORM+BOLD+" from the "+HIR+"fire"+NORM+BOLD+"!\n"+NORM);
	tell_room(environment(ob), BOLD+"\ "+ob->query_name()+" doubles over in "+NORM+RED+"agony"+NORM+BOLD+" as their body "+HIR+"burns"+NORM+BOLD+" from the "+HIR+"fire"+NORM+BOLD+"!\n"+NORM);
	ob->hit_player(damage, "other|fire");
	
	if(++beats == MAX_BEATS)
	{
		tell_object(ob, BOLD+"\nThe "+HIR+"flames"+NORM+BOLD+" around your body dissipate.\n"+NORM);
		tell_room(environment(ob), BOLD+"\nThe "+HIR+"flames"+NORM+BOLD+" around "+ob->query_name()+"'s body dissipate.\n"+NORM);
		end_it();
	}
}

end_it()
{
	set_heart_beat(0);
}