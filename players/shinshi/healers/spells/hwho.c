#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	int level, xlevel, x, health, spell;
	string title, place;
	object ob, gob, *people;
        people = users();
	
	write("\n");
	write(BOLD+WHT+"........................................................................\n"+OFF+NORM);
	write("   "+BOLD+BLACK+pad("Name",     15)+
	    pad("Level",       10)+
	    pad("HP",		   10)+
	    pad("SP",    30)+"\n"+OFF+OFF);
	write(BOLD+WHT+"........................................................................\n"+OFF+NORM);
	    
	for(x=0;x<sizeof(people);x+=1)
        {
		if(!people[x]->query_invis() && present("new_healers", people[x]) || people[x]->query_invis() && present("new_healers", people[x]))
                {
			ob = people[x];
			
			if(!ob->query_interactive())
			{
				title = "X  ";
			}
			
			if(ob->query_ghost())
			{
				title = "*  ";
			}
			
			if(query_idle(ob))
			{
				title = "I  ";
			}
			
			if(ob->query_attack())
			{
				title = "C  ";
			}
			
			else
			{
				title = "   ";
			}
			
			health = ((int)ob->query_hp()) * 100 / ((int)ob->query_mhp());
			spell = ((int)ob->query_sp()) * 100 / ((int)ob->query_msp());
			
			
			write(title+pad((string)ob->query_name(), 15));
			level = (int)ob->query_level();
			xlevel = (int)ob->query_extra_level();
			write(pad(level+"+"+xlevel, 10));
			write(pad(health+"%", 10));
			write(pad(spell+"%", 10));
			write("\n");
		}
	}
		write("\nX = Disconnected, * = Ghost, C = Combat\n");
		write(BOLD+WHT+"........................................................................\n"+OFF+NORM);
    return 1;
}
	
