inherit "/room/room";
#include "/players/pain/color.h"
#define tp this_player()

reset(arg) {
if (arg) return;
set_light( 1);
short_desc = "The "+RED+"Bar"+END;
long_desc = 
	"You have entered the Club's "+RED+"Bar"+END+".\n"+
	"It is quite serene with its dark woods, leather bar stools,\n"+
	"and dim lighting. The brass bar rail shines brightly, cheerfully\n"+
	"inviting you to have a drink. The bartender is quite capable, and\n"+
	"is more than willing to serve you whatever you like. You see a\n"+
	"drink list on the bar with the prices and descriptions.\n"+
	"There is a large drain in the middle of the floor.\n";
items = ({
	"drain", "A large drain in the floor.\n"+
		"Perhaps you could \"squeeze\" yourself into it?",
	"stool", "A set of handsome bar stools with leather seats",
	"stools", "A set of handsome bar stools with leather seats",
	"bar stool", "A set of handsome bar stools with leather seats",	
	"bar stools", "A set of handsome bar stools with leather seats",
	"rail", "A brightly polished brass bar rail, you can see yourself"+
		"in it",	
	"bar rail", "A brightly polished brass bar rail, you can see yourself"+                     "in it",
	"list", "An ornately hand written list of the drinks available at the"+
		" bar:\n\n"+LIGHT_BLUE+
		"\tA Domestic Beer          50 coins\n"+
		"\tAn Imported Beer        150 coins\n"+
		"\tA Rum & Coke            250 coins\n"+
		"\tA Latte                  50 coins\n\n"+END+
		"All prices include tax, <order> whatever you like",
	"drink list", "A hand written list of the drinks available at the"+
                " bar:\n\n"+LIGHT_BLUE+
                "\tA Domestic Beer          50 coins\n"+
                "\tAn Imported Beer        150 coins\n"+
                "\tA Rum & Coke            250 coins\n"+
                "\tA Latte                  50 coins\n\n"+END+
                "All prices include tax, <order> whatever you like",
});
dest_dir = 
	({
	"/players/pain/tiny/entrance", "south",
	"/players/pain/tiny/tr4", "east",
	"/players/pain/tiny/tr5", "west",
	"/players/pain/tiny/tr6", "north",
	});
}

init() {
	::init();
	add_action("listen", "listen");
	add_action("smell", "smell");
	add_action("order","order");
	add_action("squeeze","squeeze");
}

listen() {
write("You hear the clinking of glasses, the occasional pouring of a drink,\n"+
	"and the chatter of club members.\n");
return 1;
}

smell() {
write("You can smell whiskey, vodka, brandy, all manner of liqour, and even\n"+
	"whiff of cigarrette smoke here and there.\n");
return 1;
}

squeeze(str) {
if(!str || str != "into drain") {
	write("Perhaps you should \"squeeze into drain\"?\n");
	return 1;
}
write("You squeeze yourself into the drain .... AND....\n");
("players/pavlik/tiny/enter.c")->sewer_enter(1);
  return 1;
}


order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "domestic" || str == "domestic beer") {
	mess = "That feels good";
	heal = 1;
        value = 50;
	strength = 3;
    }
    else if (str == "imported" || str == "imported beer") {
	mess = "A tingling feeling goes through your body";
	heal = 10;
        value = 150;
        strength = 7;
    } else if (str == "coke" || str == "rum & coke" || str == "rum") {
	mess = "A shock wave runs through your body";
	heal = 25;
        value = 250;
        strength = 14;
    } else if (str == "latte") {
	mess = "You feel somewhat invigorated";
	heal = 0;
	value = 50;
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
