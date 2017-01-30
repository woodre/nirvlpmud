inherit "/obj/treasure.c";
#include <ansi.h>

id(str) {
return str == "lipstick" || str == "shinshi_lipstick";
}

short() { return "Some "+HIR+"lipstick"+NORM; }
long() {
	write("A small, cylindrical tube with a cap at\n"+
		  "one and and a dial at the other. It looks\n"+
		  "like the same shade that the teacher uses.\n");
}

get() { return 1; }
query_weight() { return 2; }
query_value(){ return 3000; }
