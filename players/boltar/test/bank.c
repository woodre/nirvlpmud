#include "std.h"
string play_name;
object room;

#undef EXTRA_INIT
#define EXTRA_INIT\
    add_action("buy"); add_verb("buy");\
    add_action("visit"); add_verb("visit");
    
ONE_EXIT("room/bank", "down",
         "The bank",
         "You are on the upper floor of the bank.\n" +
	 "You may purchase a safety deposit box for 1000 coins.\n" +
	 "If you already own one, you may visit for 100 coins.\n" +
         "Commands are: 'buy box', 'visit'\n" +
	 "  NOTE:  Not responsible for lost items.\n" + 
	 "         If the MUD goes down, your items are gone.\n\n",1)

buy(item) {
    object box;
    
    if (!item || item != "box")
        return 0;
    room = find_object("players/vayde/bank_vault.c");
    play_name = call_other(this_player(),"query_name",0);
    if (present("box",room)) {
        write("You already own one.\n");
	return 1;
	}
    if (call_other(this_player(), "query_money", 0) < 1000) {
        write("You cannot afford it at this time.\n");
	return 1;
	}
    call_other(this_player(), "add_money", - 1000);
    box = clone_object("players/vayde/safety_box");
    call_other(box,"set_name",play_name);
    move_object(box, "players/vayde/bank_vault");
    call_other(this_player(), "move_player", "west#players/vayde/bank_vault");

    return 1;
}

visit() {
    room = find_object("players/vayde/bank_vault.c");
    play_name = call_other(this_player(),"query_name",0);
    if (!present("box",room)) {
        write("You don't own a box!\n");
	return 1;
	}
    if (call_other(this_player(), "query_money", 0) < 100) {
        write("You cannot afford it at this time.\n");
	return 1;
	}
    call_other(this_player(), "add_money", - 100);
    call_other(this_player(), "move_player", "west#players/vayde/bank_vault");

    return 1;
}

