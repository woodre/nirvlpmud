#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT\
    add_action("sell","sell");\
    add_action("value","value");\
    add_action("buy","buy");\
    add_action("north","north");\
    add_action("list","list");

ONE_EXIT("players/boltar/lv2/wildwest3", "south",
	 "Ye olde western shop",
 "You have entered a general store like those of the old west.\n" +
"Something looks odd about the this place however.\n" +
	 "There is an opening to the north, and some shimmering\n" +
 "green light in the doorway. The only other exit is south.\n" +
 "You can:\n"+
 "            'buy item'          'list' \n"+
 "            'sell item'         'list weapons' \n"+
 "            'value item'        'list armors'  \n"+
"\n", 1)


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
	write(item); write("  is a piece of junk, and this isn't Sanford and son.\n");
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
       int blah;
	write("The shopkeeper is too cheap to give you what it's worth...\n");
	blah = 1000+random(400);
        if(blah < value) value = blah;
    }
    write("You get "); write(value); write(" gold coins.\n");
    say(call_other(this_player(), "query_name", 0) + " sells " +
	call_other(name_of_item, "short", 0) + ".\n");
    call_other(this_player(), "add_money", value);
    call_other("players/boltar/lv2/storeroom", "store", name_of_item);
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
	if (call_other("players/boltar/lv2/storeroom", "value", item))
	    return 1;
	write("No such item ("); write(item); write(") here\n");
	write("or in the store.\n");
	return 1;
    }
    value = call_other(name_of_item, "query_value", 0);
    if (!value) {
	write(item); write("  is a piece of junk, and this isn't Sanford and son.\n");
	return 1;
    }
    if (value < 1510) {
	write("You would get "); write(value); write(" gold coins.\n");
    }
    else {
	write("It's really worth "); write(value); write(" gold coins.\n");
write("But the storekeeper is real cheap, so he'll only give you 1510.\n");
    }
    return 1;
}

buy(item) {
    if (!item)
	return 0;
    call_other("players/boltar/lv2/storeroom", "buy", item);
    return 1;
}

north() {
    if (call_other(this_player(), "query_level", 0) < 21) {
	write("A strong magic force stops you.\n");
	say(call_other(this_player(), "query_name", 0) +
    " tries to go through the field, falls backward, lands on his butt,\n" +
    " and looks stupid.\n");
	return 1;
    }
    write("You wriggle through the force field...\n");
    call_other(this_player(), "move_player", "north#players/boltar/lv2/storeroom");
    return 1;
}

list(obj) {
    call_other("players/boltar/lv2/storeroom", "inventory", obj);
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
