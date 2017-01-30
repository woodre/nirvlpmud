#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object djinn;
	
	if(PO->query_suspend())
	{
		write("You are suspended and cannot do that.\n");
		return 1;
	}
		
	if(!present("elemental aura", User))
	{
		write("You must complete the Elemental Test!\n");
		return 1;
	}
	
	if(User->query_sp() < 150)
	{
		write("Khnum says: You do not have the magical energies needed to summon the Elemental Djinn!\n");
		return 1;
	}
	
	if(PO->query_has_djinn())
	{
		write("You already have a Djinn with you.\n");
		return 1;
	}
	
	if(AIRDAEMON->check_people(User) || FIREDAEMON->check_people(User) || WATERDAEMON->check_people(User) || EARTHDAEMON->check_people(User))
	{
		write("The "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"tal"+NORM+" Djinn requires all four Elements to be used.\n");
		return 1;
	}
			write("\n\nYou call upon the Four Ancient "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"tal"+NORM+" Elders for aid in combat...\n\nA Fine "+CYN+"mist"+NORM+" whips around the room as "+CYN+"Glyndwr"+NORM+" appears.....\n\nA crisp "+YEL+"wind"+NORM+" whips around the room as "+YEL+"Aeolos"+NORM+" appears.....\n\n");
			write(RED+"Embers "+NORM+"whip around the room as "+RED+"Adroushan"+NORM+" appears.....\n\nThe "+GRN+"earth"+NORM+" trembles as "+GRN+"Aatami"+NORM+" appears.....\n\nThe Elders chant a bright light explodes.\n\nEverything fades into view....\n\nThe Four Ancient Elders have vanished from sight....\n\nAn Anicent "+NORM+RED+"Ele"+YEL+"me"+GRN+"nt"+CYN+"al"+NORM+" Djinn Bows standing in their place.\n\n"+NORM);
		move_object(clone_object(DJINNPATH+"eledjinn.c"), environment(User));
		User->add_spell_point(-150);
		djinn = present("djinn", environment(User));
		djinn->patch_owner(this_player());
    	djinn->set_level(9);
    	djinn->set_ac(20);
    	djinn->set_wc(20);
    	djinn->set_hp(350);
    	djinn->init();
    	PO->set_has_djinn(1);
		return 1;
}
