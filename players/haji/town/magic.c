#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT new_init();

ONE_EXIT("players/haji/town/road2.c", "east",
         "The magic shop",
         "You are in Aladdin's Magic Shop. You can buy spells and items here.\n" +
         "Commands are: 'buy item', 'list',\n", 1)

new_init() {
    add_action("buy","buy");
    add_action("list","list");
}

buy(item) {
    if (!item)
        return 0;
    call_other("players/morgar/magicstore", "fill", 0);
    call_other("players/morgar/magicstore", "buy", item);
    return 1;
}

list(obj) {
    call_other("players/morgar/magicstore", "fill", 0);
    call_other("players/morgar/magicstore", "inventory", obj);
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
