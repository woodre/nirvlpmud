#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object sandstorm;
	int x;
	
	if(User->query_ghost()) {
		write("You lack substance.\n");
		return 1;
	}
	
	if(User->query_attrib("pie") < 30){
		write("You lack devotion.\n");
		return 1;
	}
	
	if(PO->query_spell_delay()) {
		write("You cannot cast a spell again so soon.\n");
		return 1;
	}
	
	if(environment(User)->query_no_fight()) {
		write("You can not cast this spell here.\n");
		return 1;
	}
	
	x=65+random(20);
	if(User->query_sp() < x)
	{
		write("You do not have enough energy.\n");
		return 1;
	}
	
	if(User->query_level() < 19 || (User->query_extra_level() < 15 && !User->query_prestige_level())) {
		write("You are not high enough level to summon a sandstorm yet.\n");
		return 1;
	}
	 
	if(present(SANDSTORM, environment(User))){
		write("There is already a sandstorm in the room.\n"); return 1; }
		write(BOLD+RED+"\tYou scream wildly as a Sandstorm sweeps into the room.\n"+OFF);
		say(BOLD+RED+User->query_name()+" screams wildly as a Sandstorm sweeps into the	room.\n"+OFF);
		sandstorm = clone_object(OBJECTPATH+"/sandstorm.c");
		sandstorm->set_time(((int)User->query_level()/2) + ((int)User->query_extra_level()/2)+
		((int)User->query_attrib("int")/2) +
		((int)User->query_attrib("wil")/2)); 
                sandstorm->set_owner( User );

	move_object(sandstorm, environment(User));
	User->add_spell_point(-x);
	PO->add_spell_delay(200 - (((int)User->query_level()*4) + ((int)User->query_extra_level()
	/2) +
	((int)User->query_attrib("pie")/2) +
	((int)User->query_attrib("wil")/2) +
	((int)User->query_attrib("int")/2) +
	((int)User->query_attrib("dex")/2)));
	return 1; }
