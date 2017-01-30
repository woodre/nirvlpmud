inherit "/obj/treasure.c";
#include <ansi.h>

id(str) {
return str == "ring" || str == "shinshi_ring";
}

short() { return HIG+"--`--}"+HIR+"@ "+NORM+"Mark's own"+HIY+" golden "+NORM+"wedding ring (Daniella)"; }
long() {
	write("You see a wide band of pure gold, simple and elegant.\n"+
		  "This shows your undying love for your one, and true\n"+
		  "love for Daniella Leona Ayres.\n");
}

drop() { return 0; }
get() { return 1; }
query_weight() { return 2; }
query_value(){ return 0; }
