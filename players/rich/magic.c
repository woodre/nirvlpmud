#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT\
    add_action("list","list");

ONE_EXIT("room/yard", "south",
         "The magic shop",
         "You are in a magic shop. You can buy spells and items here.\n" +
         "Commands are: 'buy item', 'list',\n", 1)

buy(item) {
    if (!item)
        return 0;
    call_other("room/morgar/magicstore", "fill", 0);
    call_other("room/morgar/magicstore", "buy", item);
    return 1;
}

list(obj) {
    call_other("room/morgar/magicstore", "fill", 0);
    call_other("room/morgar/magicstore", "inventory", obj);
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
