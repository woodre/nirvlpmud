object newspaper, top_list;
object band;

reset(arg) {
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
  return "Pavlik's Bar and Grill";
}

init() {
    add_action("move","east");
    add_action("order","order"); 
    add_action("order","buy");
}

move() {
    object ob;

   this_player()->move_player("east#players/pavlik/castle/court.c");
    return 1;
}

long() {
  write("Welcome to Pav's Bar and Grill!\n");
  write("Come on it, have a seat and order up whatever you like\n"+
   "Pav's chef is one of the finest in the land and his brew\n"+
   "just can't be beat.  Pull up a chair in front of the big screen\n"+
   "Tv and relax for abit.\n");
    write("A large sign here says:\n");
    write("WE RESERVE THE RIGHT TO CHANGE UNDERWEAR WITHOUT NOTICE\n\n");
    write("You can order drinks here.\n\n");
    write("     Peddler's Beer    :  10 coins\n");
    write("     Cup of coffee       :  20 coins\n");
    write("     Homespun Special: 150 coins\n");
    write("     Baracudda        : 230 coins\n");
    write("     8 Ball            : 900 coins\n");
    write("     Bombadier         : 1440 coins\n");
    write("     The Morning After : 1500 coins\n");
   write("\n");
    write("The only obvious exit is east.\n");
}

order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "beer") {
	mess = "Not a bad brew!";
	heal = 1;
        value = 10;
	strength = 3;
    }
    else if (str == "special" || str == "special of the house") {
  mess = "You have never tasted a finer brew!\n";
	heal = 10;
        value = 150;
        strength = 7;
    } else if (str == "baracudda" || str == "bar") {
  mess = "Joe the bartender rushes over and helps you up off the floor";
	heal = 25;
        value = 230;
        strength = 14;
    } else if (str == "coffee" || str == "cup of coffee") {
	mess = "You feel somewhat invigorated";
	heal = 0;
	value = 20;
	strength = -2;
  }
 else if (str == "8 ball" || str == "ball") {
   mess = "Straight into the Corner Pocket!\n";
   call_other(this_player(), "add_spell_point", 50);
     value = 900;
    strength = 7;
 } else if (str == "bombadier") {
  mess = "Bombs Away!\n";
    heal = 40;
     value = 1440;
   strength = 7;
 } else if (str == "morning" || str == "the morning after" || str == "after") {
   mess = "You slam the drink and get slammed yourself!\n";
     heal = 49;
      value = 1500;
     strength = 7;
    } else {
  write("Joe the bartender says, 'Whatcha want bud?\n");
       return 1;
    }
    if (call_other(this_player(), "query_money", 0) < value) {
 write("Joe says 'Hold on there pal, you gotta have the funds\n"+
   "to support this boozing habit of yours!\n");
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
 write("Joe takes your car keys from you and sits you in the corner\n"+
    "'That's enough for you, big guy,' he says.\n");
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
