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
    return "Your Good Neighbor Pharmacy";
}

init() {
    add_action("move", "east");
    add_action("order", "order");
    add_action("order", "buy");
}

move() {
    object ob;

    call_other(this_player(), "move_player",  "east" + "#" + "players/airwoman/CASTLE/rm1n");
    return 1;
}

long() {
    write("WELCOME TO YOUR GOOD NEIGHBOR PHARMACY!\n");
    write("A large sign here says:\n");
    write("WE RESERVE THE RIGHT TO CHANGE PRICES WITHOUT NOTICE\n\n");
    write("You can order drugs here.\n\n");
    write("              Benadryl          :  10 coins\n"); 
    write("              No DOZE           :  20 coins\n");
    write("              Valium            :  180 coins\n");
    write("              Morphine          :  250 coins\n");
    write("The only obvious exit is east.\n");

}

order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "benadryl") {
        mess = "That feels good";
	heal = 1;
        value = 10;
	strength = 3;
    }
    else if (str == "valium") {
	mess = "A tingling feeling goes through your body";
	heal = 10;
        value = 180;
        strength = 7;
    } else if (str == "morphine") {
	mess = "A shock wave runs through your body";
	heal = 25;
        value = 250;
        strength = 14;
    } else if (str == "no doze") {
	mess = "You feel somewhat invigorated";
	heal = 0;
	value = 20;
	strength = -2;
    } else {
       write("The pharmacist asks:  What would you like?\n");
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
            say(call_other(this_player(), "query_name", 0) + " orders a dose of "+
		str + ", and immediately throws it up.\n");
            write("You order a dose of "  + str + ", and try to intake it, but you throw up.\n");
	} else {
            say(call_other(this_player(), "query_name", 0) + " orders a dose of " + 
		str + ", and spews it all over you!\n");
            write("You order a dose of "+ str +", try to take it, but puke!\n");
	}
	call_other(this_player(), "add_money", - cost);
	return 1;
    }
    if (!call_other(this_player(), "drink_alcohol", strength)) {
        write("The druggist says: Hey buddy, you've had enough.\n");
        say(call_other(this_player(), "query_name", 0) + " asks for a dose of " +
                str + " but the pharmacist refuses.\n");

	return 1;
    }
    write("You pay "+ cost +" coins for a dose of "+ str +".\n");
   say(call_other(this_player(), "query_name", 0) + " orders a dose of "+ str +".\n");
    call_other(this_player(), "add_money", - cost);
    call_other(this_player(), "heal_self", heal);
    write(mess + ".\n");
    return 1;
}
