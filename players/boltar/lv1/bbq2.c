object newspaper, top_list;

reset(arg) {
    if (!present("go player"))
	move_object(clone_object("obj/go_player"), this_object());
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
    return "The backyard deck";
}

init() {
    add_action("move", "east");
    add_action("order","order");
    add_action("order","buy");
}

move() {
    object ob;

    call_other(this_player(), "move_player",  "east" + "#" +"players/boltar/lv1/nixonroom");
    return 1;
}

long() {
    write("You are outside about 20 feet above the ground on the rear deck of The Big House There is a barbaque here .\n");
    write("You can order food here.\n\n");
write(" Hot dogs from the Grill :   8 coins\n");
    write("        Hamburger        :  24 coins\n");
    write("           Ribs          :  55 coins\n");
    write(" Ribs with special sauce : 145 coins\n\n");
    write("The only obvious exit is to " +  "east" + ".\n");
}

order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "hot dog") {
	mess = "That tasted great";
	heal = 1;
	value = 8;
	strength = 0;
    }
    else if (str == "hamburger" || str == "special of the house") {
	mess = "That was the best burger you have ever eaten";
	heal = 4;
	value = 24;
	strength = 0;
    } else if (str == "ribs with special sauce" || str == "special") {
	mess = "A shock wave runs through your body. That's some sauce!";
	heal = 25;
	value = 145;
	strength = 12;
    } else if (str == "ribs" || str == "cup of coffee") {
	mess = "The best bbq ribs you ever had.";
	heal = 6;
	value = 55;
	strength = 0;
    } else {
       write("The cook says: Only what's on the grill buddy.\n");
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
	    write("You order a " + str + ", try to eat it, and throw up.\n");
	} else {
	    say(call_other(this_player(), "query_name", 0) + " orders a " +
		str + ", and spews it all over you!\n");
	    write("You order a " + str + ", try to eat it, and sputter it all over the room!\n");
	}
	call_other(this_player(), "add_money", - value);
	return 1;
    }
    if (!call_other(this_player(), "drink_alcohol", strength)) {
	write("The cook says: That's enough special sauce for you!\n");
	say(call_other(this_player(), "query_name", 0) + " asks for a " +
		str + " but the cook refuses.\n");

	return 1;
    }
    write("You pay " + value + " coins for a " + str + ".\n");
    say(call_other(this_player(), "query_name", 0) + " orders a " + str + ".\n");
    call_other(this_player(), "add_money", - value);
    call_other(this_player(), "heal_self", heal);
    write(mess + ".\n");
    return 1;
}
