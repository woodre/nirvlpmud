object newspaper, top_list;
object band;

reset(arg) {
    if (arg) return;
    set_light( 1);
}

short() {
return "The local Graffx Shop";
}

init() {
    add_action("move", "west");
    add_action("order","order");
    add_action("order","buy");
}

move() {
    object ob;

call_other(this_player(), "move_player", "west" + "#" +"players/nightshade/room/shoprd");
    return 1;
}

long() {
write("This is the local Graffx Shop. You see bongs of all types\n"+
      "lining the walls and shelves. One in particular is a five\n"+
      "foot mother called the Executioner. If you are lucky you\n"+
      "might be able to score a quarter bag or maybe just a single\n"+
      "joint.\n");
write("     Funky herbal tea     :   20 coins\n");
write("     Small joint          :   10 coins\n");
write("     Medium joint         :  150 coins\n");
write("     Bob Marley Special   :  230 coins\n");
}

order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
write("Hippy Dood says: Psst! What did you want?\n");
       return 1;
    }
    if (str == "small") {
mess = "You body begins to spasm a little bit, but you like it";
	heal = 1;
        value = 10;
	strength = 3;
    }
    else if (str == "medium" || str == "special of the house") {
mess = "You feel yourself becoming one with the earth and all its vibrations";
	heal = 10;
        value = 150;
        strength = 7;
    } else if (str == "bob" || str == "bob") {
mess = "You are now one with the entire universe. You feel a wave of pure cosmic energy flow through your body. A severed ponytail with a red ribbon tied around it floats past you";
	heal = 25;
        value = 230;
        strength = 14;
    } else if (str == "tea" || str == "cup of coffee") {
mess = "The tea is tangy and refreshing";
	heal = 0;
	value = 20;
	strength = -2;
    } else {
write("Hippy Dood says: SSSSHHH! Not so loud. What did you want again?\n");
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
		str + ", and immediately throws up.\n");
	    write("You order a " + str + ", try to smoke it, and throw up.\n");
	} else {
	    say(call_other(this_player(), "query_name", 0) + " orders a " +
		str + ", and spews chunks all over you!\n");
	    write("You order a " + str + ", try to smoke it, and sputter it all over the room!\n");
	}
	call_other(this_player(), "add_money", - cost);
	return 1;
    }
    if (!call_other(this_player(), "drink_alcohol", strength)) {
write("Hippy Dood says: Woahh. You are to stoned at the moment for that.\n");
	say(call_other(this_player(), "query_name", 0) + " asks for a " +
		str + " but the Hippy Dood refuses.\n");

	return 1;
    }
    write("You pay " + cost + " coins for a " + str + ".\n");
    say(call_other(this_player(), "query_name", 0) + " orders a " + str + ".\n");
    call_other(this_player(), "add_money", - cost);
    call_other(this_player(), "heal_self", heal);
    write(mess + ".\n");
    return 1;
}