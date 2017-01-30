#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT\
    add_action("buy"); add_verb("buy");\
    add_action("list"); add_verb("list");

ONE_EXIT("players/rumplemintz/room/elevall/room1","east",
	"Elevallie Armory",
	"You are in the Elevallie Armory.  You can buy armor here.\n"+
         "Commands are: 'buy <item>', 'list',\n", 1)

buy(item) {
    if (!item)
        return 0;
    call_other("players/rumplemintz/room/elevall/armorystore", "fill", 0);
    call_other("players/rumplemintz/room/elevall/armorystore", "buy", item);
    return 1;
}

list(obj) {
    call_other("players/rumplemintz/room/elevall/armorystore", "fill", 0);
    call_other("players/rumplemintz/room/elevall/armorystore", "inventory", obj);
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
