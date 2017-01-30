inherit "/obj/treasure.c";
#include <ansi.h>

id(str) {
return str == "tampon" || str == "shinshi_tampon";
}

short() { return HBMAG+"A tampon"+NORM; }
long() {
	write("An unused Tampax tampon. The tampon's paper has been\n"+
		  "ripped a little bit revealing the tampon.\n");
}

get() { return 1; }
query_weight() { return 2; }
query_value(){ return 3500; }
