#include "std.h"

#undef EXTRA_INIT
#define EXTRA_INIT\
    add_action("buy"); add_verb("buy");\
    add_action("list"); add_verb("list");

#undef EXTRA_RESET
#define EXTRA_RESET\
   if(!present("coins")) {\
      object money;\
      money = clone_object("players/rumplemintz/obj/utmoney");\
      money->set_money(random(100) + 399);\
      move_object(money, this_object());\
   }

ONE_EXIT("players/rumplemintz/room/elevall/room3","west",
	"Elevallie Magic Shop",
	"You are in the Elevallie Magic Shop.  You can buy certain magic things here.\n"+
         "Commands are: 'buy <item>', 'list',\n", 1)

buy(item) {
    if (!item)
        return 0;
    call_other("players/rumplemintz/room/elevall/magicstore", "fill", 0);
    call_other("players/rumplemintz/room/elevall/magicstore", "buy", item);
    return 1;
}

list(obj) {
    call_other("players/rumplemintz/room/elevall/magicstore", "fill", 0);
    call_other("players/rumplemintz/room/elevall/magicstore", "inventory", obj);
    return 1;
}
