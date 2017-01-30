#include "std_old.h"
#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   short_desc = BLK+BOLD+"The shop"+NORM;
   long_desc =
   "You are in a shop. You can buy or sell things here.\n"+
   "Commands are: 'buy item', 'sell item', 'sell all', 'list', 'list weapons'\n"+
   "'list armors' and 'value item'.\n";
   add_item("grass","Nasty crab grass; rotten, and dying.");
   
   add_exit("/players/jaraxle/3rd/alt/rooms/road2.c","south");
   
}

 init() {

   ::init();
    add_action("sell","sell");
    add_action("value","value");
    add_action("buy","buy");
    add_action("list","list");
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
    if (do_destroy) {
    write("The valuable item is hidden away.\n");
        destruct(ob);
        return 1;
    }
   call_other("/players/jaraxle/3rd/alt/rooms/shop_storage.c", "store", ob);
    return 1;
}

value(item) {
    int value;
    string name_of_item;

    if (!item)
        return 0;
    if (!name_of_item)
      name_of_item = find_item_in_player(item);
    if (!name_of_item) {
if (call_other("/players/jaraxle/3rd/warrior/rooms/shop_storage.c", "value", item))
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
   call_other("/players/jaraxle/3rd/alt/rooms/shop_storage.c", "buy", item);
    return 1;
}

list(obj) {
   call_other("/players/jaraxle/3rd/alt/rooms/shop_storage.c", "inventory",
obj);
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
