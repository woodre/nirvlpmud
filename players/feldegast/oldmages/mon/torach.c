/*
File: torach.c
A merchant who will buy/sell stuff.
*/

#include "/players/feldegast/defines.h"
inherit "obj/monster";

string backroom;

reset(arg) {
  set_name("torach");
  set_alias("merchant");
  set_short(MAG+"Torach the Acquirer"+NORM);
  set_race("unknown");
  set_long(
"Torach is a stout being, tightly wrapped in a bulky cloak that\n\
conceals all traces of his features.  A huge pack, filled with\n\
assorted items from across the realms, is strapped to his hunched\n\
back.  Torach is a merchant by trade, and will buy and sell items.\n");
  set_level(15);
  set_hp(300);
  set_heal(30,2);
  set_wc(15);
  set_ac(7);
  backroom="/players/feldegast/arena/rooms/backroom.c";
}
heartbeat() {
  ::heartbeat();
  if(attacker_ob) {
    tell_room(environment(),
"Torach the Acquirer sees that he is unwelcome here and leaves.\n");
    move_object(this_object(),"/players/feldegast/realm/void");
  }
}
init() {
    add_action("sell","sell");
    add_action("value","value");
    add_action("buy","buy");
    add_action("list"); add_verb("list");
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
    int bonus;

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
	write("Torach balks at the price you ask...\n");
	value = 1000;
    }

/* Torach is a good trader. */
    if(random(this_player()->query_attrib("int")) < 18) {
      bonus=-random(value*3/10);
      write("Torach dazzles you with his silvery tongue. ["+bonus+"]\n");
      value+=bonus;
    }

    if(random(this_player()->query_attrib("wil")) < 5) {
      bonus=-random(value/10);
      write("Torach looks at "+ob->short()+".\n\"I don't know...I seem to see alot of those.\" ["+bonus+"]\n");
      value+=bonus;
    }
    if(random(this_player()->query_attrib("pie")) > 17) {
      bonus=random(value/10);
      write(
"You point out to Torach the numerous expenses involved in gaining\n"+
"the object in question, not to mention risk to life and limb,\n"+
"insurance, and other hazards of the adventurer's life.  ["+bonus+"]\n");
      value+=bonus;
    }
    if(random(this_player()->query_attrib("luc")) < 5) {
      bonus=-random(value/10);
      write(
"Torach grumbles about all the trouble it took to arrive at this out\n"+
"of the way location. ["+bonus+"]\n");
      value+=bonus;
    }
    if(random(this_player()->query_attrib("ste")) > 18) {
      bonus=random(value/10);
      write("You catch Torach miscounting coins.  He acts contrite and agrees\n"+
            "to give you more. ["+bonus+"]\n");
      value+=bonus;
    }

    write("Torach gives you "); write(value); write(" gold coins in exchange for "+ob->short()+".\n");
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
    if (!item)
	return 0;
    call_other(backroom,"buy",item);
    return 1;
}

list(obj) {
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

