#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT\
    add_action("sell","sell");\
    add_action("search","search");
ONE_EXIT("/players/blackadder/hall4", "west",
	 "The Morgue",
"You are in the Morgue.  Blackadder is always in the market for fresh kills.\n" +
"A giant freezer on the back wall contains the mortal remains.\n" +
"Use the command: 'sell corpse'\n", 1)
search(str) {
    if (!str) {
       write("Found nothing of value. \n");
       return 1;
    }
    return 0;
}
sell(item) {
    object ob;
    if (!item)
	return 0;
    if (item != "corpse") {
       write("We only buy corpses here.\n");
       return 1;
    }
    ob = present(item, this_player());
    if (!ob)
	ob = present(item, this_object());
    if (!ob) {
	write("You don't have a corpse on you.\n");
	return 1;
    }
    do_sell(ob);
    return 1;
}
do_sell(ob) {
    int value, do_destroy;
    value = 50;
    if (environment(ob) == this_player()) {
        int weight;
	if (call_other(ob, "drop", 0)) {
	    write("I can't take it from you!\n");
	    return 1;
	}
        weight = call_other(ob, "query_weight", 0);
	call_other(this_player(), "add_weight", - weight);
    }
    write("You get "); write(value); write(" gold coins.\n");
    say(call_other(this_player(), "query_name", 0) + " sells " +
	call_other(ob, "short", 0) + ".\n");
    call_other(this_player(), "add_money", value);
    destruct(ob);
    return 1;
}
query_drop_castle() {
    return 1;
}
