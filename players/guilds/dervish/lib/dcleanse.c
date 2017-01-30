#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	object poison, next;
	string a, b;
	
	if(User->query_level() < 19) {
		write("You are not high enough level to use this Master ability yet.\n");
		return 1;
	}
	
	if(User->query_ghost()) {
		write("You lack substance.\n");
		return 1;
	}
	
	if(User->query_attrib("pie") < 30) {
		write("You lack devotion.\n");
		return 1;
	}
	
	if(PO->query_spell_delay()) {
		write("You cannot cast a spell again so soon.\n");
		return 1;
	}
	write(BOLD+RED+"\tYou scream and spin into a frenzy!\n"+OFF+OFF);
	say(BOLD+RED+User->query_name()+" screams and spins into a frenzy!\n"+OFF+OFF);
	User->drink_alcohol(-(((int)User->query_level()/4)+((int)User->query_extra_level()/5)));
	User->eat_food(-(((int)User->query_level())+((int)User->query_extra_level()/5)));
	User->drink_soft(-(((int)User->query_level())+((int)User->query_extra_level()/5)));
	PO->delete_sand_points(20+random(15));
	if(PO->query_sand_points() < 1)
	{
		User->add_hit_point(-15);
		tell_object(User, "The sand takes your blood as its sacrifice.\n");
		PO->add_sand_points((21-((int)User->query_level()))*5);
		if(User->query_hp() < 1)
			PO->kill_me(User);
			PO->add_spell_delay(10+random(40));
			return 1;
		}
		return 1;
}