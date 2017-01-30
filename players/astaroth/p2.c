object newspaper, bar, top_list;
 
reset(arg) {
    if (!present("go player"))
        move_object(clone_object("obj/go_player"), this_object());
    if (!top_list || !present(top_list)) {
        top_list = clone_object("obj/level_list");
        move_object(top_list, this_object());
    }
    if (!newspaper || !present(newspaper)) {
        newspaper = clone_object("obj/newspaper");
        move_object(newspaper, this_object());
    }
    if (!present("bartender")) {
        bar = clone_object("obj/monster");
        bar->set_name("bartender");
        bar->set_short("Bartender");
        bar->set_long("The bartender seems to be serving someone.\n");
        bar->set_race("human");
        bar->set_level(5);
        bar->set_hps(150);
        bar->set_wc(12);
        bar->set_ac(5);
        move_object(bar, this_object());
        }
    if (arg) return;
    set_light( 1);
}
 
short() {
    return "The Horse and Groom pub";
}
 
init() {
    add_action("move");  add_verb("out");
    add_action("order");
    add_verb("order");
    add_action("order");
    add_verb("buy");
}
 
move() {
    object ob;
 
    call_other(this_player(), "move_player", "out"+"#"+"players/astaroth/pubfront");
    return 1;
}
long() {
    write("You are in the Horse and Groom pub.\n");
    write("You can order drinks here.\n\n");
    write("     Bitter ale          :  40 coins\n");
    write("     Bag of peanuts      :  25 coins\n");
    write("     Gin and tonic       : 150 coins\n");
    write("     The good stuff      : 230 coins\n\n");
    write("The only exit is: out\n");
}
 
order(str)
{
    string name, what, short_desc, mess;
    int value, cost, strength, heal;
 
    if (!str) {
       write("Order what ?\n");
       return 1;
    }
    if (present("bartender")) {
    if (str == "ale" || str == "bitter") {
        mess = "That feels good...  Another one seems like a good idea to you!";
        what = "pint of bitter ale";
        heal = 2;
        value = 40;
        strength = 4;
    }
    else if (str == "gin" || str == "gin and tonic") {
        mess = "That went down pretty smooth.  Why not have another?";
        what = "gin and tonic";
        heal = 10;
        value = 150;
        strength = 8;
    } else if (str == "good stuff" || str == "xxx") {
        mess = "Ahhhhh...  You get the idea that it would be unwise to breathe near a flame.";
        what = "shot of the good stuff";
        heal = 23;
        value = 230;
        strength = 12;
    } else if (str == "peanuts" || str == "bag of peanuts") {
        mess = "You feel less bombed, but somehow thirsty...";
        what = "bag of peanuts";
        heal = 0;
        value = 20;
        strength = -1;
    } else {
       write("The bartender says: Only what the sign says, buddy!\n");
       return 1;
    }
    if (call_other(this_player(), "query_money", 0) < value) {
        write("Are you some kind of deadbeat or just plain stupid?\n");
        write("That costs " + value + " gold coins, which you don't have.\n");
        return 1;
    }
    if (strength > (call_other(this_player(), "query_level") + 3)) {
        if (strength > (call_other(this_player(), "query_level") + 5)) {
            /* This drink is *much* too strong for the player */
            say(call_other(this_player(), "query_name", 0) + " orders a " +
                what + ", and passes out before even getting a sip down.\n");
            write("You order a " + what + ", try to drink it, and fall unconscious.\n");
        } else {
            say(call_other(this_player(), "query_name", 0) + " orders a " +
                what + ", and coughs it back up, and begins choking!\n");
            write("You order a " + what + ", try to drink it, and start choking on it!\n");
        }
        call_other(this_player(), "add_money", - value);
        return 1;
    }
    if (!call_other(this_player(), "drink_alcohol", strength)) {
        write("The bartender says: If you can't handle it, get out of my pub.\n");
        say(call_other(this_player(), "query_name", 0) + " asks for a " +
                what + " but the bartender tells him to get lost.\n");
 
        return 1;
    }
    write("You pay " + value + " coins for a " + what + ".\n");
    say(call_other(this_player(), "query_name", 0) + " orders a " + what + ".\n");
    call_other(this_player(), "add_money", - value);
    call_other(this_player(), "heal_self", heal);
    write(mess + ".\n");
    return 1;
} else {
    write("Somebody seems to have killed the bartender.\n");
    write("You will have to come back after we hire a new one.\n");
    return 1;
}
}
