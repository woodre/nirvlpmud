#include "/players/eurale/closed/ansi.h"
#define tp this_player()

reset(arg) {
    if (arg) return;
    set_light( 1);
}

short() {
  return "The "+BOLD+GRN+"Druid Pub"+NORM;
}

init() {
  add_action("east","east");
  add_action("order","order");
}

east() {
  tp->move_player("east#players/eurale/Druid/df10.c");
    return 1;
}

long() {
  write("                 You are in the "+BOLD+GRN+"Druid Pub"+NORM+"\n");
    write("               A large wooden sign here says:\n");
  write(" \n");
    write("      WE RESERVE THE RIGHT TO CHANGE PRICES WITHOUT NOTICE\n\n");
  write("         You can [order] the following libations here.\n\n");
  write("		Gin Sing Tea		:     10 coins\n");
  write("		Dandelion Wine		:    150 coins\n");
  write("		Barley Malt Brew	:    230 coins\n");
  write("		Bitterroot		:     20 coins\n");
  write(" \n");
    write("               The only obvious exit is "+BOLD+"east"+NORM+".\n");
}

order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "tea") {
	mess = "That feels good";
	heal = 1;
        value = 10;
	strength = 3;
    }
    else if (str == "wine" || str == "dandelion wine") {
	mess = "A tingling feeling goes through your body";
	heal = 10;
        value = 150;
        strength = 7;
    } else if (str == "brew" || str == "malt brew") {
	mess = "A shock wave runs through your body";
	heal = 25;
        value = 230;
        strength = 14;
    } else if (str == "bitterroot" || str == "root") {
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
