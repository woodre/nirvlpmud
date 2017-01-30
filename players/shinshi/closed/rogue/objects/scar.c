#include <ansi.h>
#include "../defs.h"

id(str) { return str == "scars"; }

long()
{
	write("Two scars are on both sides of your spine.\n");
}

extra_look()
{
	if(environment() == this_player())
		write("You have two large scars in the midde of your back.\n");
	else
		write(environment()->query_name() + " has two dagger wounds on both sides of " + possessive(environment()) + " spine from a Rogue.\n");
}

query_auto_load() { return OBJPATH+"scar:"; }

drop() { return 1; }