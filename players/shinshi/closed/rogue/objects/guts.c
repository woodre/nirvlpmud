#include <ansi.h>
inherit "/obj/treasure.c";

id(str) { return str == "guts" || str == "shinshi_guts" || str == "shinshi_rogue_guts"; }

short() { return "Some "+HIR+"bloody"+NORM+" guts"; }

long()
{
	write("Some guts that look freshly removed.\n");
}

extra_look()
{
	if(environment() == this_player())
		write("You have some guts flung over your shoulder.\n");
	else
		write(environment()->query_name()+" has some guts flung over "+possessive(environment())+" shoulder.\n");
}

get() { return 1; }
query_weight() { return 1; }
query_value() { return 25; }