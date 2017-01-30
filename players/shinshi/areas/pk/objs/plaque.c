inherit "/obj/treasure.c";
#include <ansi.h>

id(str) {
return str == "plaque" || str == "shinshi_plaque";
}

short() { return HIY+"A Bronze Plaque"+NORM; }
long() {
	write("This is a large bronze plaque in which the winners\n"+
		  "of the PK Tournaments are listed. These players\n"+
		  "were the ones that stood above the rest and are\n"+
		  "true PK warriors. To read the list of names, type\n"+
		  HIK+"			read plaque\n"+NORM);
}

get() { return 0; }

init()
{
	::init();
	
	add_action("read", "read");
}

read(str)
{
	if(!str)
	{
		write("What would you like to read?\n");
		return 1;
	}
	
	if(str != "plaque")
	{
		write("Try reading from the plaque.\n");
		return 1;
	}
	
	if(str == "plaque")
	{
		cat("/players/shinshi/logs/winners.txt");
		return 1;
	}
}