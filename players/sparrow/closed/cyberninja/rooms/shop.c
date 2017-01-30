inherit "/players/dune/closed/guild/rooms/room";
#include "../DEFS.h"
#include "std_old.h"
#define STORE  "/room/store.c"


do_sell(ob);

init() {
 add_action("sell","sell");
 add_action("value","value");
 add_action("buy","buy");
 add_action("north","north");
 add_action("list","list");
 ::init();
}

reset(arg){
if(!present("board")) {
    move_object(clone_object(BOARDDIR + "/pkboard.c"),
    this_object());
  }

  if(!present(MERCHANT_NPC)) {
    move_object(clone_object(ROOMDIR + "/MerchanT.c"),
    this_object());
  }
  if(!arg){
  set_light(1);
  short_desc="CyberMart";
  long_desc=
"     Here at CyberMart you can purchase items from the\n"+
"Black Market and many other secret underground organizations.\n"+
"Commands are: 'buy item',     'sell item',   'sell all',  'list',\n"+
"              'list weapons', 'list armors', 'value item'.       \n"+
"A sealed security door blocks passage to the north.\n";

  items=({
    "door","Only persons with proper security clearance are allowed north",
  });

  dest_dir=({
    ROOMDIR + "/hallway2.c","south",
    ROOMDIR + "/weaponry.c","east",
    ROOMDIR + "/mechshop.c","down",
    /* Taken out due to Ninja inability to wear armor.
     * ROOMDIR + "/armory.c","west",
     */
  });
  }
}

status sell(string item) {
    object ob;
    object next;
    if(!present(MERCHANT_NPC, environment(TP))) {
      write("The merchant is not present.\n");
      return 1; }
    if (!item)
        return 0;
    if (item == "all") {
        ob = first_inventory(this_player());
        while(ob) {
            next = next_inventory(ob);
            if (!ob->drop() && (int)ob->query_value()) {
                write(ob->short() + ":\t");
                do_sell(ob);
            }
            ob = next;
        }
        write("Ok.\n");
        return 1;
    }
    next = present(item, this_player());
    if (!next)
        next = present(item, this_object());
    if (!next) {
        write("No such item ("); write(item); write(") here.\n");
        return 1;
    }
    do_sell(next);
    return 1;
}

do_sell(ob) {
    int value, do_destroy;
	int value2;
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
    if (value > 3000)
        do_destroy = 1;
    if(ob->query_dest_flag()) do_destroy = 1;
    if (value > 1000) {
        write("The shop is low on money...\n");
		value2 = 1000 + random(100);
		if(value > value2) { value = value2; }
    }
    write("You get "); write(value); write(" gold coins.\n");
    say(call_other(this_player(), "query_name", 0) + " sells " +
        call_other(ob, "short", 0) + ".\n");
    call_other(this_player(), "add_money", value);
    call_other(ob, "add_worth", value);
    if (do_destroy) {
        write("The valuable item is hidden away.\n");
        destruct(ob);
        return 1;
    }
    call_other(STORE, "store", ob);
    return 1;
}

value(item) {
    int value;
    string name_of_item;
    if(!present(MERCHANT_NPC, environment(TP))) {
      write("The merchant is not present.\n");
      return 1; }
    if (!item)
        return 0;
    name_of_item = present(item);
    if (!name_of_item)
      name_of_item = find_item_in_player(item);
    if (!name_of_item) {
        if (call_other(STORE, "value", item))
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
    if(!present(MERCHANT_NPC, environment(TP))) {
      write("The merchant is not present.\n");
      return 1; }
    if (!item)
        return 0;
    call_other(STORE, "buy", item);
    return 1;
}

north() {
    if (call_other(this_player(), "query_level", 0) < 30) {
        write("A strong magic force stops you.\n");
        say(call_other(this_player(), "query_name", 0) +
            " tries in vain to get past the security door.\n");
        return 1;
    }
    write("You wriggle through the force field...\n");
    call_other(this_player(), "move_player",
               "north#"+STORE);
    return 1;
}

list(obj) {
    call_other(STORE, "inventory", obj);
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
