#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT\
    add_action("buy","buy");\
    add_action("list","list");

ONE_EXIT("players/mistress/lobby/east", "north",
         "Magic and mystery",
         "\n" +
         "You are in the forbidden part of the library.  Books on magic are\n" +
         "kept here.  There are more shelves to the south...\n" +
         "Commands are: 'buy item', 'list',\n", 1)

buy(item) {
    if (!item)
        return 0;
    call_other("players/mistress/lobby/mymagic.c", "fill", 0);
    call_other("players/mistress/lobby/mymagic.c", "buy", item);
    return 1;
}

list(obj) {
    call_other("players/mistress/lobby/mymagic.c", "fill", 0);
    call_other("players/mistress/lobby/mymagic.c", "inventory", obj);
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
