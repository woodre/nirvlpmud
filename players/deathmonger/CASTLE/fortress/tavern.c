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
    return "The Undead Bar and Grill";
}

init() {
    add_action("move", "south");
    add_action("order","order");
    add_action("order","buy");
}

move() {
    object ob;

    call_other(this_player(), "move_player",
  "south" + "#" +"players/deathmonger/CASTLE/fortress/corridor1");
     return 1;

}

long() {
    write("This appears to be the place where the undead gather to have fun.\n"+
          "It is a dreary bar and grill, with all kinds of strange monsters\n"+
          "running amok.\n\n");
    write("THE UNDEAD BAR AND GRILL\n");
    write("WE RESERVE THE RIGHT TO CHANGE PRICES WITHOUT NOTICE\n\n");
    write("You can order drinks here.\n\n");
    write("     Human Blood                 10 coins\n");
    write("     Electro-shock Therapy       30 coins\n");
    write("     Arsenic                     175 coins\n");
    write("     Death-in-a-bucket           200 coins\n");
    write("The only obvious exit is south.\n");
}

order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "blood") {
mess = "It doesn`t taste real good, but it`ll get you buzzed";
	heal = 1;
        value = 10;
	strength = 3;
    }
   

    else if (str == "arsenic") {
mess = "You feel like you were hit by a bus.";
heal = 12;
        value = 175;
        strength = 5;
    } else if (str == "death" || str == "bucket") {
mess = "You feel like you were just smashed by a sledge hammer";
        heal = 22;
        value = 200;
        strength = 12;
    } else if (str == "therapy") {
mess = "You start to shake from all the nervous energy you now have";
	heal = 0;
        value = 30;
        strength = -4;
    } else {
       write("The bartender says: We don't serve drinks for the living.\n");
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
write("You`re so far gone you can`t even see the bartender anymore.\n");
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
