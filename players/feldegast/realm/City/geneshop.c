/*
File: geneshop.c
Author: Feldegast
Date: 02/04/98
Revised: 03/23/02
Description:
  A generic shop.  Originally from the arena.
*/

#include "defs.h"

inherit ROOM;

string backroom;

init() {
    ::init();
    add_action("sell","sell");
    add_action("value","value");
    add_action("buy","buy");
    add_action("list","list");
}

reset(arg) {
  if(arg) return;
  if(!present("gene")) {
    object gene;
    gene=clone_object("/players/feldegast/mon/gene");
    move_object(gene,this_object());
  }
  backroom=PATH+"backroom.c";
  short_desc="Gene Eric's Shop";
  long_desc=
"    This is a middling large pawn shop stuffed wall-to-wall with\n"+
"assorted pieces of junk next to precious objets d'art.  A counter\n"+
"near the back has a sign on it.  A door leads west, back out into\n"+
"the marketplace.\n";
  items=({
     "sign",
"The sign says:\n"+
"\tWelcome to Gene Eric's pawn shop!\n"+
"\tYou may: list, value, buy, sell",
  });
  dest_dir=({
    PATH+"crtyard","west"
  });
  set_light(1);
}


sell(item) {
    object ob;

    if(!present("shopkeeper")) return 0;

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
    if (value > 6000)
	do_destroy = 1;
    if(ob->query_dest_flag()) do_destroy = 1;
    if (value > 1000) {
	write("The shop is low on money...\n");
	value = 1000;
    }
    write("You get "); write(value); write(" gold coins.\n");
    say(call_other(this_player(), "query_name", 0) + " sells " +
	call_other(ob, "short", 0) + ".\n");
    call_other(this_player(), "add_money", value);
/* add_worth(value, ob); */
    if (do_destroy) {
	write("The valuable item is hidden away.\n");
	destruct(ob);
	return 1;
    }
    call_other(backroom,"store",ob);
    return 1;
}

value(item) {
    int value;
    string name_of_item;

    if(!present("shopkeeper")) return 0;

    if (!item)
	return 0;
    name_of_item = present(item);
    if (!name_of_item)
      name_of_item = find_item_in_player(item);
    if (!name_of_item) {
        if(call_other(backroom,"value",item))
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
    if(!present("shopkeeper")) return 0;
    if (!item)
	return 0;
    call_other(backroom,"buy",item);
    return 1;
}

list(obj) {
    if(!present("shopkeeper")) return 0;
    call_other(backroom,"inventory",obj);
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
