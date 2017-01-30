#include "std_old.h"

id(str) { return str == "sign"; }
short() { return "A Shop Sign"; }
long() { write("\n"+
 "The sign reads:\n"+
 "          You may buy and sell items here.\n"+
 "          You may also list and value items.\n"+
 "\n");
}

init()  {
   add_action("buy","buy");
   add_action("sell","sell");
   add_action("value","value");
   add_action("list","list");
   add_action("north","north");
}

sell(item) {
    object ob;

    if (!item)
	return 0;
    if (item == "all") {
	object next;
	ob = first_inventory(this_player());
	while(ob) {
	    next = next_inventory(ob);
	    if (!ob->drop() && ob->query_value()) {
		write(ob->short() + ":\t");
		do_sell(ob);
	    }
	    ob = next;
	}
	write("Ok.\n");
	return 1;
    }
    ob = present(item, this_player());
    if (!ob)
	ob = present(item, this_object());
    if (!ob) {
	write("No such item ("); write(item); write(") here.\n");
	return 1;
    }
    do_sell(ob);
    return 1;
}

do_sell(ob) {
    int value, do_destroy;
    value = ob->query_value();
    if (!value) {
	write(ob->short() + " has no value.\n");
	return 1;
    }
    if (environment(ob) == this_player()) {
        int weight;
	if (call_other(ob, "drop", 0)) {
	    write("I can't take it from you!\n");
	    return 1;
	}
        weight = call_other(ob, "query_weight", 0);
	call_other(this_player(), "add_weight", - weight);
    }
   if(value > 6000 || value < 50)
	do_destroy = 1;
    if (value > 1000) {
	write("The shop is low on money...\n");
   value = 1000 + random(400);
    }
    write("You get "); write(value); write(" gold coins.\n");
    say(call_other(this_player(), "query_name", 0) + " sells " +
	call_other(ob, "short", 0) + ".\n");
    call_other(this_player(), "add_money", value);
    if (do_destroy) {
  write("This item is sent to the back store room of the shop.\n");
	destruct(ob);
	return 1;
    }
    call_other("/players/saber/food/store2.c", "store", ob);
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
    if (call_other("/players/saber/food/store2.c", "value", item))
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
    write("You would get "); write(value); write(" gold coins.\n");
    return 1;
}

buy(item) {
    if (!item)
	return 0;
    call_other("/players/saber/food/store2.c", "buy", item);
    return 1;
}

north() {
    if (call_other(this_player(), "query_level", 0) < 25) {
	write("A strong magic force stops you.\n");
	say(call_other(this_player(), "query_name", 0) +
	    " tries to go through the field, but fails.\n");
	return 1;
    }
    write("You wriggle through the force field...\n");
    call_other(this_player(), "move_player", "north#/players/saber/food/store2.c");
    return 1;
}

list(obj) {
    call_other("/players/saber/food/store2.c", "inventory", obj);
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

query_drop_castle() {
    return 1;
}
