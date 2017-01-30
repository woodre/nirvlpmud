object bouncer;

query_nosucko() { return 1; }
reset(arg) {
      if (!bouncer || !present(bouncer)) {
	bouncer = clone_object("players/grimm/monster/bruno");
	move_object(bouncer, this_object());
    }
    if (arg) return;
        set_light(100);
}

short() {
    return "ReesePort's Saloon";
}

init() {
    add_action("north","north");
    add_action("order","order");
    add_action("order","buy");
}


long() {
    write("You are in ReesePort's saloon.  Bubba sits behind the counter\n");
    write("all ready to serve you.  The drinks here are as follows:\n\n");
    write("     A cup of Java       :  25 coins\n");
    write("     -------------------------------\n");
    write("     Sea Water           :  10 coins\n");
    write("     Sailor's Delight    : 150 coins\n");
    write("     Sea Serpent         : 250 coins\n");
    write("     Death Salve         :1000 coins\n\n");

write("The only obvious exit is: north.\n");
}
north() {
  this_player()->move_player("north#players/grimm/town/mainstreet_3");
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
    if (str == "water" || str == "sea water") {
        mess = "That hits the spot";
	heal = 1;
	value = 10;
	strength = 3;
    }
    else if (str == "delight" || str == "sailor's delight") {
        mess = "You shiver with excitment";
	heal = 10;
	value = 150;
	strength = 8;
    } else if (str == "sea serpent" || str == "serpent") {
        mess = "The sea's mysteries sweep you away";
	heal = 25;
	value = 250;
	strength = 13;
    } else if (str == "java") {
	mess = "You feel somewhat invigorated";
	heal = 0;
	value = 25;
	strength = -2;
    } else if (str == "death" || str == "death salve" || str == "salve") {
  mess = "You are now so drunk that death would seem preferrable";
        heal = 100;
        value = 1000;
        strength = 20;
    } else {
    write("Bubba says: What the hell do you want? Order from the list...\n");
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
	    write("You order a " + str + ", try to drink it, and throw up.\n");
	} else {
	    say(call_other(this_player(), "query_name", 0) + " orders a " +
		str + ", and spews it all over you!\n");
	    write("You order a " + str + ", try to drink it, and sputter it all over the room!\n");
	}
	call_other(this_player(), "add_money", - value);
	return 1;
    }
    if (!call_other(this_player(), "drink_alcohol", strength)) {
   write("Bubba says: You be way to drunk for another drink.\n");
	say(call_other(this_player(), "query_name", 0) + " asks for a " +
         str + " but Bubba laughs in his face.\n");

	return 1;
    }
    write("You pay " + value + " coins for a " + str + ".\n");
    say(call_other(this_player(), "query_name", 0) + " orders a " + str + ".\n");
    call_other(this_player(), "add_money", - value);
    call_other(this_player(), "heal_self", heal);
    write(mess + ".\n");
    return 1;
}

query_nofight() { return 1; }
realm() { return "NK"; }
