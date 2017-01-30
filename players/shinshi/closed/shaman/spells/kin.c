#include <ansi.h>

status main(string str, object PO, object User)
{
	int level, xlevel, x;
	string title, place;
	object ob, *people;
        people = users();
	
	write("\n");
	write(BOLD+"********************************************************"+
	    "***********************\n"+OFF);
	write(BOLD+BLU+pad("Shaman",     15)+
	    pad("Level",       11)+
	    pad("Location",    30)+"\n"+OFF+OFF);
	write(BOLD+"********************************************************"+
	    "***********************\n\n"+OFF);
	    
	for(x=0;x<sizeof(people);x+=1)
        {
		if(!people[x]->query_invis() && present("shinshi_shaman_relic", people[x]) || people[x]->query_invis() && present("shinshi_shaman_relic", people[x]))
                {
			ob = people[x];
			write(pad((string)ob->query_name(), 15));
			level = (int)ob->query_level();
			xlevel = (int)ob->query_extra_level();
			write(pad(level+"+"+xlevel, 15));
			place = (string)environment(ob)->short();
			write(place);
			write("\n");
		}
	}
        return 1;
}
	
