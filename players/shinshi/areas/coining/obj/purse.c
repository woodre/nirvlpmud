inherit "/obj/treasure.c";
#include <ansi.h>

id(str) {
return str == "purse" || str == "shinshi_purse";
}

short() { return "A "+HIK+"black leather purse"+NORM; }
long() {
	write("A black leather purse which has been completely emptied.\n");
}

get() { return 1; }
query_weight() { return 5; }
query_value(){ return 5000; }
