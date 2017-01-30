inherit "/obj/treasure";
#include <ansi.h>

id(str) { return (str == "chemical" || str == "ethanediyloxycarbonyl"); }

short() { return HBRED+"Ethanediyloxycarbonyl (rare)"+NORM; }
long() {
	write("This very rare chemical bubbles as it moves. It has a\n");
	write("red color to it and fizzes at random times.\n");
	write("A label on the tube says, \"When combined with two\n");
	write("other rare chemicals, it can bond together and form\n");
	write("a very powerful substance.\"\n");
}

query_value() { return 0; }
query_save_flag() { return 1; }
query_weight() { return 1; }
get(){ return 1; }