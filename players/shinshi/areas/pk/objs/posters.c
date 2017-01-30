inherit "/obj/treasure.c";
#include <ansi.h>

id(str) {
return str == "poster" || str == "posters" || str == "shinshi_poster";
}

short() { return HIR+"Large Posters"+NORM; }
long() {
	write("A couple of large posters are taped everywhere\n"+
		  "on the bus. The posters have pictures of people\n"+
		  "fighting other people on them. There looks like\n"+
		  "there is one extremely important poster that looks\n"+
		  "as if it were an "+HIK+"agreement"+NORM+". Perhaps\n"+
		  "you should view it.\n");
}

get() { return 0; }

init()
{
	::init();
	
	add_action("view", "view");
}

view(str)
{
	if(!str)
	{
		write("What would you like to view?\n");
		return 1;
	}
	
	if(str != "agreement" && str != "notice" && str != "commands")
	{
		write("That is not here to view!\n");
		return 1;
	}
	
	if(str == "agreement")
	{
		cat("/players/shinshi/areas/pk/agreement.txt");
		return 1;
	}
	if(str == "notice")
	{
		cat("/players/shinshi/areas/pk/notice.txt");
		return 1;
	}
	
	if(str == "commands")
	{
		cat("/players/shinshi/areas/pk/commands2.txt");
		return 1;
	}
}