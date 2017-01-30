#include "std_old.h"
string play_name;
string var1, var2, var3;
object store1, store2, store3;
object room;

#undef EXTRA_INIT
#define EXTRA_INIT\
    add_action("start","start");\
    add_action("pay","pay");\
    add_action("pawn","pawn");\
    add_action("list","list");
    
ONE_EXIT("players/boltar/lv2/wildwest3", "west",
         "The wildwest pawn shop",
         "You are in an old style pawn shop.\n" +
 "You may buy back or pawn what you want.\n" +
  "However you must start an account to pawn anything." +
  "\n" +
     "Commands available are: 'start', 'pawn <item>', 'list', and 'pay <item>'\n" +
      "The list command shows only the items you have pawned, only the player who\n" +
     "pawned the item can see what he has pawned or buy it back.\n"+
     "You are charged 10% interest on all items pawned when you return for them." +
"\n" +
     "not responsible for items left over .1 seconds." +
"\n" +
"If this Mudworld collapses upon itself into nothingness, all the items you\n" +
"have pawned and your account are gone forever.\n",1)

start() {
    object box;
    
    call_other("players/boltar/lv2/pawnstorage.c", "short", 0);
    room = find_object("players/boltar/lv2/pawnstorage.c");
    play_name = call_other(this_player(),"query_name",0);
    if (present("box",room)) {
        write("You already have an account.\n");
	return 1;
	}
    box = clone_object("players/boltar/things/pawnholder");
    call_other(box,"set_name",play_name);
   move_object(box, "players/boltar/lv2/pawnstorage");
   write("Your account has been made.\n");

    return 1;
}

pay(item) {
string qaw;
    call_other("players/boltar/lv2/pawnstorage.c", "short", 0);
    room = find_object("players/boltar/lv2/pawnstorage.c");
    play_name = call_other(this_player(),"query_name",0);
    if (!present("box",room)) {
        write("You you don't have an account.\n");
	return 1;
	}
      play_name = call_other(this_player(), "query_name",0);
    if (!item)
	return 0;
  qaw = play_name+"holder"+" ?? "+item;
    call_other("players/boltar/lv2/pawnstorage", "buy", qaw);
    return 1;
}

pawn(item) {
    int value;
    string name_of_item, sendstr, play_name;
    object ob;

    
    call_other("players/boltar/lv2/pawnstorage.c", "short", 0);
    room = find_object("players/boltar/lv2/pawnstorage.c");
    play_name = call_other(this_player(),"query_name",0);
    if (!present("box",room)) {
        write("You don't have an account.\n");
	return 1;
	}
    play_name = call_other(this_player(),"query_name",0);
    if (!item)
	return 0;
    name_of_item = present(item, this_player());
    if (!name_of_item)
      name_of_item = find_item_in_player(item);
    if (!name_of_item) {
	write("No such item ("); write(item); write(") here.\n");
	return 1;
    }
    value = call_other(name_of_item, "query_value", 0);
    if (!value) {
	write(item); write(" has no value and cannot be pawned.\n");
	return 1;
    }
    if (value < 100) {
    write(item); write(" we dont buy any cheap stuff here.\n");
    return 1;
    }
    if (environment(name_of_item) == this_player()) {
        int weight;
	if (call_other(name_of_item, "drop", 0)) {
	    write("I can't take it from you!\n");
	    return 1;
	}
        weight = call_other(name_of_item, "query_weight", 0);
	call_other(this_player(), "add_weight", - weight);
    }
    if (value > 1000) {
	write("The pawn broker will not give more than 1000 coins per item.\n");
value = 1000;
    }
    store(name_of_item);
    write("You get "); write(value); write(" gold coins.\n");
    say(call_other(this_player(), "query_name", 0) + " pawns " +
	call_other(name_of_item, "short", 0) + ".\n");
/*
write_file("/open/boltar/pawn.log", this_player()->query_name()+" pawns "+name_of_item->short()+" for "+value+"\n");
*/
    call_other(this_player(), "add_money", value);
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
list(obj) {
    
    call_other("players/boltar/lv2/pawnstorage.c", "short", 0);
    room = find_object("players/boltar/lv2/pawnstorage.c");
    play_name = call_other(this_player(),"query_name",0);
    if (!present("box",room)) {
        write("You don't have an account.\n");
	return 1;
	}
    call_other("players/boltar/lv2/pawnstorage", "inventory", obj);
    return 1;
}

store(item)
{
    object ob;
     string hold, pl_nam, hold2;
     pl_nam = call_other(this_player(), "query_name",0);
  hold = pl_nam+"holder";

     hold2 = present(hold, find_object("players/boltar/lv2/pawnstorage.c"));
     move_object(item, hold2);
	    return;
  }
