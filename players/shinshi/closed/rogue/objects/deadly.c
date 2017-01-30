inherit "/obj/treasure.c";
#include <ansi.h>

id(str) {
return str == "shinshi_deadly_poison" || str == "poison" || str == "deadly poison";
}

short() { return HIG+"Deadly Poison"+NORM; }
long() {
	write("This small vial of poison can be used by\n"+
		  "applying it to your weapon for a chance\n"+
		  "to poison your enemies.\n");
}

get() { return 1; }
query_weight() { return 1; }
query_value(){ return 0; }