
reset(arg) {
    set_light( 1);
}

short() {
    return "The first aid station";
}

init() {
    add_action("move","south");
    add_action("order","buy");
    add_action("order","buy");
}

move() {
    object ob;

    call_other(this_player(), "move_player",  "south" + "#" +"players/mistress/lobby/west.c");
    return 1;
}

long() {
    write("\nA friendly nurse looks up with a smile:  How can I help you?\n");
    write("You can purchase healing here.\n\n");
    write("     Witch hazel         :    15 coins\n");
    write("     Cup of coffee       :    20 coins\n");
    write("     Castor oil          :   100 coins\n");
    write("     Codeine Plus        :   300 coins\n\n");
    write("The only obvious exit is to " +  "south" + ".\n");
}

order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Excuse me ?\n");
       return 1;
    }
    if (str == "hazel") {
	mess = "You feel a little better";
	heal = 1;
	value = 15;
	strength = 2;
    }
    else if (str == "castor" || str == "castor oil") {
	mess = "You feel faint from the taste but you quickly revive.";
	heal = 5;
	value = 100;
	strength = 8;
    } else if (str == "codeine" || str == "codeine plus") {
mess = "You feel a sudden rush like you`ve been hit by a freight train";
	heal = 10;
	value = 300;
	strength = 12;
    } else if (str == "coffee" || str == "cup of coffee") {
mess = "Funny how coffee feels better than the medicine";
	heal = 0;
	value = 20;
	strength = -2;
    } else {
       write("The nurse asks you: How can i help you?\n");
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
		str + ", and immediately passes into unconciousness.\n");
	    write("You buy a " + str + ", try to endure it, but faint dead away.\n");
	} else {
	    say(call_other(this_player(), "query_name", 0) + " buys a " +
		str + ", and crumbles in a heap at your feet!\n");
	    write("You buy a " + str + ", try to endure it, and pass out!\n");
	}
	call_other(this_player(), "add_money", - value);
	return 1;
    }
    if (!call_other(this_player(), "drink_alcohol", strength)) {
	write("The nurse says: I don`t think you can take anymore.\n");
	say(call_other(this_player(), "query_name", 0) + " asks for a " +
		str + " but the nurse politely turns him down.\n");

	return 1;
    }
    write("You pay " + value + " coins for a " + str + ".\n");
    say(call_other(this_player(), "query_name", 0) + " buys a " + str + ".\n");
    call_other(this_player(), "add_money", - value);
    call_other(this_player(), "heal_self", heal);
    write(mess + ".\n");
    return 1;
}
