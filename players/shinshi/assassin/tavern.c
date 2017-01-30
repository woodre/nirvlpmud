object newspaper, top_list;
object band, processor;
object sign;

reset(arg){
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
    return "The Vanilla Pub";
}

init() {
     if(!present("license", this_player())){
       write("You're not an assassin!\n");
       move_object(this_player(), "room/church");
     return 1;
      }
    add_action("west");
    add_verb("west");
    add_action("up");
    add_verb("up");
     add_action("ladder","ladder");
    add_action("read","read");
    add_action("order");
    add_verb("order");
    add_action("order");
    add_verb("buy");
}

read(str){
     if(str == "sign"){
     write("This guild is unique in that this tavern is YOURS to develop.\n");
     write("If you get any ideas about what you'd like to see in here, all\n");
     write("That you need to do is get the Grandfather to approve it and\n");
     write("have enough money in the treasury to undertake the project.\n");
     write("Right now, I am proposing the following:\n");
     write("For every 1000 coins deposited in the treasury, all drinks and\n");
     write("all guild commands requiring spell points will be reduced in cost\n");
     write("by one coin or spell point, respectively.\n");
     write("Other ideas I have seen are:\n");
     write("A poker table\n");
     write("A dart board\n");
     write("A practice monster\n");
     write("This is only limited by your creativity, my programming skill\n");
     write("and patience, and the cash in the treasury.\n");
     write("So if you get any ideas, feel free to post them on the board\n");
     write("or mail Shinshi.\n");
     return 1;
}
return 0;
}
west() {

    call_other(this_player(), "move_player",
     "west#players/shinshi/assassin/cenguild");
     return 1;
}

ladder(){
     call_other(this_player(), "move_player",
     "up the ladder#players/shinshi/assassin/catapult");
     return 1;
}
up() {

    call_other(this_player(), "move_player",
    "up#players/deathmonger/KMART/checkout");
    return 1;
}

long() {
     write("You enter The Assassin's Hideout tavern, a very seedy place.\n");
     write("Contracts are being made at the various tables for assassinations\n");
     write("This is your own tavern--try to make it the best it can be.\n");
    write("     Stab in the Back               8 coins\n");
    write("     Wakeup Call                    25 coins\n");
    write("     Mystery Killer                 165 coins\n");
    write("     Kiss of Death                  190 coins\n");
    write("There is a great black marble arch to the west.\n");
    write("There is a ladder leading upwards.\n");
    write("There are three obvious exits: up, west, and ladder.\n");
    write("There is a large sign here.\n");
}

order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "stab") {
mess = "It doesn`t taste real good, but it`ll get you buzzed";
	heal = 1;
        value = 8;
	strength = 3;
    }
   

    else if (str == "killer") {
mess = "You feel like you were hit by a bus.";
heal = 12;
        value = 165;
        strength = 5;
    } else if (str == "kiss") {
mess = "You feel like you were just smashed by a sledge hammer";
        heal = 22;
        value = 190;
        strength = 12;
    } else if (str == "wakeup" || str == "call") {
mess = "You start to shake from all the nervous energy you now have";
	heal = 0;
        value = 30;
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
