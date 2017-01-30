object newspaper, top_list;

reset(arg) {
    if (!top_list || !present(top_list)) {
	top_list = clone_object("obj/level_list");
	move_object(top_list, this_object());
    }
    if (!newspaper || !present(newspaper)) {
	newspaper = clone_object("obj/newspaper");
	move_object(newspaper, this_object());
    }
    if (arg) return;
    set_light( 1);
}

short() {
    return "10 forward";
}

init() {
    add_action("move","south");
    add_action("order","order");
    add_action("order","buy");
}

move() {
    object ob;

    call_other(this_player(), "move_player",  "south" + "#" +"players/rich/hall5.c");
    return 1;
}

long() {
    write("You are in 10 forward.\n");
    write("You can order drinks here.\n\n");
    write("     synthehol                :  15 coins\n");
    write("     Cup of coffee            :  20 coins\n");
    write("     Romulan Ale              :  100 coins\n");
    write("     Saurian Brandy           :  300 coins\n\n");
    write("The only obvious exit is to " +  "south" + ".\n");
}

order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "synthehol") {
	mess = "That feels good";
	heal = 1;
	value = 15;
	strength = 2;
    }
    else if (str == "ale" || str == "romulan ale") {
	mess = "A tingling feeling goes through your body";
	heal = 5;
	value = 100;
	strength = 8;
    } else if (str == "saurian brandy" || str == "brandy") {
	mess = "A shock wave runs through your body";
	heal = 10;
	value = 300;
	strength = 12;
    } else if (str == "coffee" || str == "cup of coffee") {
	mess = "You feel somewhat invigorated";
	heal = 0;
	value = 20;
	strength = -2;
    } else {
       write("The bartender says: What do you want?\n");
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
	    write("You order a " + str + ", try to drink it, and throw up.\n");
	} else {
	    say(call_other(this_player(), "query_name", 0) + " orders a " +
		str + ", and spews it all over you!\n");
	    write("You order a " + str + ", try to drink it, and sputter it all over the room!\n");
	}
	call_other(this_player(), "add_money", - value);
	return 1;
    }
    if (!call_other(this_player(), "drink_alcohol", strength)) {
	write("The bartender says: I think you've had enough.\n");
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
realm(){return "enterprise";}
