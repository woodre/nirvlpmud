#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT\
    add_action("buy"); add_verb("buy");\
    add_action("list"); add_verb("list");

FOUR_EXIT("players/boltar/templar/enter", "south",
         "players/boltar/templar/donate", "east",
         "players/saber/ryllian/portal", "west",
         "players/boltar/templar/weaponsmith", "north",
         "The Templar Armory",
         "This is the Templar Armory, a small old man sits behind a set\n"+
         "of iron bars with the inventory awaiting your order.\n"+
         "There is a glowing portal to the west which appears to exit the castle.\n"+
         "Commands are: 'buy item', 'list',\n", 1)

buy(item) {
    if (!item)
        return 0;
    call_other("players/boltar/templar/armorystore", "fill", 0);
    call_other("players/boltar/templar/armorystore", "buy", item);
    return 1;
}

list(obj) {
    call_other("players/boltar/templar/armorystore", "fill", 0);
    call_other("players/boltar/templar/armorystore", "inventory", obj);
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
