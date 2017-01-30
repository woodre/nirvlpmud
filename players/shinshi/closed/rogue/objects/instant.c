inherit "/obj/treasure.c";
#include <ansi.h>

id(str) {
return str == "shinshi_instant_poison" || str == "poison" || str == "instant poison";
}

short() { return HIG+"Instant Poison"+NORM; }
long() {
	write("This small vial of poison can be used by\n"+
		  "applying it to your weapon for a chance\n"+
		  "to poison your enemies.\n");
}

get() { return 1; }
query_weight() { return 1; }
query_value(){ return 0; }