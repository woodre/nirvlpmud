#include <ansi.h>
inherit "/obj/treasure.c";

id(str) { return str == "thin paste" || str == "paste" || str == "shinshi_rogue_thin" || str == "shinshi_rogue_thin_paste"; }

short() { return HIW+"A thin paste"+NORM; }

long()
{
	write("This thin paste was created by mixing together pokeweed berries and yew berries.\n");
}

get() { return 1; }
query_weight() { return 1; }
query_value() { return 75; }