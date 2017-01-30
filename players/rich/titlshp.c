#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT\
    add_action("buy","buy");\
    add_action("list","list");

ONE_EXIT("players/rich/medshop.c", "south",
         "The title change store",
         "You are in a title change store. You can buy a title change here.\n" +
         "Try the starfleet surplus store!!!! just west of the shop.\n" +
         "Commands are: 'buy item', 'list',\n", 1)

buy(item) {
    if (!item)
        return 0;
    call_other("players/rich/titlsto.c", "fill", 0);
    call_other("players/rich/titlsto.c", "buy", item);
    return 1;
}

list(obj) {
    call_other("players/rich/titlsto.c", "fill", 0);
    call_other("players/rich/titlsto.c", "inventory", 0);

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
