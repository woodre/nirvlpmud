inherit "/obj/treasure.c";
#include <ansi.h>

id(str) {
return str == "sign" || str == "abcdefghij";
}

short() { return "A HUGE RED "+HIR+"SIGN"+NORM+" THAT WICKET SHOULD LOOK AT."; }
long() {
	write("WHAT UP, FAGGOT! I'M AT MY GIRLFRIEND'S HOUSE UNTIL LIKE 6PM\n"+
		  "TONIGHT. THEN I'LL BE HOME TO CODE IF YOU WANT. YOU CAN GIVE\n"+
		  "ME A CALL THEN IF YOU WANT. LATER!\n");
}

get() { return 0; }
query_weight() { return 1; }
query_value(){ return 0; }