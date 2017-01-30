#include <ansi.h>
inherit "/obj/treasure.c";

id(str) { return str == "thick paste" || str == "paste" || str == "shinshi_rogue_thick" || str == "shinshi_rogue_thick_paste"; }

short() { return HIW+"A thick paste"+NORM; }

long()
{
	write("This thick paste was created by mixing together woodbine berries and yew berries.\n");
}

get() { return 1; }
query_weight() { return 1; }
query_value() { return 75; }