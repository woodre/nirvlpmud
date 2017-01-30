#include <ansi.h>
#include "../defs.h"

status main(string str, object PO, object User)
{
	int level, xlevel, x;
	string title, place;
	object ob, gob, *people;
        people = users();
	
	write("\n");
	write(BOLD+"********************************************************"+
	    "***********************\n"+OFF);
	write(BOLD+BLACK+pad("Elementalists",     20)+
	    pad("Level",       20)+
	    pad("Location",    30)+"\n"+OFF+OFF);
	write(BOLD+"********************************************************"+
	    "***********************\n\n"+OFF);
	    
	for(x=0;x<sizeof(people);x+=1)
        {
		if(!people[x]->query_invis() && present("wicket_element_orb", people[x]) || people[x]->query_invis() && present("wicket_element_orb", people[x]))
                {
			ob = people[x];
			gob = present("wicket_element_orb", ob);
			if(gob->query_elder())
			{
				title = YEL+"*  "+NORM;
			}
			
			if(gob->query_gwiz())
			{
				title = RED+"** "+NORM;
			}		
			
			if(!gob->query_gwiz() && !gob->query_elder())
			{
				title = "   ";
			}
			write(title+pad((string)ob->query_name(), 17));
			level = (int)ob->query_level();
			xlevel = (int)ob->query_extra_level();
			write(pad(level+"+"+xlevel, 19));
			place = (string)environment(ob)->short();
			write(place);
			write("\n");
		}
	}
	write(YEL+"* "+BOLD+BLACK+"denotes an Elder	"+RED+"** "+BOLD+BLACK+"denotes a Guild Wiz\n"+NORM);
    return 1;
}
	
