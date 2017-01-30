#include <ansi.h>
inherit "/obj/treasure.c";

id(str) { return str == "berries" || str == "shinshi_berries2" || str == "shinshi_rogue_berries2" || str == "pokeweed"; }

short() { return MAG+"Pokeweed Berries"+NORM; }

long()
{
	write("These long, dark purple berries are known to be very poisonous.\n");
}

get() { return 1; }
query_weight() { return 1; }
query_value() { return 50; }