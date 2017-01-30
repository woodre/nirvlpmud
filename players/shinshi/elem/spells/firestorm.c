#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object firestorm;
	
	firestorm = clone_object("/players/wicket/guild/objs/firestorm.c");
	
	if(PO->query_suspended())
	{
		write(RED+"Adroushan"+NORM+" growls: Foolish mortal! You are suspended and have no right to cast this spell!\n");
		return 1;
	}
	
	if(PO->query_FIRE() < 6)
	{
		write(RED+"Adroushan"+NORM+" growls: You don't know that spell yet, "+User->query_race()+".\n");
		return 1;
	}
	
	if(User->query_ghost()){
		return 1;
	}
	
	if(User->query_spell_dam()){
		write(RED+"Adroushan"+NORM+" growls: Slow down! You cannot attack again just yet!\n");
		return 1;
	}
	
	if(User->query_sp() < 60)
	{
		write(RED+"Adroushan"+NORM+" growls: You are too drained to attempt this!\n");
		return 1;
	}
	
	if(present("firestorm_damage", environment(User)))
	{
		write(RED+"Adroushan"+NORM+" growls: You are already channeling a "+HIR+"Firestorm"+NORM+".\n");
		return 1;
	}
	
	write(BOLD+"You focus the powers of "+NORM+RED+"Adroushan"+NORM+BOLD+" and summon a "+HIR+"FIRESTORM"+NORM+BOLD+" to ravage the area!\n"+NORM);
	say(User->query_name()+" "+BOLD+"focuses the powers of "+NORM+RED+"Adroushan"+NORM+BOLD+" and summons a "+HIR+"FIRESTORM"+NORM+BOLD+" to ravage the area!\n"+NORM);
	User->add_spell_point(-60);
	move_object(firestorm, environment(User));
	firestorm->start_it();
	return 1;
}
	