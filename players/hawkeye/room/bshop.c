#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT\
   add_action("sell", "sell"); \
   add_action("value", "value");\
   add_action("buy", "buy"); \
   add_action("north", "north"); \
   add_action("list", "list");

ONE_EXIT("players/hawkeye/room/rd4.c", "east",
    "Black Market Shop",
   "Looking around at the small tables scattered about, you see many\n" +
    "items that could be very useful. The man behind the largest table\n" +
    "looks he will give you more than a fair price for your items.\n" +
	 "Commands are: 'buy item', 'sell item', 'list', 'list weapons'\n" +
	 "'list armors' and 'value item'.\n" +
   "You can go back east the the M*A*S*H camp.\n" ,1)


sell(item) {
    int value;
    string name_of_item;
    object ob;

    if (!item)
	return 0;
    name_of_item = present(item, this_player());
    if (!name_of_item)
      name_of_item = find_item_in_player(item);
    if (!name_of_item) {
	write("No such item ("); write(item); write(") here.\n");
	return 1;
    }
    value = call_other(name_of_item, "query_value", 0);
    if (!value) {
	write(item); write(" has no value.\n");
	return 1;
    }
    if (environment(name_of_item) == this_player()) {
        int weight;
	if (call_other(name_of_item, "drop", 0)) {
	    write("I can't take it from you!\n");
	    return 1;
	}
        weight = call_other(name_of_item, "query_weight", 0);
	call_other(this_player(), "add_weight", - weight);
    }
    if (value > 1000) {
	write("The shop is low on money...\n");
	value = 1000;
    }
    write("You get "); write(value); write(" gold coins.\n");
    say(call_other(this_player(), "query_name", 0) + " sells " +
	call_other(name_of_item, "short", 0) + ".\n");
    call_other(this_player(), "add_money", value);
    call_other("room/store", "store", name_of_item);
    return 1;
}

value(item) {
    int value;
    string name_of_item;

    if (!item)
	return 0;
    name_of_item = present(item);
    if (!name_of_item)
      name_of_item = find_item_in_player(item);
    if (!name_of_item) {
	if (call_other("room/store", "value", item))
	    return 1;
	write("No such item ("); write(item); write(") here\n");
	write("or in the store.\n");
	return 1;
    }
    value = call_other(name_of_item, "query_value", 0);
    if (!value) {
	write(item); write(" has no value.\n");
	return 1;
    }
    if (value < 1001) {
     write("The value is "+value+".\n");
    }
    else {
	write("It's really worth "); write(value); write(" gold coins.\n");
	write("But the store is low on money, so you would only get 1000.\n");
    }
    return 1;
}

buy(item) {
    if (!item)
	return 0;
    call_other("room/store", "buy", item);
    return 1;
}

east() {
    call_other(this_player(), "move_player", "east#players/hawkeye/room/rd4.c");
    return 1;
}

list(obj) {
    call_other("room/store", "inventory", obj);
    return 1;
}

find_item_in_player(i)
{
    object ob;

    ob = first_inventory(this_player());
    while(ob) {
        if (call_other(ob, "id", i))
	    return ob;
	ob = next_inventory(ob);
    }
    return 0;
}
realm(){return "enterprise";}