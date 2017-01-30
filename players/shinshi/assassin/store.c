#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT\
   add_action("buy", "buy");\
   add_action("list", "list");

ONE_EXIT("players/shinshi/assassin/tavern", "north",
         "The Assassin Store",
         "This is the Assassin Store, serving your daily assassin needs.\n"+
         "Commands are: 'buy item', 'list',\n", 1)

buy(item) {
    if (!item)
        return 0;
    call_other("players/shinshi/assassin/storeroom","fill", 0);
    call_other("players/shinshi/assassin/storeroom","buy",item);
    return 1;
}

list(obj) {
    call_other("players/shinshi/assassin/storeroom","fill",0);
    call_other("players/shinshi/assassin/storeroom","inventory",obj);
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
