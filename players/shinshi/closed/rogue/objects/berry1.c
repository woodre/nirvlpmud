#include <ansi.h>
inherit "/obj/treasure.c";

id(str) { return str == "berries" || str == "shinshi_berries1" || str == "shinshi_rogue_berries1" || str == "woodbine"; }

short() { return HIB+"Woodbine Berries"+NORM; }

long()
{
	write("These dark blue berries are known to be very poisonous.\n");
}

get() { return 1; }
query_weight() { return 1; }
query_value() { return 50; }