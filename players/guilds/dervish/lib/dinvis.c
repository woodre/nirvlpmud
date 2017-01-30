#include <ansi.h>
#include "../defs.h"
#define VEIL REV_RED+BOLD+"Veil of Sand"+OFF+OFF

status main(string str, object PO, object User)
{
	object ob;
	
	if(User->query_level() < 15) {
		write("You are unable to use this ability yet.\n");
		return 1;
	}
	
	if(User->query_no_spell() || User->checkNM() || User->query_sp() < 40) {
		write("You are unable to work the Sands at this time.\n");
		return 1;
	}
	
	if(str) {
	ob = present(str, environment(User));
	if(!ob) {
		write("You can't see "+str+" here.\n");
		return 1;
	}
	if(!ob->is_player()) {
	  write("You cannot draw the Sands over "+str+".\n"); return 1; }
	}
	
	if(!ob) ob = User;
	if(ob == User) {
	write("You cover yourself with a "+VEIL+" and fade from normal sight.\n");
	say(ob->query_name()+" covers "+ob->query_objective()+"self with a "+VEIL+" and fades from normal sight.\n");
	}
	else {
	write("You cover "+ob->query_name()+" with a "+VEIL+" and "+ob->query_pronoun()+" fades from normal sight.\n");
	say(User->query_name()+" covers "+ob->query_name()+" with a "+VEIL+" and "+ob->query_name()+" fades from normal sight.\n");
	}
	ob->set_invs_sp();
	User->add_spell_point(-40);
	PO->add_spell_delay(random(10)+1);
	return 1;
}