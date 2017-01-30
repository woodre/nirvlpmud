#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
	
	int color;
	
	color = random(4);
	
	if(!str)
	{
		if(color == 0)
		{
			write(RED);
			cat("/players/wicket/guild/help/eletemp.txt");
			write(NORM);
			return 1;
		}
		
		if(color == 1)
		{
			write(YEL);
			cat("/players/wicket/guild/help/eletemp.txt");
			write(NORM);
			return 1;
		}
		
		if(color == 2)
		{
			write(GRN);
			cat("/players/wicket/guild/help/eletemp.txt");
			write(NORM);
			return 1;
		}
		
		if(color == 3)
		{
			write(CYN);
			cat("/players/wicket/guild/help/eletemp.txt");
			write(NORM);
			return 1;
		}
		return 1;
	}
	
	else if(str)
	{
		if(color == 0)
		{
			write(RED);
			cat("/players/wicket/guild/help/"+str+".txt");
			write(NORM);
			return 1;
		}
		
		if(color == 1)
		{
			write(YEL);
			cat("/players/wicket/guild/help/"+str+".txt");
			write(NORM);
			return 1;
		}
		
		if(color == 2)
		{
			write(GRN);
			cat("/players/wicket/guild/help/"+str+".txt");
			write(NORM);
			return 1;
		}
		
		if(color == 3)
		{
			write(CYN);
			cat("/players/wicket/guild/help/"+str+".txt");
			write(NORM);
			return 1;
		}
		return 1;
	}
	return 1;
}