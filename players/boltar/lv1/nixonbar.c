object lotto,newspaper, top_list;

reset(arg) {
    if (!top_list || !present(top_list)) {
	top_list = clone_object("obj/level_list");
	move_object(top_list, this_object());
    }
   if(!lotto || !living(lotto)) {
     lotto = clone_object("players/boltar/things/lotto");
    move_object(lotto,this_object());
   }
    if (!newspaper || !present(newspaper)) {
	newspaper = clone_object("obj/newspaper");
	move_object(newspaper, this_object());
    }
    if (arg) return;
    set_light( 1);
}

short() {
    return "Nixon's PRIVATE bar";
}

init() {
    add_action("move", "east");
    add_action("order", "order");
    add_action("order", "buy");
}

move() {
    object ob;

    call_other(this_player(), "move_player",  "east" + "#" +"players/boltar/lv1/nixonroom");
    return 1;
}

long() {
  write("You have entered the very nice PRIVATE bar of the one and only Richard Nixon.\n" +
  "You aren't one of the ex-presidents friends, but the bartender will sell you a\n" +
  "few drinks.\n\n");
write("A fine imported beer      { 25 gold coins }\n");
write("Nixon's favorite          { 50 gold coins }\n");
write("A fine imported red wine  { 100 gold coins}\n");
write("20 year-old scotch        { 200 gold coins}\n");
write("\n");
    write("The bar's exit is to " +  "east" + ".\n");
write("\n");
}

order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "beer") {
	mess = "That tasted great";
	heal = 1;
	value = 25;
	strength = 5;
    }
    else if (str == "favorite" || str == "nixon's favorite") {
mess = "You can tell Nixon doesn't know what a good drink is";
	heal = 2;
	value = 50;
	strength = 6;
    } else if (str == "fine red wine" || str == "wine") {
mess = "A very fine red wine indeed.";
	heal = 5;
	value = 100;
	strength = 9;
    } else if (str == "scotch" || str == "20 year-old scotch") {
mess = "That was a good well-aged drink";
	heal = 10;
	value = 200;
	strength = 12;
    } else {
       write("The bartender says: You are not one of the pres's friends so I'm not making\n" +
      "anything special.\n");
       return 1;
    }
    if (call_other(this_player(), "query_money", 0) < value) {
        write("That costs " + value + " gold coins, which you don't have.\n");
	return 1;
    }
    if (strength > (call_other(this_player(), "query_level") + 2)) {
	if (strength > (call_other(this_player(), "query_level") + 5)) {
	    /* This drink is *much* too strong for the player */
	    say(call_other(this_player(), "query_name", 0) + " orders a " +
		str + ", and immediately throws it up.\n");
	    write("You order a " + str + ", try to drink it, and put it back down. (it's too strong).\n");
	} else {
	    say(call_other(this_player(), "query_name", 0) + " orders a " +
		str + ", and is too weak to drink it\n");
	    write("You order a " + str + ", try to drink it, and put it back down. (it's too strong)\n");
	}
	call_other(this_player(), "add_money", - value);
	return 1;
    }
    if (!call_other(this_player(), "drink_alcohol", strength)) {
	write("The bartender says: That's enough for you. Know when to say when.\n");
	say(call_other(this_player(), "query_name", 0) + " asks for a " +
		str + " but the bartender refuses.\n");

	return 1;
    }
    write("You pay " + value + " coins for a " + str + ".\n");
    say(call_other(this_player(), "query_name", 0) + " orders a " + str + ".\n");
    call_other(this_player(), "add_money", - value);
    call_other(this_player(), "heal_self", heal);
    write(mess + ".\n");
    return 1;
}
