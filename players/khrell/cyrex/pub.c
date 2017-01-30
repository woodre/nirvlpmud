object newspaper, top_list;
object band;

reset(arg) {
    if (!present("go player"))
	move_object(clone_object("obj/go_player"), this_object());
    if (!top_list || !present(top_list)) {
	top_list = clone_object("obj/level_list");
	move_object(top_list, this_object());
    }
/*
    if (!present("bandit")) {
   band = clone_object("obj/bandit");
   move_object(band, this_object());
   }

*/
    if (!newspaper || !present(newspaper)) {
	newspaper = clone_object("obj/newspaper");
	move_object(newspaper, this_object());
    }
    if (arg) return;
    set_light( 1);
}

short() {
    return "The Far-Out pub";
}

init() {
    add_action("move");
    add_verb( "north");
    add_action("order");
    add_verb("order");
    add_action("order");
    add_verb("buy");
}

move() {
    object ob;

    call_other(this_player(), "move_player",  "north" + "#" +"players/cyrex/lounge");
    return 1;
}

long() {
    write("You are in the Far-Out pub.\n");
    write("A large sign here says:\n");
    write("WE RESERVE THE RIGHT TO CHANGE PRICES WITHOUT NOTICE\n\n");
    write("You can order Far-Out drinks here.\n\n");
    write("     First Class Beer    : 100 coins\n");
    write("     Shot of Stunner     :  80 coins\n");
    write("     Zentradi's Special  : 180 coins\n");
    write("     Master's Secret     : 380 coins\n\n");
    write("The only obvious exit is north.\n");
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
        mess = "That feels real good";
        heal = 5;
        value = 100;
	strength = 3;
    }
    else if (str == "special" || str == "Zentradi's special") {
        mess = "A gushing blood flow goes through your body";
	heal = 10;
        value = 180;
        strength = 7;
    } else if (str == "Master's Secret" || str == "secret") {
        mess = "A massive burst of energy runs through your body";
        heal = 38;
        value = 380;
        strength = 15;
    } else if (str == "stunner" || str == "shot of stunner") {
	mess = "You feel somewhat invigorated";
	heal = 0;
        value = 80;
        strength = -4;
    } else {
       write("The bartender says: What do you want?\n");
       return 1;
    }
    if (call_other(this_player(), "query_money", 0) < value) {
        write("That costs " + value + " gold coins, which you don't have.\n");
	return 1;
    }
    cost = value;
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
	call_other(this_player(), "add_money", - cost);
	return 1;
    }
    if (!call_other(this_player(), "drink_alcohol", strength)) {
	write("The bartender says: I think you've had enough.\n");
	say(call_other(this_player(), "query_name", 0) + " asks for a " +
		str + " but the bartender refuses.\n");

	return 1;
    }
    write("You pay " + cost + " coins for a " + str + ".\n");
    say(call_other(this_player(), "query_name", 0) + " orders a " + str + ".\n");
    call_other(this_player(), "add_money", - cost);
    call_other(this_player(), "heal_self", heal);
    write(mess + ".\n");
    return 1;
}
