#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	object meat, ob;
	int hp, mhp, cost1, cost2, z;    /*cost1 is spell points, cost2 is sandpoints*/

	meat = (object)User->query_attack();

	if(User->query_level() < 11)
	{
		write("You are unable to use this ability yet.\n");
		return 1;
	}

	if(User->query_no_spell() || this_player()->checkNM())
	{
		write("You are unable to work the sands at this time.\n");
		return 1;
	}

	if(User->query_ghost())
	{
		write("You cannot do that while you are dead!\n");
		return 1;
	}

	if(!meat)
	{
		write("You must be in combat to do that!\n");
		return 1;
	}


	if(!meat->is_npc())
	{
		write("You cannot finish that!\n");
		return 1;
	}

	if(!present(meat, ENV(User)))
	{
		write(meat->query_name()+" is not present.\n");
		return 1;
	}

	hp = (int)meat->query_hp();
	mhp = (int)meat->query_mhp();
	z = 0;
	cost1 = 15;
	cost2 = 25;

	if(((hp*10) / mhp) < 1)
	{
		if(!random(10))
		{
			write("Your attempt fails!\n");
			if(User->query_spell_point() > cost1)
			User->add_spell_point(-cost1);
		else
			PO->add_sand_points(-cost2);
			return 1;
		}
	else
	{
		switch(random(4))
		{
			case 0:
			tell_room(ENV(User),
			"\n"+BROWN+"Particles of sand whip into the room tearing the flesh from "+meat->query_name()+"!\n");
			tell_room(ENV(User),
			"When the sand dissipates only "+meat->query_name()+"'s lifeless body remains.\n\n"+OFF);
			break;
			case 1:
			tell_room(ENV(User),
			"\n"+BROWN+"A wave of sand engulfs "+meat->query_name()+" slowly suffocating the life out of "+meat->query_objective()+"."+OFF+"\n\n"); 
			break;
			case 2:
			tell_room(ENV(User),
			"\n"+BROWN+"The ground beneath "+meat->query_name()+" starts to shake...\n");
			tell_room(ENV(User),
			"     A giant pillar of sand explodes from the ground smashing\n"+"    "+meat->query_name()+" into a bloody pulp.\n\n"+OFF);
			break;
			case 3: 
			tell_room(ENV(User),
			"\n"+BROWN+"The ground opens up underneath "+meat->query_name()+" causing them to fall to their death.\n\n"+OFF);
			z = 1;
			break;
		}
		if(z)
		destruct(present("corpse", ENV(User)));

		if(User->query_spell_point() > cost1)
		User->add_spell_point(-cost1);
		else
		PO->add_sand_points(-cost2);       

		meat->heal_self(-hp);
		meat->hit_player(hp*2); 
		return 1;
		}
	}
	else
	{
	write("Your attempt fails. "+meat->query_name()+" is too strong yet!\n");
	if(User->query_spell_point() > cost1)
	User->add_spell_point(-cost1);
	else
	PO->add_sand_points(-cost2);
	return 1;
	}
	return 1;
}
