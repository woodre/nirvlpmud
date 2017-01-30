object man;

reset(arg) {
    if (!present("go player"))
	move_object(clone_object("obj/go_player"), this_object());
    if (!present("bartender")) {
    man = clone_object("players/bastion/obj/static");
    man->set_name("bartender");
    man->set_alias("man");
    man->set_short("Bartender");
    man->set_long("He looks at you suspiciously.\n" +
                  "Bartender is in good shape.\n");
    man->set_object(this_object());
    man->set_chat_chance(15);
    man->load_chat("The bartender begins wiping down the bar.\n");
    man->load_chat("Bartender says: If I were you, I'd take care around the\n"+
        "western part of Belgaers...\n");
    man->load_chat("The bartender rouses a sleeping patron.\n");
    move_object(man, this_object());
    man->start_check();
    }
    if (arg) return;
    set_light( 1);
}

short() {
    return "A Tavern";
}

init() {
    add_action("move", "west");
    add_action("order", "order");
    add_action("order", "buy");
}

move() {
    this_player()->move_player("west#players/bastion/antaria/citadel/road1");
    return 1;
}

long() {
  write(format("You are in a crowded tavern. The oaken panelling is stained "+
   "with the reminders of countless carousers. A bartender is here taking " +
   "care of his patrons drinking needs. Some courtesans are here also, " +
   "taking care of their other needs. A sign on the wall reads:\n\n",75));
    write(
          "    Draft beer        : 10 coins\n"+
          "    Cafe ole          :  20 coins\n"+
          "    Troll's sweat     :  180 coins\n"+
          "    Dragon's Breath   :  250 coins\n"+
          "    Potion of Heal    :  10000 coins\n"+
          "    Wakeup call       :  300 coins\n\n");
    write("The only obvious exit is west.\n");
}

order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;
    object drink;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "beer") {
	mess = "That feels good";
	heal = 1;
        value = 10;
	strength = 3;
    }
    else if (str == "troll's sweat" || str == "sweat") {
	mess = "A tingling feeling goes through your body";
	heal = 10;
        value = 180;
        strength = 7;
    } else if (str == "dragon's breath" || str == "breath") {
	mess = "A shock wave runs through your body";
	heal = 25;
        value = 250;
        strength = 14;
    } else if (str == "cafe ole" || str == "coffee") {
	mess = "You feel somewhat invigorated";
	heal = 0;
	value = 20;
	strength = -2;
    } else if(str=="wakeup call" || str=="wakeup" ||
              str=="potion of heal" || str=="potion") {
        if(str=="wakeup call" || str=="wakeup") {
            cost=300;
            drink=clone_object("players/bastion/obj/wakeup"); }
        else if(str=="potion of heal"||str=="potion") {
            drink=clone_object("players/bastion/obj/healpotion");
            cost=10000; }
        if((cost > this_player()->query_money())) {
             write("That costs " + cost + " coins, which you don't have.\n");
             destruct(drink);
             return 1; }
        if(!call_other(this_player(), "add_weight", 
           call_other(drink, "query_weight"))) {
            write("You can't carry any more.\n");
            destruct(drink);
            return 1; }
        this_player()->add_money(- cost);
        write("You pay " + cost + " coins for a " + str + ".\n");
        say(this_player()->query_name() + " buys a " + str + ".\n");
        move_object(drink, this_player());
        return 1;
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
