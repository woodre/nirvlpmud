inherit "/obj/treasure.c";
#include <ansi.h>

id(str) {
return str == "key" || str == "shinshi_key";
}

short() { return "A "+HIY+"key"+NORM; }
long() {
	write("A small key with seven different sized ridges that\n"+
		  "can be inserted into a key hole.\n");
}

get() { return 1; }
query_weight() { return 1; }
query_value(){ return 0; }