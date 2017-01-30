#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT\
    add_action("buy","buy");\
    add_action("list","list");

ONE_EXIT("players/rich/surstomai.c", "south",
         "The starfleet supply store(misc. division)",
         "You are in the starfleet surplus store(misc. division).\n" +
         "Try MUDD`S EMPORIUM!!!!! on the lower level.\n" +
         "Commands are: 'buy item', 'list',\n", 1)

buy(item) {
    if (!item)
        return 0;
    call_other("players/rich/surshparm.c", "fill", 0);
    call_other("players/rich/surshparm.c", "buy", item);
    return 1;
}

list(obj) {
    call_other("players/rich/surshparm.c", "fill", 0);
    call_other("players/rich/surshparm.c", "inventory", 0);

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
