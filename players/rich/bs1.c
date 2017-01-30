#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT\
    add_action("buy","buy");\
    add_action("list","list");

ONE_EXIT("players/rich/surstomai.c", "east",
         "The starfleet surplus store(weapons division)",
         "You are in a starfleet surplus store. You can buy weapons here.\n" +
         "Weapons bought here tend to be more effective on Enterprise,\n" +
         "but are still very effective outside the Enterprise.\n" +
         "Commands are: 'buy item', 'list',\n", 1)

buy(item) {
    if (!item)
        return 0;
    call_other("players/rich/bs.c", "fill", 0);
    call_other("players/rich/bs.c", "buy", item);
    return 1;
}

list(obj) {
    call_other("players/rich/bs.c", "fill", 0);
    call_other("players/rich/bs.c", "inventory", obj);
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
