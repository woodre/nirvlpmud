#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT\
    add_action("buy","buy");\
    add_action("list","list");

ONE_EXIT("players/rich/shop.c", "up",
         "The photon torpedo room",
            "This is the photon torpedo room.\n" +
            "Before you you see a photon torpedo launch tube.\n" +
            "If there is another player that you really can`t stand,\n" +
            "Then take out your frustrations with them and blow them out\n" +
            "with everyone`s best friend,the photon torpedo.You have the option \n" +
            "of knocking off 25,50% of a players current hp pending on\n"  +
            "which torpedo you buy.To buy type buy percentage(ex. buy 50)\n" +
            "This would cost 7500 coins but it takes away 50% hp.\n" +
            "When you buy a torpedo you get a key which u can use at your leisure.\n" +
            "And just remember folks i don`t want to make money....\n " +
            "I just love to sell torpedoes!!!\n" +
         "Commands are: 'buy item', 'list',\n", 1)

buy(item) {
    if (!item)
        return 0;
    call_other("players/rich/torpstore.c", "fill", 0);
    call_other("players/rich/torpstore.c", "buy", item);
    return 1;
}

list(obj) {
    call_other("players/rich/torpstore.c", "fill", 0);
    call_other("players/rich/torpstore.c", "inventory", 0);

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
