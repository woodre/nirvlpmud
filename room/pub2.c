object newspaper, top_list;
object band;

reset(arg) {
    if (!present("go player"))
	move_object(clone_object("obj/go_player"), this_object());
    if (!top_list || !present(top_list)) {
	top_list = clone_object("obj/level_list");
	move_object(top_list, this_object());
    }
    if (!present("bartender"))
        move_object(clone_object("obj/bartender"), this_object());

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
    return "The local pub";
}

init() {
#ifndef __LDMUD__ /* Rumplemintz */
    add_action("move");
    add_verb( "west");
    add_action("order");
    add_verb("order");
    add_action("order");
    add_verb("buy");
#else
  add_action("move", "west");
  add_action("order", "order");
  add_action("order", "buy");
#endif
     add_action("look", "look");
     add_action("look", "l");
     add_action("look", "examine");
    add_action("look", "read");
}

move() {
    object ob;

    call_other(this_player(), "move_player",  "west" + "#" +"room/yard");
    return 1;
}

long() {
    write("You are in the local pub.\n");
    write("This old pub features paneled walls with wood tables and \n"+
     "chairs scattered about the place. There is a large wooden bar\n"+
     "where the barkeep usually is, serving drinks to all who order.\n"+
     "There are stools in front of the bar and a large mirror with\n"+
     "shelves full of booze behind it. There is a large sign behind\n"+
     "the bar with the drinks and prices written on it.\n");
    write("The only obvious exit is west.\n");
}
look(str) {
  if (!str) return 0;
  if (str=="at sign"||str=="at large sign"||str=="sign"||str=="large sign") {
      write("A large sign here says:\n");
    write("WE RESERVE THE RIGHT TO CHANGE PRICES WITHOUT NOTICE\n\n");
    write("You can order drinks here.\n\n");
    write("     First class beer    :  10 coins\n");
    write("     Cup of coffee       :  20 coins\n");
    write("     Special of the house: 150 coins\n");
    write("     Firebreather        : 230 coins\n\n");
  return 1;
  }
  if (str == "at tables" || str == "at table") {
     write("Old, crudely made wood tables are throughout the pub.\n");
     return 1;
  }
  if (str == "at chairs" || str == "at chair") {
     write("Simple factory made wood chairs of cheap construction.\n");
     return 1;
  }
  if (str == "at stool" || str == "at stools") {
     write("A simple wood-framed bar stool with a cusion held together\n"+
      "with clear packing tape.\n");
     return 1;
  }
  if (str == "at bar" || str == "wood bar") { 
    write("A worn, ornately carved bar.\n"); return 1;
  }
  if (str == "at shelf" || str == "at shelves" || str == "mirror") {
   if (present("bartender"))
    write("A series of glass shelves in front of the mirror hold the\n"+
    "booze that is served here.\n");
   else
    write("The glass shelves are knocked down and broken, the mirror\n"+
     "is cracked. The bottles once on the shelves lay broken on the floor.\n"); 
    return 1;
  }
  return 0;
}   
order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (!present("bartender")) {
       write("The bartender is gone and all the bottles appear to be \n"+
         "broken. Their contents spilled on the floor behind the bar.\n");
      return 1;
    }
    if (str == "beer") {
	mess = "That feels good";
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
    say("The bartender serves up the drink.\n");
    call_other(this_player(), "add_money", - cost);
    call_other(this_player(), "heal_self", heal);
    write("The bartender serves you your drink.\n");
    write(mess + ".\n");
    return 1;
}
