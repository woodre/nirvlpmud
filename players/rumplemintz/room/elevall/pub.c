object newspaper, top_list;
object dartboard;
object band;

reset(arg) {
    if (!present("go player"))
        move_object(clone_object("obj/go_player"), this_object());
    if (!top_list || !present(top_list)) {
        top_list = clone_object("obj/level_list");
        move_object(top_list, this_object());
    }
    if(!dartboard || !present(dartboard)){
        dartboard=clone_object("players/rumplemintz/obj/dartboard");
        move_object(dartboard,this_object());
        }
/*
More: (line 17) 
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
    return "The Elevallie Pub";
}

init() {
    add_action("move");
    add_verb( "east");
    add_action("order");
    add_verb("order");
    add_action("order");
    add_verb("buy");
}

move() {
    object ob;

    call_other(this_player(), "move_player", "west#players/rumplemintz/room/elevall/room2");
        return 1;
}

long() {
    write("You are in the Elevallie Pub.\n");
    write("A rusted old sign here says:\n");
    write("WE RESERVE THE RIGHT TO CHANGE PRICES WITHOUT NOTICE\n\n");
    write("You can order drinks here.\n\n");
    write("     Corona Extra        :  10 coins\n");
    write("     Jaun Valdez special :  20 coins\n");
    write("     Shot of Rumplemintz : 150 coins\n");
    write("     Jungle Juice        : 230 coins\n\n");
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
    if (str == "corona") {
        mess = "Ya gotta love imported beer!";
        heal = 1;
        value = 10;
        strength = 3;
    }
    else if (str == "shot" || str == "shot of rumplemintz" ) {
        mess = "You slam it down with amazing speed, that was smooth!";
        heal = 8;
        value = 150;
        strength = 7;
    } else if (str == "jungle juice" || str == "juice") {
        mess = "Your body goes into convultions for a second";
        heal = 19;
        value = 230;
        strength = 12;
    } else if (str == "special" || str == "juan valdez special") {
        mess = "That woke you up a little...";
        heal = 0;
        value = 20;
        strength = -2;
    } else {
       write("The bartender says: Excuse me?\n");
       return 1;
    }
    if (call_other(this_player(), "query_money", 0) < value) {
        write("Why don't you go get " + value + " coins, then i'll give one to ya.\n");
        return 1;
    }
    cost = value;
    if (strength > (call_other(this_player(), "query_level") + 2)) {
        if (strength > (call_other(this_player(), "query_level") + 5)) {
            /* This drink is *much* too strong for the player */
            say(call_other(this_player(), "query_name", 0) + " orders a " +
                str + ", and throws up.\n");
            write("You try to drink a " + str + ", and spit it all over.\n");
        } else {
            say(call_other(this_player(), "query_name", 0) + " orders a " +
                str + ", and spews it all over you!\n");
            write("You order a " + str + ", try to drink it, and sputter it all over the room!\n");
        }
        call_other(this_player(), "add_money", - cost);
        return 1;
    }
    if (!call_other(this_player(), "drink_alcohol", strength)) {
        write("The bartender says: No more for you, ya drunkard!\n");
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
