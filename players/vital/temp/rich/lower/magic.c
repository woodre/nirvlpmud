#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT\
    add_action("buy"); add_verb("buy");\
    add_action("list"); add_verb("list");

ONE_EXIT("players/rich/lower/hall1d.c", "west",
         "Mudd`s Emporium",
         "You are in Mudd`s Emporium. You can buy spells and items here.\n" +
         "Commands are: 'buy item', 'list',\n", 1)

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
realm(){return "enterprise";}
