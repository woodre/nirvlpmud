#include <ansi.h>
inherit "/obj/treasure.c";

id(str) { return str == "berries" || str == "shinshi_berries3" || str == "shinshi_rogue_berries3" || str == "bittersweet"; }

short() { return YEL+"Bittersweet Berries"+NORM; }

long()
{
	write("These short, round berries are known to be very poisonous.\n");
}

get() { return 1; }
query_weight() { return 1; }
query_value() { return 50; }