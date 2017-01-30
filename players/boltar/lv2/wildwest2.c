object newspaper, top_list;

reset(arg) {
    if (!present("maverick"))
	move_object(clone_object("players/boltar/things/mmv2.c"), this_object());
    if (arg) return;
    set_light( 1);
}

short() {
    return "An old wild west saloon.";
}

init() {
    add_action("move", "west");
    add_action("order", "order");
    add_action("order", "buy");
}

move() {
    object ob;

    call_other(this_player(), "move_player",  "west" + "#" +"players/boltar/lv2/wildwest");
    return 1;
}

long() {
write(" Here you see a typical saloon of the old west.\n");
write(" The drinks here are really strong and sometimes don't taste too good.\n");
write(" A sign on the wall behind the bar reads 'Hangovers installed and Serviced'\n");
write("\n");
write("               'weak'  whiskey          [ 100 coins ]\n");
write("               Weasel's old no. 7       [ 190 coins ]\n");
write("                Old Red Eye             [ 300 coins ]\n");
write("                 X   X   X              [ 500 coins ]\n");
write("           Strongest Coffee in the west [  40 coins ]\n");
write("\n");
write("The classic saloon doors are to the " + "west" + " \n");
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
    if (str == "whiskey") {
	mess = "That feels good";
	heal = 10;
	value = 100;
	strength = 12;
    }
    else if (str == "old red eye" || str == "red eye") {
	mess = "You feel like your blood is boiling!!! Your eyes turn bloodshot.";
	heal = 30;
	value = 300;
	strength = 20;
    } else if (str == "x x x" || str == "xxx") {
	mess = "A shock wave runs through your body. And then some. You feel like you just drank 120 octane fuel.";
	heal = 55;
	value = 500;
	strength = 20;
    } else if (str == "weasel's old no. 7" || str == "7") {
mess = "This chem. lab stuff sure tastes great.";
heal = 20;
value = 190;
strength = 15;
    } else if (str == "coffee" || str == "cup of coffee") {
	mess = "You feel somewhat invigorated";
	heal = 0;
	value = 40;
	strength = -6;
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
