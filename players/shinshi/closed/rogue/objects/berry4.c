#include <ansi.h>
inherit "/obj/treasure.c";

id(str) { return str == "berries" || str == "shinshi_berries4" || str == "shinshi_rogue_berries4" || str == "yew"; }

short() { return RED+"Yew Berries"+NORM; }

long()
{
	write("These short, round, hollow berries are known to be very poisonous.\n");
}

get() { return 1; }
query_weight() { return 1; }
query_value() { return 50; }