object top_list, board, band;
  string name;

reset(arg) {
 if(arg)  return;
    if (!top_list || !present(top_list)) {
	top_list = clone_object("obj/level_list");
	move_object(top_list, this_object());
    }
   if(!present("guild board", this_object())) {
  board = clone_object("players/hawkeye/closed/monk/sports_board");
  move_object(board, this_object());
      }
 set_light(1);
}

short() {
   return "The Monks Bar";
}

init() {
    name = this_player()->query_real_name();
if(find_player(name) && !present("mrobe", this_player())) {
       write("You're not a member!\n");
       move_object(this_player(), 
"players/hawkeye/closed/guild/join");
       return 1;
     }
    add_action("move");
    add_verb( "north");
    add_action("order");
    add_verb("order");
    add_action("order");
    add_verb("buy");
}

move() {
    object ob;
    call_other(this_player(), "move_player",  "north" + "#" +"players/hawkeye/closed/guild/mshop");
    return 1;
}

long() {
    write("You are in the Monk's Bar.\n");
    write("A large sign here says:\n");
    write("WE RESERVE THE RIGHT TO CHANGE PRICES WITHOUT NOTICE\n\n");
    write("You can order drinks here.\n\n");
    write("     A Glass of Kool Aid    :  10 coins\n");
    write("     Cup of coffee       :  20 coins\n");
    write("     Special of the house: 150 coins\n");
    write("     Firebreather        : 230 coins\n\n");
    write("The only obvious exit is north.\n");
}

order(str) {
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "kool aid") {
   mess = "Yuummmm, You are on a sugar high!";
	heal = 1;
        value = 10;
	strength = 3;
    }
    else if (str == "special" || str == "special of the house") {
	mess = "A tingling feeling goes through your body";
	heal = 10;
        value = 150;
        strength = 7;
    } else if (str == "firebreather" || str == "fire") {
	mess = "A shock wave runs through your body";
	heal = 25;
        value = 230;
        strength = 14;
    } else if (str == "coffee" || str == "cup of coffee") {
 mess = "You stroll over to the Mr. Coffee and help yourself\n"+
   "to a fresg warm cup of coffee";
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
