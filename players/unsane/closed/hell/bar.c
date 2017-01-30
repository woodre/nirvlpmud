#define tp = this_player()->query_name();

reset(arg) {
    if (arg) return;
    set_light( 1);
}

short() {
    return "The Demon's Pub";
}

init() {
    add_action("move","out");
    add_action("order","order");
    add_action("order","buy");
}

move() {
    object ob;

say(this_player()->query_name()+" teleports out of here.\n");
move_object(this_player(),"/players/unsane/closed/hell/circle1.c");
write("You think about leaving this place, and teleport away.\n");
command("look",this_player());
say(this_player()->query_name()+" arrives in a puff of brimstone.\n");
    return 1;
}

long() {
write("  You are in the favorite pub of the residents of Maleborgia.  It is smoky\n"+
"and reeks of brimstone here.  Luckily, there are no demons in the room\n"+
"right now, so you can breathe easier.\n");
write("\n");
    write("A large sign here says:\n");
write("WE RESERVE THE RIGHT TO EAT YOU WITHOUT NOTICE\n\n");
    write("You can order drinks here.\n\n");
    write("     Cup of animal blood  :  10 coins\n");
    write("     Sobering brew        :  20 coins\n");
    write("     Goblet of human blood: 150 coins\n");
    write("     Mug of child's blood : 230 coins\n\n");
    write("The only obvious exit is out.\n");
}

order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
if (str == "cup" || str == "animal blood") {
mess = "You let the animal blood run down your chin as you drink it";
	heal = 1;
        value = 10;
	strength = 3;
    }
    else if (str == "goblet" || str == "human blood") {
  mess = "You enjoy the goblet of human blood";
	heal = 10;
        value = 150;
        strength = 7;
    } else if (str == "mug" || str == "child's blood") {
mess = "You drink down the precious blood of children";
	heal = 25;
        value = 230;
        strength = 14;
    } else if (str == "brew" || str == "sobering brew") {
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
