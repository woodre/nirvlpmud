#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	object ob, conshad;
	int obwc, obac;
	int calc_sp;
	
	if(User->query_level() < 15) {
		write("You are not high enough level to confuse yet.\n");
		return 1;
	}
	
	if(User->query_ghost()) {
		write("You cannot confuse while you are a ghost.\n");
		return 1;
	}
	
	calc_sp=(160 -
		(((int)User->query_level()*3/4) +
		((int)User->query_extra_level()*3/4) +
		((int)User->query_attrib("mag")/2) +
		((int)User->query_attrib("pie")/2) +
		((int)User->query_attrib("wil")/2)));
		
	if(User->query_sp() < calc_sp) {
		write("You lack the energy to confuse.\n");
		return 1;
	}
	
	if(User->query_attrib("pie") < 15) {
		write("You lack in faith.\n");
		return 1;
	}
	
	if(PO->query_spell_delay()) {
		write("You cannot cast a spell again so soon.\n");
		return 1;
	}
	
	if(!str && !User->query_attack()) {
		write("Confuse what?\n");
		return 1;
	}
	
	if(!str) ob = (object)User->query_attack();
	if(!ob) ob = present(str, environment(User));
	if(!ob || !present(ob, environment(User))) {
		write("You can't see "+str+".\n");
		return 1;
	}
	
	if(!living(ob)) {
		write("You cannot confuse inanimate objects.\n");
		return 1;
	}
	
	if(ob->is_player()) {
		write("You cannot confuse players.\n");
		return 1;
	}
	
	if(ob->is_confused()) {
		write(ob->query_name()+" is already confused.\n");
		return 1;
	}
	write("You scream and whirl maniacally!\n");
	say(User->query_name()+" screams and whirls maniacally!\n");
	tell_room(environment(User), BOLD+ob->query_name()+" is surrounded by whipping particles of sand!\n"+OFF);
	conshad = clone_object(OBJECTPATH+"/conshad.c");
	conshad->set_victim(ob);
	conshad->set_time(((int)User->query_level()/2) + ((int)User->query_extra_level()/3) +
			((int)User->query_attrib("mag")/4) +
			((int)User->query_attrib("pie")/4) +
			((int)User->query_attrib("wil")/4));
	PO->set_spell_delay(275-
	((int)User->query_attrib("wil"))-
	((int)User->query_attrib("mag"))-
	((int)User->query_attrib("pie"))-
	((int)User->query_level() * 5)-
	((int)User->query_extra_level()/2));
	
	User->add_spell_point(-calc_sp);
	return 1;
}