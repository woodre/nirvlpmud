inherit "room/room";
object newspaper, top_list;

reset(arg) {
    if (arg) return;
    set_light( 1);
    if (!top_list || !present(top_list)) {
	top_list = clone_object("obj/level_list");
	move_object(top_list, this_object());
    }
    if (!newspaper || !present(newspaper)) {
	newspaper = clone_object("obj/newspaper");
	move_object(newspaper, this_object());
    }
  short_desc = "Blues Alley Pub";
  long_desc = "Welcome to The Blues Alley Pub !\n"+
	      "\n"+
              "Featuring Blues and Jazz Nightly !\n"+
              "\n"+
              "NO SPITTING, BRAWLING, OR CUSSING !!\n"+
              "\n"+
              "The bartender graciously accepts all tips..\n"+
              "\n"+
              "You can order drinks here...\n"+
                      "     Schlitz Bull          :  10 coins\n"+
              "     NoDoz                 :  20 coins\n"+
              "     Blues Man Special     : 180 coins\n"+
              "     Flaming Gibson        : 250 coins\n";
  dest_dir = 
  ({
      "players/morgoth/CASTLE/vil_road_1", "east",
      "players/morgoth/CASTLE/garden_path1", "south"
  });
}

init() {
  add_action("order", "order");
  add_action("order", "buy");
  ::init();
}

order(str)
{
    string name, short_desc, mess;
    int value, cost, strength, heal;

    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (str == "bull") {
	mess = "That feels good";
	heal = 1;
        value = 10;
	strength = 3;
    }
    else if (str == "special") {
	mess = "A tingling feeling goes through your body";
	heal = 10;
        value = 180;
        strength = 7;
    } else if (str == "gibson") {
	mess = "A shock wave runs through your body";
	heal = 25;
        value = 250;
        strength = 14;
    } else if (str == "nodoz") {
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

query_temp() { return 1; }
