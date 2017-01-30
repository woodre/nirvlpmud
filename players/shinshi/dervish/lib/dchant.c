#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	if(User->query_level() < 10) {
		write("You are not high enough level to use this Mystic ability yet.\n");
		return 1;
	}
	
	if(User->query_ghost()) {
		write("You lack substance.\n");
		return 1;
	}
	
	if(User->query_attrib("pie") < 19) {
		write("You lack devotion.\n");
		return 1;
	}
	
	if(PO->query_spell_delay()) {
		write("You cannot cast a spell again so soon.\n");
		return 1;
	}
	
	if(User->query_sp() < 20) {
		write("You do not have enough energy.\n");
		return 1;
	}
	
	if(User->query_attack()) {
		write("You cannot cast a spell in combat.\n");
		return 1;
	}
	write(BOLD+RED+User->query_name()+" screams and spins wildly about!\n"+OFF+OFF);
	User->add_spell_point(-20);
	User->add_hit_point(random((int)User->query_attrib("pie"))+8);
	PO->add_spell_delay(random(20)+5);
	return 1;
}